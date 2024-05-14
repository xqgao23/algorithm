/**
 * Description:
 *  一种新型的激光炸弹，可以摧毁一个边长为m的正方形内的所有目标。现在地图上有n个目标，用整数xi,yi表示目标在地图上的位置，每个目标都有一个价值vi.激光炸弹的投放是通过卫星定位的，但其有一个缺点，就是其爆破范围，即那个边长为m的边必须与x轴,y轴平行。若目标位于爆破正方形的边上，该目标不会被摧毁。
 *  现在你的任务是计算一颗炸弹最多能炸掉地图上总价值为多少的目标。
 *
 * Input:
 *  输入的第一行为整数n和整数m，
 *  接下来的n行，每行有3个整数xi,yi,vi表示一个目标的坐标与价值。
 *
 * Output:
 *  输出仅有一个正整数，表示一颗炸弹最多能炸掉地图上总价值为多少的目标（结果不会超过32767 ）。
 *
 * Hints:
 *  1≤n≤10<4>, 1≤m≤5000, 0≤xi,yi≤5000, 1≤vi≤100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 1
0 0 1
1 1 1
 *
 *  output:
1
 *
 */

#include <iostream>
using namespace std;
const int N = 5010;
int n, m, a[N][N], s[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        a[++x][++y] += v;
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = m; i <= 5001; i++) {
        for (int j = m; j <= 5001; j++) {
            ans = max(ans, s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
        }
    }
    cout << ans << endl;
    return 0;
}