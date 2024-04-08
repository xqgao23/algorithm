/**
 * Description:
 *  有一个城市的地图如下图所示：左下角坐标为(0,0)，右上角坐标为(m,n)，图中m=n=5
 *  小猴从左下角出发，每次可以沿着黑线所示的街道向上向右或向右上移动。问小猴移动到右上角共有多少种不同路线？
 * 
 * Input:
 *  一行，两个正整数m,n，用空格分隔。
 * 
 * Output:
 *  一个整数，小猴的移动路线数。
 * 
 * Hints:
 *  1 <= n, m <= 12
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
5 5
 * 
 *  output:
1683
 *
 */

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int m, n, a[15][15];

int main()
{
    cin >> m >> n;
    for (int i = 0; i <= m; i++) {
        a[i][0] = 1;
    }
    
    for (int j = 0; j <= n; j++) {
        a[0][j] = 1;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j] + a[i][j - 1];
        }
    }

    cout << a[m][n] << endl;

    return 0;
}