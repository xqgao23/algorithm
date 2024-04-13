/**
 * Description:
 *  一个城市里面有m个基站，每个基站能覆盖距离自己不超过r的一个范围（注意这是一个圆形的范围）
 *  问坐标范围在1≤x≤n 和1≤y≤n范围内的n<2>个整数坐标的点(x,y)中, 有多少个点能被覆盖到.
 *  如果坐标为(x,y)的点和位于坐标(s0,t0)的基站之间满足:
 *  (x - s0)<2> + (y - t0)<2> <= r<2>
 *  则这个点可以被位于(s0, t0)的基站覆盖到
 *
 * Input:
 *  第一行3个正整数n,m,r接下来m行，每行两个整数s0,t0,依次表示每个基站的坐标.
 *
 * Output:
 *  一个整数，能被覆盖到的点的个数.
 *
 * Hints:
 *  1<=n,m<=100, 0<=r<=100 |s0|,|t0| <= 10<9>
 */

/**
 *  Samples:
 *  1):
 *  input:
5 2 1
3 3
4 2
 *
 *  output:
8
 *
 */

#include <iostream>
using namespace std;
int n, m, r, s[110], t[110], flag[110][110];
int main()
{
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if ((i - s[k]) * (i - s[k]) + (j - t[k]) * (j - t[k]) <=
                    r * r) {
                    flag[i][j] = 1;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (flag[i][j]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}