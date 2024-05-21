/**
 * Description:
 *  皮皮的暑假作业太过繁重，为了劳逸结合，妈妈同意皮皮可以去家附近的景区游玩一天。
 *  景区共有n个景点，景点两两之间有m条路径连接。皮皮可以让妈妈开车到任意景点开始游玩，也可以到任意景点结束游玩，但是妈妈为了防止皮皮故意拖延时间，不允许皮皮去前往相同的地点一次以上。而皮皮为了得到最好的休息，希望选择最长的路程游玩。
 *
 * Input:
 *  第一行，两个用空格隔开的正整数n,m。之后m行，每行三个整数a,b,c表示一条观景道的两个端点编号和长度。
 *
 * Output:
 *  一个整数，表示皮皮选择的最长的路程的长度。
 *
 * Hints:
 *  n≤20,m≤50，保证景点两两之间不会有多条路径连接，答案在int范围内。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 6
1 2 10
2 3 20
3 4 30
4 1 40
1 3 50
2 4 60
 *
 *  output:
150
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int n, m, g[25][25], ans, cnt, vis[25];

void dfs(int x, int d)
{
    vis[x] = 1;
    cnt = max(cnt, d);
    for (int i = 1; i <= n; i++) {
        if (g[x][i] != g[0][0] && !vis[i]) {
            dfs(i, d + g[x][i]);
        }
    }
    vis[x] = 0;
}

int main()
{
    cin >> n >> m;
    memset(g, -0x3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        memset(vis, 0, sizeof vis);
        dfs(i, 0);
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}