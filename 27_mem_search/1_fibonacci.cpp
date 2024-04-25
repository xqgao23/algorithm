/**
 * Description:
 *  斐波那契数列是一个特殊的数列:1,1,2,3,5,8,13,21,34,55,⋯
 *  数列的第一项和第二项都是1, 从第三项开始, 每一项是其前面两项之和。
 *  输入正整数n, 编程输出该数列的第n项。
 *
 * Input:
 *  一个整数n
 *
 * Output:
 *  一个整数, 斐波那契数列的第n项
 *
 * Hints:
 *  1≤n≤50
 *
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
 *  2):
 *  input:
45
 *
 *  output:
1134903170
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
long long n, f[60];

long long fac(int n)
{
    if (f[n] != -1) {
        return f[n];
    }
    if (n == 1 || n == 2) {
        return f[n] = 1;
    }
    return f[n] = fac(n - 1) + fac(n - 2);
}

int main()
{
    cin >> n;
    memset(f, -1, sizeof f);
    cout << fac(n) << endl;
    return 0;
}