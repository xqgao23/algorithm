/**
 * Description:
 *  有一部长篇漫画一共有 10<9> 卷，它们的标题编号为 1∼10<9> 卷。小明打算从第 1 卷开始看。
 *  初始小明有 n 本书，第 i 本书是这部长篇漫画的第 ai 卷。（他可能持有很多同一卷漫画）
 *  小明在开始看漫画前，可以进行以下操作任意次：
 *  	•	选择目前持有的两本书卖掉，购买一本任意标题漫画。
 *  然后，小明会按照标题编号 1,2,3,⋯ 卷的顺序一直读下去。直到读不到下一卷为止，即小明读完第i卷后，发现自己未持有第i+1卷，此时即使小明还持有其他卷漫画，也只能停止阅读。
 *  问小明最多可以读多少卷漫画？
 *
 * Input:
 *  第1行，1个正整数n。
 *  第2行，n个正整数a1,a2,...,an.
 *
 * Output:
 *  输出小明最多可以读多少卷漫画。如果连第1卷都读不到，输出0
 *
 * Hints:
 *  1≤n≤3*10<5>,1≤ai≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
1 2 4 6 7 271
 *
 *  output:
4
 *
 *  2):
 *  input:
10
1 1 1 1 1 1 1 1 1 1
 *
 *  output:
5
 *
 *  3):
 *  input:
1
5
 *
 *  output:
0
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, a[300010], b[300010], m, c, ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            c++;
        } else {
            b[++m] = a[i];
        }
    }
    int x = 0, p = 1;
    while (p <= m) {
        if (x + 1 == b[p]) {
            x++, p++;
        } else {
            if (c >= 2) {
                x++, c -= 2;
            } else if (c >= 1 && p <= m) {
                x++, c--, m--;
            } else if (p < m) {
                x++, m -= 2;
            } else {
                break;
            }
        }
    }
    cout << x + c / 2 << endl;
    return 0;
}