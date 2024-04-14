/**
 * Description:
 *  房间里放着n块奶酪。一只小老鼠要把它们都吃掉，问至少要跑多少距离？老鼠一开始在(0,0)点处。
 *
 * Input:
 *  第一行一个数n (n<=12)
 *  接下来每行2个实数，表示第i块奶酪的坐标。
 *  两点之间的距离公式 d = sqrt((x1-x2)<2> + (y1-y2)<2>)
 *
 * Output:
 *  一个数，表示要跑的最少距离，四舍五入保留2位小数。
 *
 * Hints:
 *  1≤n<=8;1<=xi<=10<7>
 */

/**
 *  Samples:
 *  1):
 *  input:
4
1 1
1 -1
-1 1
-1 -1
 *
 *  output:
7.41
 *
 */

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, p[20], vis[20];
double x[20], y[20], ans = 1e9;

double get_dis(int a, int b)
{
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

void dfs(int step, double x)
{
    if (x > ans) {
        return;
    }
    if (step > n) {
        ans = min(ans, x);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            p[step] = i;
            vis[i] = 1;
            dfs(step + 1, x + get_dis(i, p[step - 1]));
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    dfs(1, 0);
    printf("%.2lf\n", ans);
    return 0;
}