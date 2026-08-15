//
// Created by hp on 2026/8/14.
//
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream input;
    input.open("poem.txt");
    while (!input.fail())
    {
        // 检查并跳过 UTF-8 BOM（EF BB BF）
        char c1 = input.get();
        char c2 = input.get();
        char c3 = input.get();
        if (!(c1 == '\xEF' && c2 == '\xBB' && c3 == '\xBF'))
        {
            // 不是 BOM，回到文件开头
            input.seekg(0);
        }
        string line;
        getline(input, line);

        cout << line << endl;

        input.close();
    }
    return 0;
}
