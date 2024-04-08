/**
 * Description:
 *  杨辉三角是一类非常有趣的数阵. 如图所示是一个6行的杨辉三角，杨辉三角最外层的数值均为1,中间的数值则为正上方和左上角的两个数值相加. 读入一个正整数n,请编程打印一个n行的杨辉三角.
 * 
 * Input:
 *  一个正整数n <= 30
 * 
 * Output:
 *  n层杨辉三角
 * 
 * Hints:
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
5
 * 
 *  output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[35][35];

int main()
{
    cin >> n;
    
    a[1][1] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}