/**
 * Description:
 *  爱与愁大神坐在公交车上无聊，于是玩起了手机。一款奇怪的游戏进入了爱与愁大神的眼帘：***（游戏名被打上了马赛克）。这个游戏类似象棋，但是只有黑白马各一匹，在点(x1,y1)和(x2,y2)上。它们得从点(x1,y1)和(x2,y2)走到(1,1)。这个游戏与普通象棋不同的地方是：马可以走"日"，也可以像象走"田"。现在爱与愁大神想知道两匹马到(1,1)的最少步数，你能帮他解决这个问题么？
 *
 * Input:
 *  第1行：两个整数x1,y1
 *  第2行：两个整数x2,y2
 *
 * Output:
 *  第1行：黑马到1,1的步数
 *  第2行：白马到1,1的步数
 *
 * Hints:
 *  x1,y1,x2,y2≤20
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
12 16
18 10
 *
 *  output:
8
9
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2, 2, 2, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1, 2, -2, 2, -2};
int x1, y1, x2, y2, dis[30][30];

struct node {
    int x, y;
};

int bfs(int a, int b)
{
    queue<node> q;
    memset(dis, -1, sizeof dis);
    node tt = {a, b};
    q.push(tt);
    dis[a][b] = 0;
    while (q.size()) {
        node t = q.front();
        q.pop();
        if (t.x == 1 && t.y == 1) {
            return dis[1][1];
        }
        for (int i = 0; i <= 11; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (nx < 1 || nx > 20 || ny < 1 || ny > 20 || dis[nx][ny] != -1) {
                continue;
            }
            node tm = {nx, ny};
            q.push(tm);
            dis[nx][ny] = dis[t.x][t.y] + 1;
        }
    }
    return -1;
}
int main()
{
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1, y1) << endl;
    cout << bfs(x2, y2) << endl;
    return 0;
}