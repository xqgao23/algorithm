/**
 * Description:
 *  一幅画是由 n 行 m 列的 0,1 组成的矩形，画中人很美，所以你想知道她倒立起来是不是会别有一番风味，于是你决定把画进行上下翻转。
 *  具体而言，对于 n 行的画，把第 i 行 (1<=n) 和第 n−i+1 行对调就可以了！ 读入这幅画，输出画着倒立情人的画吧。
 * 
 * Input:
 *  输入由 n+1 行组成：
 *  第 1 行为 2 个正整数 n,m，表示画的尺寸为 n 行 m 列；
 *  接下来的 n 行每行有 m 个用空格隔开的正整数，代表画中每一行的数字。
 * 
 * Output:
 *  输出由 n 行组成：
 *  每行有 m 个用空格隔开的数字，这是把画进行上下翻转后的样子。
 * 
 * Hints:
 *  5 <= n, m <= 30
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
6 6
0 0 1 1 1 0
0 0 1 1 1 0
0 0 0 1 0 0
0 0 1 1 1 0
0 0 0 1 0 0
0 0 1 0 1 0
 * 
 *  output:
0 0 1 0 1 0
0 0 0 1 0 0
0 0 1 1 1 0
0 0 0 1 0 0
0 0 1 1 1 0
0 0 1 1 1 0
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[35][35], b[35][35];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[n + 1 - i][j] = a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}