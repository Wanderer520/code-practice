//
// Created by hp on 2026/8/1.
//
#include <iostream>
#include <string>
using namespace std;

void nameIdamond(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.substr(0, i + 1) << endl;
    }
    for (int i = 1; i < s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << s.substr(i, s.length()) << endl;
    }
}

int main()
{
    string name = "MARTY";
    nameIdamond(name);
    return 0;
}
