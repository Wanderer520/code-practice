//
// Created by hp on 2026/8/14.
//
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<string> v1 = {"Hello", "World", "!"};
    vector<string> v2 = {"C++", "is", "awesome"};
    vector<string> v3 = {"Let's", "learn", "vectors"};
    vector<vector<string>> vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    for (int i = 0 ;i<vv.size();i++)
    {
        for (int j = 0 ; j<vv[i].size();j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
