/**
 * Description:
 *  一张方格表由 n 行 m 列的方格组成，而小猴站在左上角的格子中，他每次只能走到所在格 子右边或下边相邻的格子中。但是有些格子中有坑，这些有坑格子是不能走的！
 *  研究一下方格表的坑，然后告诉小猴现在他想走到右下角的格子有几种不同的走法吧！
 * 
 * Input:
 *  输入由n+1行组成
 *  第一行为两个整数n和m (0<n,m<=20)
 *  第二行至第n+1行每行有m个整数，第i行第j列的整数代表地图上坐标为(i,j)的点是否可以通过,1表示该点可以通过,0表示该点不能通过.(数据保证(1,1)=1,(n,m)=1,即左上角和右下角都是可以通过的).
 * 
 * Output:
 *  输出包含一个正整数，表示所求的走法数。
 * 
 * Hints:
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
4 5
1 1 1 1 0
0 1 1 1 0
0 1 0 1 1
1 1 1 1 1
 * 
 *  output:
7
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[25][25], b[25][25];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    b[1][1] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            
            if (a[i][j] == 1) {
                b[i][j] = b[i-1][j] + b[i][j-1];
            }
        }
    }
    
    cout << b[n][m] << endl;
    
    return 0;
}