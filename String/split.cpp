/*************************************************************************
	> File Name: split.cpp
	> Author: Shawn Yan
	> Mail: yanxjun1990@gmail.com 
	> Created Time: Wed 15 Jun 2016 10:04:01 AM CST
 ************************************************************************/

#include<iostream>
#include <string>
#include <vector>
using namespace std;

//如果是char* 可以使用strtok来实现


//如果是string则使用STL中的string的find和substr来实现
//字符串分割函数,单个字符
vector<string> split_one(string str,string pattern){
    string::size_type pos;
    vector<string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

//单个或者多个字符的（主要使用）
vector<string> split(string str,string pattern){
    vector<string> result ; //Use vector to add the words

    size_t prev_pos = 0, pos;
    while ((pos = str.find_first_of(pattern, prev_pos)) != string::npos){
        cout << prev_pos << "-" << pos << endl;
        if (pos > prev_pos)//大于可以省略多个字符的情况
            result.push_back(str.substr(prev_pos, pos-prev_pos));
        prev_pos= pos+1;
    }

    if (prev_pos< str.length())
        result.push_back(str.substr(prev_pos));
    return result;
}

int main(){
    string str;
    /*
    cout<<"Please input str:"<<endl;
    getline(cin,str);
    string pattern;
    cout<<"Please input pattern:"<<endl;
    getline(cin,pattern);//用于获取含空格的字符串
    vector<string> result=split(str,pattern);
    */
    vector<string> result = split("fsa$# sdfs$sdfs# sdfsf#","# $");
    cout<<"The result:"<<endl;
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
