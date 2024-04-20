/**
 * Description:
 *  有 N 张卡片，第 i 张卡上写着整数 Ai
 *  你接下来将要进行 M 次操作：
 *  第 j 次操作有两个参数 Bj 和 Cj，表示这次操作你要
 *  选择最多Bj张卡片（可以选0张），将选出卡片上的整数改成Cj。
 *  M次操作结束后，N张卡片上的整数之和的最大值是多少？
 *
 * Input:
 *  第1行，2个正整数N,M
 *  第2行，N个正整数A1,,A2,…AN接下来M行，每行两个正整数Bj,Cj
 *
 * Output:
 *  输出M次操作后所有卡片上整数总和的最大值
 *
 * Hints:
 *  1<=N<=10<5>, 1<=M<=10<5>, 1<=Ai,Cj<=10<9>, 1<=Bj<=N
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 2
5 1 4
2 3
1 5
 *
 *  output:
14
 *
 *  2):
 *  input:
10 3
1 8 5 7 100 4 52 33 13 5
3 10
4 30
1 4
 *
 *  output:
338
 *
 *  3):
 *  input:
11 3
1 1 1 1 1 1 1 1 1 1 1
3 1000000000
4 1000000000
3 1000000000
 *
 *  output:
10000000001
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int b, c;
} t[100010];

int a[100010], n, m;
long long ans;

bool cmp(node x, node y) { return x.c > y.c; }

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i].b >> t[i].c;
    }
    sort(a + 1, a + n + 1);
    sort(t + 1, t + m + 1, cmp);
    for (int i = 1, j = 1; i <= n && j <= m; i++) {
        if (t[j].c <= a[i]) {
            break;
        }
        if (t[j].b-- > 0) {
            a[i] = t[j].c;
        }
        if (!t[j].b) {
            j++;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}