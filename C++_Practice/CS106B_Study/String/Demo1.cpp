//
// Created by hp on 2026/7/31.
//
#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string s = "Xian You";
    s.append("!");
    cout << s << endl; //Xian You!
    cout << s.compare("Xian You") << endl; //1
    cout << s.compare("Xian You!") << endl; //0
    cout << s.compare("Xian You!!") << endl; //-1
    s.erase(8, 1);
    cout << s << endl; //Xian You
    cout << "first index " << s.find("You") << " last index " << s.rfind("You") << endl; //5 7
    s.insert(8, "!");
    cout << s << endl; //Xian You!
    cout << "length: " << s.length() << endl; //9
    cout << "size: " << s.size() << endl; //9
    s.replace(8, 1, "!!!");
    cout << s << endl;
    cout << s.substr(5) << endl;
    cout << s.substr(5, 3) << endl;
    return 0;
}
