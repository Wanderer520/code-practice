//
// Created by hp on 2026/8/14.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream input;
    input.open("poem.txt");
    // 检查并跳过 UTF-8 BOM（EF BB BF）
    char c1 = input.get();
    char c2 = input.get();
    char c3 = input.get();
    if (!(c1 == '\xEF' && c2 == '\xBB' && c3 == '\xBF'))
    {
        // 不是 BOM，回到文件开头
        input.seekg(0);
    }
    vector<string> allWords;
    string token;
    while (input >> token)
    {
        cout << token << endl;
        allWords.push_back(token);
    }
    for (const auto &word : allWords)
    {
        cout << word << " ";
    }
    return 0;
}
