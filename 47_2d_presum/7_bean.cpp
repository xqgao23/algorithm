/**
 * Description:
 *  现在有一个n×m的棋盘，左下角的格子为(1,1)，右上角格子为(n,m)，每个棋盘格子可以放任意数量的豆子。
 *  小明有k次操作，对于每次操作给出四个数字x1,y1,x2,y2，表示小明会将所有(x,y)满足x1≤x≤x2, y1≤y≤y2格子放上一个豆子。
 *  在小明完成k次操作后，他将对你进行q次询问。
 *  每次询问给出四个数x1,y1,x2,y2，问所有(x1,y1)满足x1≤x≤x2,y1≤y≤y2的格子上的豆子的总数和为多少？
 *
 * Input:
 *  第一行四个整数n,m,k,q，表示棋盘大小为n×m，有k次操作和q次询问。
 *  接下来k行，每行四个整数x1,y1,x2,y2，表示小明会将所有满足x1≤x≤x2,y1≤y≤y2这两个条件的格子放一个豆子。
 *  接下来q行，每行四个整数x1,y1,x2,y2，表示询问所有满足x1≤x≤x2,y1≤y≤y2这两个条件的格子的豆子数量总和。
 *
 * Output:
 *  对于每次询问，输出一行包含一个整数，表示询问的答案。
 *
 * Hints:
 *  1≤n,m≤2000, 1≤k,q≤2*10<5>, 1≤x1≤x2≤n, 1≤y1≤y2≤m
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 2 1 1
1 1 2 2
1 1 2 1
 *
 *  output:
2
 *
 */

#include <iostream>
using namespace std;
const int N = 2010;
int n, m, k, q, d[N][N];
long long s[N][N];

int main()
{
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d[x1][y1]++;
        d[x1][y2 + 1]--;
        d[x2 + 1][y1]--;
        d[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + d[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + d[i][j];
        }
    }
    for (int i = 1; i <= q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}