/**
 * Description:
 *  现在是晚餐时间，而母牛们在外面分散的牧场中。
 *  Farmer John 按响了电铃，所以她们开始向谷仓走去。 你的工作是要指出哪只母牛会最先到达谷仓（在给出的测试数据中，总会有且只有一只最快的母牛）。在挤奶的时候（晚餐前），每只母牛都在她自己的牧场上，一些牧场上可能没有母牛。
 *  每个牧场由一条条道路和一个或多个牧场连接（可能包括自己）。有时，两个牧场（可能是字母相同的）之间会有超过一条道路相连。至少有一个牧场和谷仓之间有道路连接。因此，所有的母牛最后都能到达谷仓，并且母牛总是走最短的路径。当然，母牛能向着任意一方向前进，并且她们以相同的速度前进。牧场被标记为a,b,c,...,z和A,B,C,...,Y，在用大写字母表示的牧场中有一只母牛，小写字母中则没有。 谷仓的标记是Z，注意没有母牛在谷仓中。
 *  注意m和M不是同一个牧场。
 *
 * Input:
 *  第一行一个整数P(1≤P≤10<4>)，表示连接牧场（谷仓）的道路的数目
 *  接下来P行，每行两个字母和一个正整数，表示道路连接的牧场的编号和道路的长度（道路的长度不超过10<3>)
 *
 * Output:
 *  单独的一行包含二个项目：最先到达谷仓的母牛所在的牧场的标号，和这只母牛走过的路径的长度。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
 *
 *  output:
B 11
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int m, g[60][60], ans = 1e9, dis[60], id;
int vis[60];

int f(char c)
{
    if (islower(c)) {
        return c - 'a' + 1;
    }
    return c - 'A' + 27;
}

void dfs(int x, int d)
{
    if (dis[x] <= d) {
        return;
    }
    vis[x] = 1;
    dis[x] = min(dis[x], d);
    for (int i = 1; i < 52; i++) {
        if (g[x][i] != g[0][0] && !vis[i]) {
            dfs(i, d + g[x][i]);
        }
    }
    vis[x] = 0;
}

int main()
{
    cin >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        u = f(u);
        v = f(v);
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    memset(dis, 0x3f, sizeof dis);
    dfs(52, 0);
    for (char i = 27; i < 52; i++) {
        if (dis[i] < ans) {
            ans = dis[i];
            id = i;
        }
    }
    cout << char(id + 'A' - 27) << " " << ans << endl;
    return 0;
}