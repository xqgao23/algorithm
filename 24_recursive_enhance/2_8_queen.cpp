/**
 * Description:
 *  对一个如下的8×8的国际象棋棋盘，有八个皇后被放置在棋盘上，使得每行、每列和每条斜线上都至多只有一个皇后,
 *  类似地我们可以定义n皇后问题:n×n的国际象棋棋盘，有n个皇后被放置在棋盘上，使得每行、每列和每条斜线上都至多只有一个皇后.
 *  容易发现每行一定会恰好有一个皇后，我们用ai表示第i行的皇后在第ai列。例如图中的解可以表示成{1,5,8,6,3,7,2,4}。给出数组a1,a2,..,an，验证这组排列属否是n皇后的一个解。
 *
 * Input:
 *  输入共 1 行：
 *  第1行，一个正整数n, 表示我们要求解n皇后问题。
 *
 * Output:
 *  第1行,n用空格隔开的正整数，依次表示第一组解中第1,2,⋯,n行的皇后在第几个位置.
 *
 * Hints:
 *  1<=n<=10
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8
 *
 *  output:
1 5 8 6 3 7 2 4
 *
 */

#include <iostream>
using namespace std;
int n, a[20], vis[20], flag;

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

void dfs(int step)
{
    if (flag) {
        return;
    }
    if (step > n) {
        if (check()) {
            flag = 1;
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            a[step] = i;
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
    return;
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
