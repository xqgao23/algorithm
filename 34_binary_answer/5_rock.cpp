/**
 * Description:
 *  一年一度的"跳石头"比赛又要开始了!
 *  这项比赛将在一条笔直的河道中进行，河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。在起点和终点之间，有 N 块岩石（不含起点和终点的岩石）。在比赛过程中，选手们将从起点出发，每一步跳向相邻的岩石，直至到达终点。
 *  为了提高比赛难度，组委会计划移走一些岩石，使得选手们在比赛过程中的最短跳跃距离尽可能长。由于预算限制，组委会至多从起点和终点之间移走 M 块岩石（不能移走起点和终点的岩石）。
 *
 * Input:
 *  第一行包含三个整数 L,N,M，分别表示起点到终点的距离，起点和终点之间的岩石数，以及组委会至多移走的岩石数。保证 L≥1 且 N≥M≥0。
 *  接下来 N 行，每行一个整数，第 i 行的整数 Di(0<Di<L)， 表示第 i 块岩石与起点的距离。这些岩石按与起点距离从小到大的顺序给出，且不会有两个岩石出现在同一个位置。
 *
 * Output:
 *  一个整数，即最短跳跃距离的最大值。
 *
 * Hints:
 *  0≤M≤N≤50000, 1≤L≤1000000000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
25 5 2
2
11
14
17
21
 *
 *  output:
4
 *
 */

#include <iostream>
using namespace std;
int L, n, m, d[50010];

bool check(int mid)
{
    int pos = 0, cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (d[i] - pos < mid) {
            cnt++;
        } else {
            pos = d[i];
        }
    }
    return cnt <= m;
}

int main()
{
    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    d[n + 1] = L;
    int l = 1, r = 1e9, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}