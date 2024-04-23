/**
 * Description:
 *  由于手上（更确实的，蹄子上）有大把的空余时间，Farmer
 * John的农场里的奶牛经常玩电子游戏消磨时光。她们最爱的游戏之一是基于一款人类中流行的电子游戏Puyo
 * Puyo的奶牛版；名称当然叫做Mooyo Mooyo。 Mooyo
 * Mooyo是在一块细长的棋盘上进行的游戏，高N（1≤N≤100）格，宽10格。
 * 这是一个N=6的棋盘的例子： 0000000000 0000000300 0054000300 1054502230
 *  2211122220
 *  1111111223
 *  每个格子中或者是空的（用0表示），或者是九种颜色之一的干草捆（用字符1..9表示）。重力会使得干草捆下落，所以没有干草捆的下方是0。
 *  如果两个格子水平或垂直方向直接相邻，并且为同一种非0颜色，那么这两个格子就属于同一个连通区域。任意时刻出现至少K个格子构成的连通区域，其中的干草捆就会全部消失，变为0。如果同时出现多个这样的连通区域，它们同时消失。随后，重力可能会导致干草捆向下落入某个变为0的格子。由此形成的新的布局中，又可能出现至少K个格子构成的连通区域。若如此，它们同样也会消失（如果又有多个这样的区域，则同时消失），然后重力又会使得剩下的方块下落，这一过程持续进行，直到不存在大小至少为K的连通区域为止。
 *  给定一块Mooyo Mooyo棋盘的状态，输出这些过程发生之后最终的棋盘的图案。
 *
 * Input:
 *  输入的第一行包含N和K（1≤K≤10N）。
 *  以下N行，每行10个字符，给出了棋盘的初始状态。
 *
 * Output:
 *  N行，描述最终的棋盘状态
 *
 * Hints:
 *  n≤1000，m≤100000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223
 *
 *  output:
0000000000
0000000000
0000000000
0000000000
1054000000
2254500000
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, k, vis[110][20], cnt, ans[2010];
char g[110][20];

void dfs(int x, int y)
{
    vis[x][y] = cnt;
    ans[cnt]++;
    for (int i = 0; i <= 3; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > 10 || g[nx][ny] != g[x][y] ||
            vis[nx][ny]) {
            continue;
        }
        dfs(nx, ny);
    }
}

bool check()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            if (g[i][j] != '0' && !vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            if (ans[vis[i][j]] >= k) {
                g[i][j] = '0';
                ok = 0;
            }
        }
    }
    return ok;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> g[i][j];
        }
    }
    while (true) {
        cnt = 0;
        memset(vis, 0, sizeof vis);
        memset(ans, 0, sizeof ans);
        if (check()) {
            break;
        }
        for (int j = 1; j <= 10; j++) {
            for (int i = n, x = n; i >= 1; i--) {
                if (g[i][j] != '0') {
                    swap(g[i][j], g[x--][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}