// Practical9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void printPrefix(vector<string> prefixArr) {
    cout << "\n";
    for (int i = 0; i < (int)prefixArr.size(); i++) {
        cout << prefixArr[i] + " ";
    }
}

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

string prefixToInfix(string prefix) {
    vector<string> prefixArr = splitBySpace(prefix);
    int number;
    string infix = "";
    stack<int> myStack;
    bool first = true;
    int size = (int)prefixArr.size() - 1;
    for (int i = size; i >= 0; i--) {
        string val = prefixArr[i];
        // cout << val + " ";
        
        if (isOpperator(val)) {
            //string val1 = ;
            //string val2 = 
            if (myStack.size() < 2) {
                return "Error";
            }
            int num1 = myStack.top();
            myStack.pop();
            int num2 = myStack.top();
            myStack.pop();

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
            else {
                return "Error";
            }
            if (first) {
                infix += "("+to_string(num1) + " " + val + " " + to_string(num2)+")";
                first = false;
            }
            else if (myStack.size() == 0) {
                infix = "" + infix + " " + val + " " + to_string(num2) + "";
            }
            else {
                infix = "(" +infix +" " + val + " " + to_string(num2) + ")";
            }
            
            myStack.push(number);
        }
        else {
            myStack.push(stoi(val));
        }
    }
    if (myStack.size()>1) {
        return "Error";
    }
    infix += " = " + to_string(myStack.top());
    return infix;
    /*
    while (i < ((int)prefixArr.size()) && prefixArr.size() != 1) {

        if (prefixArr.size() == 2) {
           return "Error";
        }
        string val1 = prefixArr[i];
        string val2 = prefixArr[i + 1];
        string val3 = prefixArr[i + 2];
        if (!isOpperator(val2) && isOpperator(val3)) {
            count = 0;
        }
        if (isOpperator(val1) && !isOpperator(val2) && !isOpperator(val3)) {
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
            else {
                return "Error";
            }
            if (firstRunThrough) {

                infix += "(" + val2 + " " + val1 + " " + val3 + ")";
                
            }
            else {
                if (prefixArr.size() == 3) {
                    infix += " " + val1 + " " + val3;
                }
                else {
                    infix = "(" + infix + " " + val1 + " " + val3 + ")";
                }
            }
            prefixArr.erase(prefixArr.begin() + i, (prefixArr.begin() + i + 3));
            prefixArr.insert(prefixArr.begin() + i, to_string(number));
            printPrefix(prefixArr);
            i = prefixArr.size() - 3;
            row++;
            count++;
        }
        else {
            //count = 0;
            row = 0;
        }
        i--;
        if (prefixArr.size() == 1) {
            infix += " = " + prefixArr[0];
            return infix;
        }
        if (i < 0) {
            i = prefixArr.size() - 3;
            firstRunThrough = false;
        }
    }
    */
    
    
}

void test(string prefix, string expected) {
    string infix = prefixToInfix(prefix);
    std::cout << "\nTest "<< prefix << ": \n";
    if (infix == expected) {
        std::cout << "\t - Passed!";
    }
    else {
        std::cout << "\t - Failed - should be \n\t" << expected << " \n\tbut is \n\t" + infix;
    }
}

int main()
{
    bool testMode = false;
    if(testMode){
        test("* 5", "Error");
        test("* 5 6 7", "Error");
        test("* - 5 6 7", "(5 - 6) * 7 = -7");
        test("- * + 2 3 4 5", "((2 + 3) * 4) - 5 = 15");
        test("* + 1 2 + 3 4", "(1 + 2) * (3 + 4) = 21");
    }
    else {
        string prefix;
        //string prefix = "* - 5 6 7";
        getline(std::cin, prefix);
        string infix = prefixToInfix(prefix);
        std::cout << infix;
    }

    
    
    
    return 0;
    
}
