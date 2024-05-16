/**
 * Description:
 *  有一个n个数组成的数列, 第i个数记为ai. 你可以通过一次操作将某一个数增加1或是减少1.
 *  求出使数列满足如下条件所需的最小操作次数.
 *  	•	对所有的𝑖(1≤i≤n). 前i项的和0.
 *  	•	对所有的i (1≤i≤n−1). 前i项的和与前i+1项的和的符号相反.
 *
 * Input:
 *  第1行, 一个整数n, 代表项数.
 *  第2行, n个整数, 用空格分隔, 代表a1,a2,...,an
 *
 * Output:
 *  一个整数, 代表所需的最小操作次数.
 *
 * Hints:
 *  2≤n≤10<5>, |ai|≤10<9>且ai都是整数
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
1 -3 1 0
 *
 *  output:
4
 *
 *  2):
 *  input:
5
3 -6 5 -5 7
 *
 *  output:
0
 *
 */

#include <iostream>
using namespace std;
long long n, s1, s2, a[100010], c1, c2;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        s1 += a[i];
        if (i % 2 != 0 && s1 <= 0) {
            c1 += -s1 + 1;
            s1 = 1;
        }
        if (i % 2 == 0 && s1 >= 0) {
            c1 += s1 + 1;
            s1 = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        s2 += a[i];
        if (i % 2 == 0 && s2 <= 0) {
            c2 += -s2 + 1;
            s2 = 1;
        }
        if (i % 2 != 0 && s2 >= 0) {
            c2 += s2 + 1;
            s2 = -1;
        }
    }
    cout << min(c1, c2) << endl;
    return 0;
}