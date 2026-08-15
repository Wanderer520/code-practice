//
// Created by hp on 2026/8/1.
//
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = string("hi") + "there";
    cout << s1 << endl;
    string s2 = string("hi") + '?';
    cout << s2 << endl;
    string s3 = "hi" + to_string(41);
    cout << s3 << endl;

    return 0;
}
