/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Magdalena Sobrino-Almanzar
 */

#include<iostream>
#include<vector>

std::vector<std::string> values = {"zero", "one", "two",
        "three", "four", "five", "six", "seven", "eight", "nine"};


int read_number()
{
        const int out_of_range = values.size();
        int val = out_of_range;
        // Try to read an integer composed of digits
        if (std::cin >> val) {
                return val;
        }
        // To use cin again after a failed read, we need to use cin clear//
        std::cin.clear();        
        std::string spelled = " ";
        std::cin >> spelled;
        for (int i = 0; i < values.size(); ++i) {
                if (values[i] == spelled) {
                        val = i;
                }
        }
        return val;
}

int main()
{
        std::cout << "Enter two numbers separated by an operator(spelled out or digits).\n"
                << "The operator can be + - * / % : ";

        while (true) {        
                              
                int value1 = read_number();
                char operation = 0;
                std::cin >> operation;
                int value2 = read_number();
                std::string oper = " ";
                double result = 0;
                
                switch (operation) {
                case '+':
                        oper = "Sum of ";
                        result = value1+value2;
                        break;
                case '-':
                        oper = "Difference between ";
                        result = value1-value2;
                        break;
                case '*':
                        oper = "Product of ";
                        result = value1*value2;
                        break;
                case '/':
                        oper = "Ratio of ";
                        if (value2==0) {
                                std::cout << "Impossible:"
                                        << " trying to divide by zero... ";
                        }
                        else {
                                result = value1/value2;
                        }
                        break;
                case '%':
                        oper = "Remainder of ";
                        if (value2==0) {
                                std::cout << "Impossible:"
                                        << " trying to divide by zero... ";
                        }
                        else {
                                result = value1%value2;
                        }
                        break;
                default:
                        std::cout << "Bad operator... ";
                }
                std::cout << oper << value1 << " and " << value2
                        << " is " << result << '\n';
                std::cout << "Try another operation: ";
        }
}