/*
                    -------------------
                    | Problem Solving |
                    -------------------
Write A program to Calculate the score for baseball sport.

Example:
Input : ["0","1","2","3","D","5","+","10","C"]
Output : 28
*/

#include <iostream>
#include <vector>
#include <string>
int calc_score(std::vector<std::string> &ops)
{
    for (int i = 0; i < ops.size(); i++)
    {
        if(ops[i] == "C")
        {
            ops.erase(ops.begin()+(i));
            ops.erase(ops.begin()+(i-1));
        }
        else if(ops[i] == "D")
        {
            ops[i] = std::to_string(std::stoi(ops[i-1]) * 2);
        }
        else if(ops[i] == "+")
        {
            ops[i] = std::to_string(std::stoi(ops[i-1]) + std::stoi(ops[i-2]));
        }
        else
        {
            ops[i] = ops[i];
        }
    }

    int result = std::stoi(ops[1]);
    if (ops.size() > 1)
    {
        result = 0;
        for (int index = 0; index < ops.size(); index++)
        {
            result = result + std::stoi(ops[index]);
        }
    }
    return result;
}

int main(void)
{
    std::vector<std::string> ops = {"0","1","2","3","D","5","+","10","C"};
    int result = calc_score(ops);
    std::cout << result << std::endl;
    return 0;
}