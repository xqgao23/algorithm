/**
 * Description:
 *  从左往右，如果每一位数字都大于等于其左边的数字，这样的数被称为上升数，比如134468。
 *  给出n和k，输出所有n位的上升数中从小到大排列后的第k个数。
 *
 * Input:
 *  2个正整数n，k
 *
 * Output:
 *  输出从小到大第k个n位上升数。
 *
 * Hints:
 *  3≤n≤30
 *  1≤k≤10<7>
 *  保证k不超过n位上升数的个数
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 30
 *
 *  output:
149
 *
 *  1):
 *  input:
28 152156
 *
 *  output:
1111111111111112234568888999
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n, k, p[40], cnt;

void dfs(int step)
{
    if (cnt >= k) {
        return;
    }
    if (step > n) {
        cnt++;
        if (cnt == k) {
            for (int i = 1; i <= n; i++) {
                cout << p[i];
            }
            cout << endl;
        }
        return;
    }
    for (int i = p[step - 1]; i <= 9; i++) {
        p[step] = i;
        // if (step > 1 && i < p[step - 1]) continue;
        dfs(step + 1);
    }
}

int main()
{
    cin >> n >> k;
    p[0] = 1;
    dfs(1);
    return 0;
}