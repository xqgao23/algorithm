/**
 * Description:
 *  你将得到一个整数n,请列出把整数n划分为k个正整数的每一种方法.
 *
 * Input:
 *  输入共1行;
 *  第1行，2个正整数n,k;
 *
 * Output:
 *  输出为若干行:
 *  每行为用空格隔开的若干个正整数，为一种n划分为k个数的方法，每组数按从小到大输出.
 *  若两种方法中前k−1个数相同，则第k个数更小的在前.
 *
 * Hints:
 *  1≤k≤n≤20
 */

/**
 *  Samples:
 *  1):
 *  input:
6 3
 *
 *  output:
1 1 4
1 2 3
2 2 2
 *
 */

#include <iostream>
using namespace std;
int n, k, p[30];

void dfs(int step, int sum)
{
    if (sum > n) {
        return;
    }
    if (step > k) {
        if (sum == n) {
            for (int i = 1; i <= k; i++) {
                cout << p[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = p[step - 1]; i <= n; i++) {
        p[step] = i;
        dfs(step + 1, sum + i);
    }
}

int main()
{
    cin >> n >> k;
    p[0] = 1;
    dfs(1, 0);
    return 0;
}