/**
 * Description:
 *  Michael喜欢滑雪。这并不奇怪，因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道在一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：
 *  1 2 3 4 5
 *  16 17 18 19 6
 *  15 24 25 20 7
 *  14 23 22 21 8
 *  13 12 11 10 9
 *  一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可行的滑坡为24－17－16－1（从24开始，在1结束）。当然25－24－23－⋯－3－2－1
 * 更长。事实上，这是最长的一条。
 *
 * Input:
 *  输入的第一行为表示区域的二维数组的行数R和列数C（1 <= R，C <=
 * 100）。下面是R行，每行有C个数，代表高度(两个数字之间用1个空格间隔)。
 *
 * Output:
 *  输出区域中最长滑坡的长度。
 *
 * Hints:
 *  1≤Q≤5*10<5>, 1≤x,y,A,B≤2000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
 *
 *  output:
25
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int r, c, g[110][110], ans, f[110][110];

int dfs(int x, int y)
{
    if (f[x][y] != -1) {
        return f[x][y];
    }
    int cnt = 1;
    for (int i = 0; i <= 3; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > r || yy < 1 || yy > c || g[xx][yy] >= g[x][y]) {
            continue;
        }
        cnt = max(cnt, dfs(xx, yy) + 1);
    }
    return f[x][y] = cnt;
}

int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> g[i][j];
        }
    }
    memset(f, -1, sizeof f);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}