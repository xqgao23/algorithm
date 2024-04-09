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

int n, a[110][110], x;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            x += a[i][j];
        }
    }
    x /= n;
    
    // 检查 行和==x
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += a[i][j];
        }
        if (sum != x) {
            cout << "No" << endl;
            return 0;
        }
    }

    // 检查 列和==x
    for (int j = 1; j <= n; j++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i][j];
        }
        if (sum != x) {
            cout << "No" << endl;
            return 0;
        }
    }

    // 检查 主对角和==x
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i][i];
    }
    if (sum != x) {
        cout << "No" << endl;;
        return 0;
    }

    // 检查 副对角线==x
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i][n + 1 - i];
    }
    if (sum != x) {
        cout << "No" << endl;
        return 0;
    }
    // 是幻方
    cout << "Yes" << endl;
    return 0;
}