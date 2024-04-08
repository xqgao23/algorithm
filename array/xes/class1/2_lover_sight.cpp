/**
 * Description:
 *  一幅画是由n行m列的字符组成的矩形，画很美，而你却只关心画中的一个人. 这个人出现的位置是第n1行到第n2行，第m1列到第m2列所组成的矩形. 读入这幅画，并输出画中人.
 * 
 * Input:
 *  输入由n+1行组成
 *  第一行为6个正整数n,m,n1,n2,m1,m2
 *  接下来的n行每行有m个用空格隔开的正整数(0或1),代表画中第n行的字符
 * 
 * Output:
 *  输出由n2−n1+1行组成, 每行有m2−m1+1个0或1组成（用空格隔开）, 这是"画中人"所占据的矩形.
 * 
 * Hints:
 *  5 <= n, m <= 30, 1 <= n1 < n2 <= n, 1 <= m1 < m2 <= m
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
8 6 2 7 3 5
0 0 0 0 0 0
0 0 1 1 1 0
0 0 1 1 1 0
0 0 0 1 0 0
0 0 1 1 1 0
0 0 0 1 0 0
0 0 1 0 1 0
0 0 0 0 0 0
 * 
 *  output:
1 1 1
1 1 1
0 1 0
1 1 1
0 1 0
1 0 1
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, n1, n2, m1, m2, a[35][35];

int main()
{
    cin >> n >> m >> n1 >> n2 >> m1 >> m2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = n1; i <= n2; i++) {
        for (int j = m1; j <= m2; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}