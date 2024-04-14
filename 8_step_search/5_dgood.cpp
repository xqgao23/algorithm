/**
 * Description:
 *  一个只由1∼m数码组成的n位数, 如果任意两个相邻数之差的绝对值都不超过d,则称这个数是一个"d好数".
 *  给出n,m,d,输出n位"d好数"的个数. d的值只可能取1,2,3.
 *
 * Input:
 *  1行,3个正整数n,m,d
 *
 * Output:
 *  输出n位"d好数"的个数.
 *
 * Hints:
 *  1≤n≤10;1≤m≤9;1≤d≤3;
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3 1
 *
 *  output:
99
 *
 */

#include <iostream>
using namespace std;
int n, m, d, p[20], ans;

void dfs(int step)
{
    if (step > n) {
        ans++;
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (step > 1 && abs(i - p[step - 1]) > d) {
            continue;
        }
        p[step] = i;
        dfs(step + 1);
    }
}

int main()
{
    cin >> n >> m >> d;
    dfs(1);
    cout << ans << endl;
    return 0;
}