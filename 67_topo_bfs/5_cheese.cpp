/**
 * Description:
 *  现有一块大奶酪，它的高度为 h，它的长度和宽度我们可以认为是无限大的，奶酪中间有许多 半径相同的球形空洞。我们可以在这块奶酪中建立空间坐标系，在坐标系中，奶酪的下表面为z=0，奶酪的上表面为z=h。
 *  现在，奶酪的下表面有一只小老鼠 Jerry，它知道奶酪中所有空洞的球心所在的坐标。如果两个空洞相切或是相交，则 Jerry 可以从其中一个空洞跑到另一个空洞，特别地，如果一个空洞与下表面相切或是相交，Jerry 则可以从奶酪下表面跑进空洞；如果一个空洞与上表面相切或是相交，Jerry 则可以从空洞跑到奶酪上表面。
 *  位于奶酪下表面的 Jerry 想知道，在 不破坏奶酪 的情况下，能否利用已有的空洞跑到奶酪的上表面去?
 *  空间内两点(P1(x1,y1,z1), P2(x2,y2,z2)的距离公式如下：
 *  dist(P1, P2) = sqrt((x1-x2)<2> + (y1 -y2)<2> + (z1-z2)<2>)
 *
 * Input:
 *  每个输入文件包含多组数据。
 *  第一行，包含一个正整数 T，代表该输入文件中所含的数据组数。
 *  接下来是 T 组数据，每组数据的格式如下： 第一行包含三个正整数 n,h 和 r，两个数之间以一个空格分开，分别代表奶酪中空洞的数量，奶酪的高度和空洞的半径。
 *  接下来的 n 行，每行包含三个整数 x,y,z，两个数之间以一个空格分开，表示空洞球心坐标为(x,y,z)。
 *
 * Output:
 *  T 行，分别对应 T 组数据的答案，如果在第 i 组数据中，Jerry 能从下 表面跑到上表面，则输出`Yes`，如果不能，则输出`No` （均不包含引号）。
 *
 * Hints:
 *  1≤n<1000, 1≤h,r≤1000000000, T≤20, 坐标的绝对值不超过1000000000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
2 4 1
0 0 1
0 0 3
2 5 1
0 0 1
0 0 4
2 5 2
0 0 2
2 0 4
 *
 *  output:
Yes
No
Yes
 *
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std; const int N = 1010;
int t, n, h, r, x[N], y[N], z[N], g[N][N], vis[N], ok;

double sq(double x)
{
    return x * x;
}

double dis(int a, int b)
{
    return sqrt(sq(x[a] - x[b]) + sq(y[a] - y[b]) + sq(z[a] - z[b]));
}

void dfs(int x)
{
    if (vis[x] || ok) {
        return;
    }
    if (z[x] + r >= h) {
        ok = 1;
        return;
    }
    vis[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (g[x][i]) {
            dfs(i);
        }
    }
}

int main()
{
    cin >> t;
    while (t--) {
        memset(g, 0, sizeof g);
        memset(vis, 0, sizeof vis);
        ok = 0;
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i] >> z[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis(i, j) <= 2 * r) {
                    g[i][j] = g[j][i] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (z[i] <= r) {
                dfs(i);
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}