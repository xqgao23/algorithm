/**
 * Description:
 *  在每一位均为A或B的长度为n的字符串中，不存在AAB的有多少个？
 *
 * Input:
 *  一个整数n
 *
 * Output:
 *  输出个数
 *
 * Hints:
 *  3≤n≤30
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
 *
 *  output:
12
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int a[50], b[50], c[50], d[50];
// a[n]表示长为n的以AA结尾的字符串个数
// b[n]表示长为n的以AB结尾的字符串个数
// c[n]表示长为n的以BA结尾的字符串个数
// d[n]表示长为n的以BB结尾的字符串个数

int main()
{
    int n;
    cin >> n;
    a[2] = 1;
    b[2] = 1;
    c[2] = 1;
    d[2] = 1;
    for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + c[i - 1];
        b[i] = c[i - 1];
        c[i] = b[i - 1] + d[i - 1];
        d[i] = b[i - 1] + d[i - 1];
    }
    cout << a[n] + b[n] + c[n] + d[n] << endl;
    return 0;
}