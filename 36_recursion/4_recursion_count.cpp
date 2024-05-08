/**
 * Description:
 *  考虑所有n位正整数, 如果要求数码6不能紧跟在数码5后面, 那么满足要求的数有多少个?
 *
 * Input:
 *  一个整数n
 *
 * Output:
 *  输出个数
 *
 * Hints:
 *  1≤n≤18
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
 *
 *  output:
881
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL a[50], b[50];
// a[n]表示以5结尾的n位数个数
// b[n]表示不以5结尾的n位数个数

int main()
{
    int n;
    cin >> n;
    a[1] = 1;
    b[1] = 8;
    for (int i = 2; i <= n; i++) {
        a[i] = b[i - 1] + a[i - 1];
        b[i] = (a[i - 1] + b[i - 1]) * 8 + b[i - 1];
    }
    cout << a[n] + b[n] << endl;
    return 0;
}