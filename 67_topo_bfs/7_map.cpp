/**
 * Description:
 *  “图上漫步”是一款在木板上进行的游戏，木板上有一个无向完全图，图中任意两个点之间都有一条直接相连的边，并且每个点都有一条自环边，因此N个点的图有共(N+1)×N/2条边。每条边都有特定的颜色。游戏中有三颗棋子，游戏开始时，每颗棋子分别放在给定的点上。玩家需要依次移动棋子，每次移动只要沿着无向图的边从当前点移到新的点。但是，只有当边的颜色与另外两颗棋子相连的边颜色一样时，棋子才能移动。
 *  事实上，“图上漫步”也有单人版，在这款游戏中，一个人要移动三颗棋子，不需要依次移动，但每次只能移动一颗棋子，游戏的任务是：用最少的步数，将所有的棋子移动到同一个位置上。
 *  请你根据图的布局及棋子的开始位置，计算出把所有的棋子移动到同一个位置上的最少步数。
 *
 * Input:
 *  输入有多组数据。
 *  对于每组数据，第一个数据是n。当n=0时表示输入结束。然后是三个整数p1,p2,p3（1≤pi≤n），表示棋子的初始位置。
 *  接下来n行为n×n的矩阵，表示每条边的颜色，都是字母（字母之间用空格隔开）。矩阵元素mij表示点i和j之间的边的颜色。因为游戏图是无向的，你可以认为矩阵是对称的。
 *
 * Output:
 *  对于每组数据，输出一行，表示把所有棋子移动到同一个位置上的最少步数，如果无法实现目标，输出"impossible"。
 *
 * Hints:
 *  1≤N≤50
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 1 2 3
r b r
b b b
r b r
2 1 2 2
y g
g y
0
 *
 *  output:
2
impossible
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 55;
struct node {
    int a, b, c;
};
int n, p1, p2, p3, vis[N][N][N], dis[N][N][N];
char g[N][N];

void bfs()
{
    queue<node> q;
    memset(dis, -1, sizeof dis);
    node tt = {p1, p2, p3};
    q.push(tt);
    dis[p1][p2][p3] = 0;
    while (q.size()) {
        node t = q.front();
        q.pop();
        if (t.a == t.b && t.b == t.c) {
            cout << dis[t.a][t.b][t.c] << endl;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (g[t.a][i] == g[t.b][t.c] && dis[i][t.b][t.c] == -1) {
                node t1 = {i, t.b, t.c};
                q.push(t1);
                dis[i][t.b][t.c] = dis[t.a][t.b][t.c] + 1;
            }
            if (g[t.b][i] == g[t.a][t.c] && dis[t.a][i][t.c] == -1) {
                node t1 = {t.a, i, t.c};
                q.push(t1);
                dis[t.a][i][t.c] = dis[t.a][t.b][t.c] + 1;
            }
            if (g[t.c][i] == g[t.a][t.b] && dis[t.a][t.b][i] == -1) {
                node t1 = {t.a, t.b, i};
                q.push(t1);
                dis[t.a][t.b][i] = dis[t.a][t.b][t.c] + 1;
            }
        }
    }
    cout << "impossible" << endl;
}

int main()
{
    while (cin >> n, n) {
        cin >> p1 >> p2 >> p3;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> g[i][j];
            }
        }
        bfs();
    }
    return 0;
}