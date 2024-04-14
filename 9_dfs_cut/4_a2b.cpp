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
 *  第2行，一个整数k,意义与第3行一起解释.
 *  第3行，用空格隔开的k个正整数a1,a2,..,ak，表示把a变成b的过程，其中a=a1,
 * b=ak,过程中ai会变成ai+1 如果有多种变形路线，输出优先使用第1种变换的路线
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
5
2 4 8 81 162
 *
 */

#include <iostream>
using namespace std;
int a, b, p[40];
bool flag = false;

void dfs(int step, int x)
{
    if (flag) {
        return;
    }
    if (x > b) {
        return;
    }
    if (x == b) {
        flag = true;
        cout << "YES" << endl;
        cout << step << endl;
        for (int i = 0; i <= step - 1; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        return;
    }
    p[step] = 2 * x;
    dfs(step + 1, 2 * x);
    p[step] = 10 * x + 1;
    dfs(step + 1, 10 * x + 1);
}

int main()
{
    cin >> a >> b;
    p[0] = a;
    dfs(1, a);
    if (!flag) {
        cout << "NO" << endl;
    }
    return 0;
}