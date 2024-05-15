/**
 * Description:
 *  高桥王国有一条横贯东西的铁路，铁路边有N个都市，从西向东编号为1∼N。
 *  AtCoder特快在这条铁路上经营着M个列车，列车i的起点在都市Li，终点是都市Ri（有可能Li=Ri）。
 *  高桥君对Q个问题感兴趣，每个问题都有如下形式：
 *  对于都市p到都市q，有多少个列车的运行区间完全被包含在都市p到都市q之间。也就是问同时满足p≤Li和Ri≤q的i的个数。
 *
 * Input:
 *  第1行，3个正整数N,M,Q
 *  接下来M行，每行两个正整数Li,Ri
 *  接下来Q行，每行两个正整数p,q
 *
 * Output:
 *  输出Q行，对于每个询问，用一行输出答案
 *
 * Hints:
 *  1≤N≤500, 1≤M≤200000, 1≤Li≤Ri≤N, 1≤Q≤100000,1≤p≤q≤N,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 3 1
1 1
1 2
2 2
1 2
 *
 *  output:
3
 *
 *  2):
 *  input:
10 3 2
1 5
2 8
7 10
1 7
3 10
 *
 *  output:
1
1
 *
 */

#include <iostream>
using namespace std;
int n, m, q, a[510][510], s[510][510];

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        a[l][r]++;
    }
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << s[y][y] - s[x - 1][y] - s[y][x - 1] + s[x - 1][x - 1] << endl;
    }
    return 0;
}