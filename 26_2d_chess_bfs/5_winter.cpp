/**
 * Description:
 *  传说在临冬城的地牢埋藏了三眼乌鸦的宝藏，为了打败异鬼，安雅决定寻找宝藏，但是地牢的结构过于复杂，安雅在地下迷路了。
 *  地牢是一个3D结构，由若干层组成，每一层都是有长宽相同的矩形组成。地牢被分成若干小格，当目标小格没有被岩石占据时，安雅可以前往当前小格前方、后方、左方、右方、上层、下层的小格，每走一小格花费一分钟时间。
 *  由于异鬼大军已经逼近，所以安雅必须在最短时间内拿到宝藏，请你帮助安雅确定是否能成功获得宝藏，如果可以，请求出所需的最短时间。
 *
 * Input:
 *  第一行输入L,R,C（L为地牢的层数，R为每层小格的行数，C为每层小格的列数，其中1<=L,R,C<=30）。
 *  第二行开始输入L层地牢的格局，每一层有R行，每行有C个小格，两层地牢中间有空行隔开。
 *  输入的文件中，"S"代表安雅现在的位置，"E"代表宝藏的位置，"#"为小格被岩石占据，"."表示此处为空地。
 *
 * Output:
 *  输出包含一行，当安雅可以顺利拿到宝藏时请输出：x代表你所花费的最短时间；
 *  否则请输出："Winter is Coming!"。
 *
 * Hints:
 *  N*M≤16384，1<=N,M≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E
 *
 *  output:
11
 *
 *  2):
 *  input:
1 3 3
S##
#E#
###
 *
 *  output:
Winter is Coming!
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};
int L, R, C, dis[40][40][40], sx, sy, sz, ex, ey, ez;
char g[40][40][40];

struct node {
    int x, y, z;
};

int bfs(int a, int b, int c)
{
    queue<node> q;
    memset(dis, -1, sizeof dis);
    node tt = {a, b, c};
    q.push(tt);
    dis[a][b][c] = 0;
    while (q.size()) {
        node t = q.front();
        q.pop();
        if (t.x == ex && t.y == ey && t.z == ez) {
            return dis[ex][ey][ez];
        }
        for (int i = 0; i <= 5; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i], nz = t.z + dz[i];
            if (nx < 1 || nx > L || ny < 1 || ny > R || nz < 1 || nz > C ||
                dis[nx][ny][nz] != -1 || g[nx][ny][nz] == '#') {
                continue;
            }
            node tm = {nx, ny, nz};
            q.push(tm);
            dis[nx][ny][nz] = dis[t.x][t.y][t.z] + 1;
        }
    }

    return -1;
}

int main()
{
    cin >> L >> R >> C;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= R; j++) {
            for (int k = 1; k <= C; k++) {
                cin >> g[i][j][k];
                if (g[i][j][k] == 'S') {
                    sx = i, sy = j, sz = k;
                }
                if (g[i][j][k] == 'E') {
                    ex = i, ey = j, ez = k;
                }
            }
        }
    }
    int ans = bfs(sx, sy, sz);
    if (ans == -1) {
        cout << "Winter is Coming!" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}