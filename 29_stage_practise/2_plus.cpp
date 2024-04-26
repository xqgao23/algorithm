/**
 * Description:
 *  你有一个h行w列的图片，你要检查图中是不是恰有一个'+'.
 *  一个'+'这样定义:
 *  1.其中心非空;
 *  2.从中心出发，每个方向（上下左右）都有连续的至少一个非空格子;
 *  3.所有其他格子都是空的.
 *  输入包含多组数据
 *
 * Input:
 *  第1行，1个正整数T，表示有T组数据。
 *  接下来是T组数据，每组数据共h+1行:
 *  第1行,2个整数h,w,意义如题目描述.
 *  之后h行，给出了整个图片,'.'表示空,'*'表示非空
 *
 * Output:
 *  输出共T行，每行输出一个字符串表示一组数据的判断结果:
 *  如果恰有一个'+'就输出"YES",否则输出"NO"（均不带引号）.
 *
 * Hints:
 *  1≤T≤5；1≤h,w≤500
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
5 6
......
..*...
.****.
..*...
..*...
3 5
..*..
****.
.*...
 *
 *  output:
YES
NO
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int t, n, m, vis[510][510];
char g[510][510];

void f(int x, int y, int i)
{
    while (g[x][y] == '*') {
        vis[x][y] = 1;
        x += dx[i], y += dy[i];
    }
}

bool check()
{
    memset(vis, 0, sizeof vis);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '*' && g[i + 1][j] == '*' && g[i - 1][j] == '*' &&
                g[i][j - 1] == '*' && g[i][j + 1] == '*') {
                for (int k = 0; k <= 3; k++) {
                    f(i, j, k);
                }
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        return false; // 没有*
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '*' && !vis[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        if (check()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}