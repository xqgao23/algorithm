/**
 * Description:
 *  高桥最近正在练习射击。 他参加了一个射击比赛，比赛内容是射击气球。
 *  共有n个气球，编号1∼n。每个气球都有一个起始高度hi，比赛开始后，每个气球的高度每秒会升高si。 高桥开始时可以先打掉一个气球，随后每一秒他可以射击一次，打掉一个气球，直到打掉所有的气球。每个气球的分数为当他打掉气球时，这个气球的高度。而最终的得分就是所有气球分数的最大值。
 *  高桥想知道他的最终得分最小可能是多少。
 *
 * Input:
 *  第一行为气球的个数n
 *  接下来n行，每行两个整数hi和si，表示气球的初始高度和气球的升高速度。
 *
 * Output:
 *  输出一个数，表示高桥能拿到的最小分数
 *
 * Hints:
 *  1≤n≤10<5>, 1≤hi≤10<9>,1≤si≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
5 6
12 4
14 7
21 2
 *
 *  output:
23
 *
 *  2):
 *  input:
6
100 1
100 1
100 1
100 1
100 1
1 30
 *
 *  output:
105
 *
 *  3):
 *  input:
9
1 999999999
2 999999999
3 999999999
4 999999999
5 999999999
6 999999999
7 999999999
8 999999999
9 999999999
 *
 *  output:
7999999993
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, h[100010], s[100010];
long long t[100010];

bool check(long long mid)
{
    for (int i = 1; i <= n; i++) {
        if (mid < h[i]) {
            return false;
        }
        t[i] = (mid - h[i]) / s[i];
    }
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= n; i++) {
        if (t[i] < i - 1) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> s[i];
    }
    long long l = 1, r = 1e15, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}