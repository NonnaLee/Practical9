// Practical9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitBySpace(string text) {
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    words.push_back(text);
    return words;
}

bool isOpperator(string str) {
    if (str == "*" || str == "/" || str == "+" || str == "-") {
        return true;
    }
    return false;
}

int main()
{
    string prefix;
    //string prefix = "* - 5 6 7";
    //cin >> prefix;
    getline(std::cin, prefix);
    vector<string> prefixArr = splitBySpace(prefix);
    int number;
    string infix = "";
    int i = 0;
    int row = 0;
    while (i < ((int)prefixArr.size()) && prefixArr.size() != 1) {

        if (prefixArr.size() == 2) {
            std::cout << "Error";
            return 0;
        }
        string val1 = prefixArr[i];
        string val2 = prefixArr[i+1];
        string val3 = prefixArr[i+2];

        if (!isOpperator(val2) && !isOpperator(val3)) {
            float num1 = stoi(val2);
            float num2 = stoi(val3);
            if (prefixArr[i] == "*") {
                number = num1 * num2;
            }
            else if (prefixArr[i] == "/") {
                number = num1 / num2;
            }
            else if (prefixArr[i] == "+") {
                number = num1 + num2;
            }
            else if (prefixArr[i] == "-") {
                number = num1 - num2;
            }
            if (row > 0) {
                infix += " " + val1 + " " + val3;
            }
            else {
                infix += "(" + val2 + " " + val1 + " " + val3 + ")";
            }
            prefixArr.erase(prefixArr.begin()+ i, (prefixArr.begin() + i + 3));
            prefixArr.insert(prefixArr.begin() + i,to_string(number));
            i = 0;
            row++;
        }
        else {
            row = 0;
            i++;
        }
    }

    infix += " = " + prefixArr[i];
    std::cout << infix;
    return 0;
    
}
