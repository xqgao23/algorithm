/**
 * Description:
 *  给定一张有向图G，图上有n个点和m条边，请你输出该有向图的邻接矩阵表示
 *
 * Input:
 *  第一行两个正整数n(1≤n≤200)和m(1≤m≤5000)
 *  接下来m行，每行两个整数x,y，表示有一条边从x指向y
 *
 * Output:
 *  输出一个n×n的邻接矩阵A，其中Aij=1表示i到j有一条边，Aij=0表示i到j没有边。
 *  每行n个整数，每个整数之间用空格隔开，注意最后一个整数后面没有空格
 *
 * Hints:
 *  2 ≤ N ≤ 2 × 10<5>, 1 ≤ Q ≤ 2 × 10<5>, 1 ≤ xi ≤ N
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1 2
2 3
1 3
 *
 *  output:
0 1 1
0 0 1
0 0 0
 *
 */

#include <iostream>
using namespace std;
int n, m, g[210][210];

int main()
{
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}