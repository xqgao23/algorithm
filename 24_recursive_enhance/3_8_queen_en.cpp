/**
 * Description:
 *  对一个如下的8×8的国际象棋棋盘，有八个皇后被放置在棋盘上，使得每行、每列和每条斜线上都至多只有一个皇后,
 *  类似地我们可以定义n皇后问题:n×n的国际象棋棋盘，有n个皇后被放置在棋盘上，使得每行、每列和每条斜线上都至多只有一个皇后.
 *  你需要根据n,输出n皇后问题的第一个解. 容易发现一个解中，每行一定会恰好有一个皇后，我们规定两个解中如果前k−1行的皇后位置相同，则第k行的皇后更靠前（靠左）的排在前面.（或者说，以皇后的每行位置，按字典序排序）
 *
 * Input:
 *  输入共 1 行：
 *  第1行，2个正整数n, k, 表示我们要求解n皇后问题的前k个解。
 *
 * Output:
 *  k行。
 *  第k行,n用空格隔开的正整数，依次表示第i组解中第1,2,⋯,n行的皇后在第几个位置.
 *
 * Hints:
 *  1<=n<=18，1<=k<=5
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8 1
 *
 *  output:
1 5 8 6 3 7 2 4
 *
 */

// 方法一
#include <iostream>
using namespace std;
int n, k, a[20], vis[20], flag;

bool check(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j] || i + a[i] == j + a[j] || i - a[i] == j - a[j]) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int step)
{
    if (k == 0) {
        return;
    }
    if (step > n) {
        if (check(n)) {
            k--;
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            a[step] = i;
            if (!check(step)) {
                continue;
            }
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> k;
    dfs(1);
    return 0;
}