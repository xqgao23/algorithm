/**
 * Description:
 *  写一个递归函数 int cmb(int n, int m), 递归求组合数C<m, n>
 *
 * Input:
 *  两个整数n，m
 *
 * Output:
 *  一个整数, 组合数C<m,n>的值
 *
 * Hints:
 *  1<=m <= n <=32
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
 *
 *  output:
10
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
// 在此定义函数
int cmb(int n, int m)
{
    if (m == 0 || n == m) {
        return 1;
    }
    return cmb(n - 1, m) + cmb(n - 1, m - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << cmb(n, m) << endl;
    return 0;
}