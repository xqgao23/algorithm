/**
 * Description:
 *  你正在散步的时候，突然出现了一只魔物! 幸好你随身携带了N把刀,
 * 你可以进行以下两种攻击: 1.挥舞目前持有的一把刀, 挥舞刀i会对魔物造成ai点伤害
 *  2.将目前持有的一把刀扔出去, 扔出刀i会对魔物造成bi点伤害.
 * 但是扔出去的刀之后就不能挥舞了. 魔物受到H点或更多伤害就会消灭.
 * 求出消灭魔物所需要的最小攻击次数.
 *
 * Input:
 *  第一行, 2个正整数N,H, 表示刀的数量和魔物的耐久值
 *  接下来N行, 每行两个正整数ai,bi, 表示刀i的挥舞和投掷伤害
 *
 * Output:
 *  输出消灭魔物所需的最小攻击次数
 *
 * Hints:
 *  1<=N<=10<5>, 1<=H<=10<9>, 1<=ai<=bi<=10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
1 10
3 5
 *
 *  output:
3
 *
 *  2):
 *  input:
4 1000000000
1 1
1 10000000
1 30000000
1 99999999
 *
 *  output:
860000004
 *
 *  3):
 *  input:
5 500
35 44
28 83
46 62
31 79
40 43
 *
 *  output:
9
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n, h, k, ans;
struct node {
    int x, h;
} t[200010];

bool cmp(node x, node y) { return x.h > y.h; }

int main()
{
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        t[++k].x = 0, t[k].h = a;
        t[++k].x = 1, t[k].h = b;
    }
    sort(t + 1, t + k + 1, cmp);
    for (int i = 1; i <= k; i++) {
        if (t[i].x == 1) {
            ans++;
            h -= t[i].h;
            if (h <= 0) {
                break;
            }
        } else {
            ans += (h + t[i].h - 1) / t[i].h;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}