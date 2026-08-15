//
// Created by hp on 2026/8/13.
//
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream input;
    input.open("poem.txt");
    if (input.fail())
        cout << "Failed to open the file." << endl;
    else
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
        while (getline(input, line))
        {
            cout << line << endl;
        }
        input.close();
    }
    return 0;
}
