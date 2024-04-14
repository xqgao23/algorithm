/**
 * Description:
 *  瓦西里有一个数a,他想把这个数变成b，为此他可以做两种变换.
 *  1.把现有的数x变为2x;
 *  2.把现有的数x后面接一个1(即x变为10x+1).
 *  例如a=2,b=162,你可以以如下的方式把a变成b
 *  2 -> 4 -> 8 -> 81 -> 162
 *  你需要帮瓦西里判断一下，把a变成b是否可能。
 *
 * Input:
 *  两个整数a,b,意义如题目描述.
 *
 * Output:
 *  一个字符串，如果变形是可能的，就输出"YES"否则输出"NO"（均不带引号）
 *
 * Hints:
 *  1<=a,b<=10<9>
 */

/**
 *  Samples:
 *  1):
 *  input:
2 162
 *
 *  output:
YES
 *
 */

#include <iostream>
using namespace std;
int a, b;

bool dfs(int x)
{
    if (x > b) {
        return false;
    }
    if (x == b) {
        return true;
    }
    return dfs(2 * x) || dfs(x * 10 + 1);
}

int main()
{
    cin >> a >> b;
    bool flag = dfs(a);
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}