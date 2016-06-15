/*************************************************************************
	> File Name: string2other.cpp
	> Author: Shawn Yan
	> Mail: yanxjun1990@gmail.com 
	> Created Time: Wed 15 Jun 2016 11:20:48 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1 = "1234567890";
    string str2 = "123.456";
    //C++ 11
    int num1 = stoi(str1);
    long num2 = stol(str1);
    float num3 = stof(str2);
    double num4 = stod(str2);
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << num4 << endl;
    return 0;
}
