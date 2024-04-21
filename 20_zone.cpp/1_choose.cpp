/**
 * Description:
 *  周末有n门选修课, 小猴要在n门选修课中选择尽可能多的课程
 *  已知每门课程的开始时间和结束时间, 不能选时间段上有重复的课程.
 *
 * Input:
 *  第一行是一个整数n (1≤n≤1000)
 *  接下来n行，每行是2个整数ai,bi(0≤ai<bi≤10<9>)，表示每门课程开始、结束的时间。
 *
 * Output:
 *  一个整数, 小猴能选的最大课程数量
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
0 2
2 4
1 3
 *
 *  output:
2
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n;
struct node {
    int a, b;
} p[1010];

bool cmp(node x, node y) { return x.b < y.b; }

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
    }

    sort(p + 1, p + n + 1, cmp);

    int lastb = -1e9, ans = 0;

    for (int i = 1; i <= n; i++) {
        if (p[i].a >= lastb) {
            ans++;
            lastb = p[i].b;
        }
    }

    cout << ans << endl;

    return 0;
}