/**
 * Description:
 *  你有若干个区间，表示为[ai, bi]，其中ai,bi为整数。
 *  要求选若干个点，使得每个区间中有至少一个点（不同的区间允许公用一个点），求最少需要的点数。
 *
 * Input:
 *  输入共n+1行：
 *  第1行，2个用空格隔开的整数n,k，表示区间个数为n，区间一定不会超出[1,k]范围；
 *  之后n行，每行2个整数ai,bi表示一个区间[ai,bi]
 *
 * Output:
 *  1个整数，为所求的最少点数。
 *
 * Hints:
 *  1<=n<=200000, 1<=k<=40000
 */

/**
 *  Samples:
 *  1):
 *  input:
6 10
1 2
2 3
5 6
3 4
4 5
6 7
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, k;
struct node {
    int a, b;
} p[200010];

bool cmp(node x, node y) { return x.b < y.b; }

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
    }

    sort(p + 1, p + n + 1, cmp);

    int lastb = -1e9, ans = 0;

    for (int i = 1; i <= n; i++) {
        if (p[i].a > lastb) {
            ans++;
            lastb = p[i].b;
        }
    }

    cout << ans << endl;

    return 0;
}