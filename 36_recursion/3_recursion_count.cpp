/**
 * Description:
 *  用1,2,3组成n位数，要求1和1不能相邻，问这样的n位数有多少个
 *
 * Input:
 *  一个整数n
 *
 * Output:
 *  输出个数
 *
 * Hints:
 *  1≤n≤20
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
 *
 *  output:
22
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int a[50], b[50], c[50];
// a[n]表示以1结尾的数的n位数的个数
// b[n]表示以2结尾的数的n位数的个数
// c[n]表示以3结尾的数的n位数的个数

int main()
{
    int n;
    cin >> n;
    a[1] = 1;
    b[1] = 1;
    c[1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = b[i - 1] + c[i - 1];
        b[i] = a[i - 1] + b[i - 1] + c[i - 1];
        c[i] = a[i - 1] + b[i - 1] + c[i - 1];
    }
    cout << a[n] + b[n] + c[n] << endl;
    return 0;
}