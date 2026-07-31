//
// Created by hp on 2026/7/31.
//
#include <cmath>
#include <iostream>
using namespace std;

void quadratic(int a, int b, int c, double& root1, double& root2)
{
    double d = sqrt(b * b - 4 * a * c);
    root1 = (-b + d) / (2 * a);
    root2 = (-b - d) / (2 * a);
}

int main()
{
    //测试二次函数求根
    double root1, root2;
    quadratic(1, -3, -4, root1, root2);
    cout << "The roots are " << root1 << " and " << root2 << endl;
    return 0;
}
