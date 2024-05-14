/**
 * Description:
 *  小明要用录像机录N个电视节目。 一共有C个电视频道，从1到C编号。
 *  第i个电视节目从时刻si开始，时刻ti结束，在频道ci播出。(包含开始时刻si，不包含结束时刻ti)
 *  同一个频道不会同时播出多个节目。
 *  如果某个录像机在时刻S到时刻T录像某个频道的节目，如果接下来想用它录像其他频道的节目，需要将这个录像机接到另一个频道上，操作时间为D，所以最早必须等到T+D时刻才能开始录制其他频道的节目。
 *  若要录下全部N个节目，至少需要多少台录像机？
 *
 * Input:
 *  第一行两个正整数N,C,D，代表节目数和频道数和换频道需要的操作时间
 *  接下来N行，每行三个正整数si,ti,ci, 代表第i个节目的开始结束时间和播出频道。
 *
 * Output:
 *  输出需要的最少录像机台数
 *
 * Hints:
 *  1≤N≤10<5>, 1≤ci≤C≤10<5>, 0≤D≤10<6>,  1≤si≤ti≤10<6>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 4 1
1 7 2
7 8 1
8 12 1
8 12 3
 *
 *  output:
2
 *
 *  2):
 *  input:
5 4 7
1 3 1
9 11 1
10 12 4
10 14 2
18 20 3
 *
 *  output:
3
 *
 *  3):
 *  input:
9 4 30
56 60 4
33 37 2
89 90 3
32 43 1
67 68 3
49 51 3
31 32 3
70 71 1
11 12 3
 *
 *  output:
4
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int N, C, D, d[2000010], ans;
struct node {
    int s, t, c;
} p[100010];

bool cmp(node x, node y)
{
    if (x.c != y.c) {
        return x.c < y.c;
    }
    return x.s < y.s;
}

int main()
{
    cin >> N >> C >> D;
    for (int i = 1; i <= N; i++) {
        cin >> p[i].s >> p[i].t >> p[i].c;
        p[i].t += D;
    }
    sort(p + 1, p + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
        if (p[i].c == p[i + 1].c && p[i].t > p[i + 1].s) {
            p[i + 1].s = p[i].s;
        } else {
            d[p[i].s]++, d[p[i].t]--;
        }
    }
    for (int i = 1; i <= 2e6; i++) {
        d[i] += d[i - 1];
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}