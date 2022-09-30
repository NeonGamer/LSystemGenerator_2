#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
using namespace std;

#pragma region Variable Declerations
int iterations;
map<char, string> rules; //Map is the saming thing as a C# Dictionary
#pragma endregion

string ApplyRules(string ss){
    stringstream newS; //Same Thing As a StringBuilder In C#
    for (auto &ch : ss) //Foreach Char In String
    {
        newS << rules[ch]; //Write The Return Of The Map To The String Buidler
    }
    return newS.str(); //Convert StringStream To String
}

int main(){
    #pragma region Init Rules
    rules['F'] = "F-G";
    rules['G'] = "F+G";
    rules['-'] = "-";
    rules['+'] = "+";
    #pragma endregion
    
    //Setting
    cin >> iterations; //Console Takes In An Input From The User TO Decide How Many Iterations
    string ss = "F"; //Set The Starting String To The Axiom

    #pragma region Generating Instructions
    for (size_t i = 0; i < iterations; i++)
    {
        ss = ApplyRules(ss);
    }
    #pragma endregion
    #pragma region Write Final Interation To File
    ofstream outputLog; //New File Stream
    outputLog.open("[Output File Location]"); //Open File to stream 
    outputLog << ss; //Write To FIle
    outputLog.close(); //Close File Stream
    #pragma endregion

    return 0;
}
