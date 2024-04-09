/**
 * Description:
 *  给出n行n列共n2个正整数，构成n×n的数阵. 求左下-右上的对角线上的数之和并输出.
 * 
 * Input:
 *  输入由n+1行组成
 *  第一行为一个正整数n<=100
 *  接下来的n行为一个n×n的正方形数阵
 * 
 * Output:
 *  一个整数，输出斜线的和
 * 
 * Hints:
 * 
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
3
8 1 6
3 5 7
4 9 2
 * 
 *  output:
15
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[110][110];

int main()
{
    int n;
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += a[i][n + 1 - i];
    }
    cout << sum << endl;
    
    return 0;
}