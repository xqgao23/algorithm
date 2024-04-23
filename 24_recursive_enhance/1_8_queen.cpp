/**
 * Description:
 *  对一个如下的8×8的国际象棋棋盘，有八个皇后被放置在棋盘上，使得每行、每列和每条斜线上都至多只有一个皇后,
 *  类似地我们可以定义n皇后问题:n×n的国际象棋棋盘，有n个皇后被放置在棋盘上，使得每行、每列和每条斜线上都至多只有一个皇后.
 *  容易发现每行一定会恰好有一个皇后，我们用ai表示第i行的皇后在第ai列。例如图中的解可以表示成{1,5,8,6,3,7,2,4}。给出数组a1,a2,..,an，验证这组排列属否是n皇后的一个解。
 *
 * Input:
 *  输入共 2 行：
 *  第1行，一个正整数n
 *  第2行，n个正整数，数组a1,a2,…,an
 *
 * Output:
 *  输出共 1 行：
 *  如果是一个解，则输出"Yes"，否则输出"No"。
 *
 * Hints:
 *  1<=n<=10, 1<=ai<=n
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8
1 5 8 6 3 7 2 4
 *
 *  output:
Yes
 *
 */

// 二重循环
#include <iostream>
using namespace std;
int n, a[20];

bool check()
{
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j] || abs(i - j) == abs(a[i] - a[j])) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (check()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}