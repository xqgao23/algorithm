/**
 * Description:
 *  有一个数列a1,a2,…,an。可以对它进行如下操作：
 *  每次操作，选择数列的一个子序列（也可以是数列本身），将子序列中的数都改成它们的平均数。
 *  例如数列[5,1,2,1]，选择第1个数和第3个数，它们的平均数是3.5，所以操作后数列就会变成[3.5,1,3.5,1]
 *  给出数列a1,a2,…,an和一个整数x，我们想要通过若干次操作，让尽可能多的数大于等于x。问最多可以使多少个数大于x？（操作的次数没有上限，也可以一次都不操作）
 *
 * Input:
 *  输入包含多组数据。
 *  第1行，1个正整数T，表示有T组数据。
 *  每组数据由两行组成：
 *  第1行，包含两个整数n,x；
 *  第2行，包含n个整数a1,a2,...,an
 *
 * Output:
 *  输出T行，对每组数据输出答案。
 *
 * Hints:
 *  1≤T≤1000, 1≤n≤10<5>, 1≤x≤10<9>, 1≤ai≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
4 3
5 1 2 1
4 10
11 9 11 9
2 5
4 3
3 7
9 4 9
 *
 *  output:
2
4
0
3
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int t, n, x, a[100010];

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1, greater<int>());
        long long s = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            s += a[i];
            if (s < 1ll * x * i) {
                break;
            }
            ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}