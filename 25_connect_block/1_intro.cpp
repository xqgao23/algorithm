/**
 * Description:
 *  不是任何人都可以进入桃花岛的，黄药师最讨厌象郭靖一样呆头呆脑的人。所以，他在桃花岛的唯一入口处修了一条小路，这条小路全部用正方形瓷砖铺设而成。有的瓷砖可以踩，我们认为是安全的，而有的瓷砖一踩上去就会有喷出要命的毒气，那你就死翘翘了，我们认为是不安全的。你只能从一块安全的瓷砖上走到与他相邻的四块瓷砖中的任何一个上，但它也必须是安全的才行。
 *  由于你是黄蓉的朋友，她事先告诉你哪些砖是安全的、哪些砖是不安全的，并且她会指引你飞到第一块砖上（第一块砖可能在任意安全位置），现在她告诉你进入桃花岛的秘密就是：如果你能走过最多的瓷砖并且没有死，那么桃花岛的大门就会自动打开了，你就可以从当前位置直接飞进大门了。
 *  注意：瓷砖可以重复走过，但不能重复计数。
 *
 * Input:
 *  第一行两个正整数 W 和 H，分别表示小路的宽度和长度。
 *  以下 H 行为一个 H×W 的字符矩阵。每一个字符代表一块瓷砖。其中，'.'代表安全的砖，'#'代表不安全的砖，'@'代表第一块砖。
 *
 * Output:
 *  输出一行，只包括一个数，即你从第一块砖开始所能安全走过的最多的砖块个数（包括第一块砖）。
 *
 * Hints:
 *  1≤W,H≤20。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
 *
 *  output:
59
 *
 */

// 未使用方向偏移数组
#include <iostream>
using namespace std;

int w, h, cnt, sx, sy, vis[30][30];
char g[30][30];

void dfs(int x, int y)
{
    vis[x][y] = 1;
    cnt++;
    if (x + 1 <= h && g[x + 1][y] != '#' && vis[x + 1][y] == 0) {
        dfs(x + 1, y);
    }
    if (x - 1 >= 1 && g[x - 1][y] != '#' && vis[x - 1][y] == 0) {
        dfs(x - 1, y);
    }
    if (y + 1 <= w && g[x][y + 1] != '#' && vis[x][y + 1] == 0) {
        dfs(x, y + 1);
    }
    if (y - 1 >= 1 && g[x][y - 1] != '#' && vis[x][y - 1] == 0) {
        dfs(x, y - 1);
    }
}

int main()
{
    cin >> w >> h;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> g[i][j];
            if (g[i][j] == '@') {
                sx = i, sy = j;
            }
        }
    }
    dfs(sx, sy);
    cout << cnt << endl;
    return 0;
}