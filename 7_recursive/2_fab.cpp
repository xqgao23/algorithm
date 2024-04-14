/**
 * Description:
 *  写一个递归函数 int fab(int k), 递归求斐波那契数列第k项
 *  规定斐波那契数列第1项和第2项为1.
 *
 * Input:
 *  1个正整数k
 *
 * Output:
 *  一个正整数, 斐波那契数列第k项
 *
 * Hints:
 *  1<=k<=40
 */

/**
 *  Samples:
 *  1):
 *  input:
4
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
// 在此定义函数
int fab(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }
    return fab(n - 1) + fab(n - 2);
}

int main()
{
    int k;
    cin >> k;
    cout << fab(k) << endl;
    return 0;
}