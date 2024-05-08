/**
 * Description:
 *  上体育课的时候，老师要求同学们4人一组练习传球。
 *  假设有ABCD四个人在练习传球, 一开始球在A处. 每次传球时, 控球的人将球传给除自己以外的任意一个人. 问传球n次后, 球又回到A处的传球路线有多少种?
 *
 * Input:
 *  一个整数n
 *
 * Output:
 *  输出个数
 *
 * Hints:
 *  2≤n≤40
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
 *
 *  output:
6
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n;
long long a[50], b[50], c[50], d[50];

int main()
{
    cin >> n;
    a[0] = 1;
    b[0] = 0;
    c[0] = 0;
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = b[i - 1] + c[i - 1] + d[i - 1];
        b[i] = a[i - 1] + c[i - 1] + d[i - 1];
        c[i] = a[i - 1] + b[i - 1] + d[i - 1];
        d[i] = a[i - 1] + b[i - 1] + c[i - 1];
    }
    cout << a[n] << endl;
    return 0;
}