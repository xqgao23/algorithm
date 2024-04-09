/**
 * Description:
 *  幻方是一类有趣的数阵，它是由若干个整数组成的正方形.对于一个幻方，它每一行、每一列和两条对角线上的数相加之和均为同一个值.给定一个正方形的数阵，请编程判断它是否是一个幻方.
 * 
 * Input:
 *  输入由n+1行组成
 *  第一行为一个正整数n<=100
 *  接下来的n行为一个n×n的正方形数阵，数据保证此数阵由1∼n2的所有整数组成
 * 
 * Output:
 *  若此数阵是一个幻方，输出"Yes";否则输出"No"
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
Yes
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[110][110], s1[110], s2[110], x1, x2;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            s1[i] += a[i][j];
            s2[j] += a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        x1 += a[i][i];
        x2 += a[i][n + 1 - i];
    }
    
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (s1[i] != x1) {
            flag = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s2[i] != x1) {
            flag = false;
        }
    }
    
    if (x2 != x1) {
        flag = false;
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;;
    }

    return 0;
}