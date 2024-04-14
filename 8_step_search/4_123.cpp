/**
 * Description:
 *  一个数中如果如果不含连续的"12",连续的"23",连续的"31", 就称作"123"好数.
 *  那么, 在由123构成的n位数中, 第k个"123"好数是什么?
 *
 * Input:
 *  一行, 两个正整数n,k, 用空格分隔
 *
 * Output:
 *  一行, 输出由123构成的n位数中, 第k个"123"好数.
 *
 * Hints:
 *  1≤n≤20 k不超过满足条件的"123"好数个数
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 14
 *
 *  output:
113322
 *
 */

#include <iostream>
using namespace std;
int n, k, p[30], cnt;

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
    for (int i = 1; i <= 3; i++) {
        p[step] = i;
        if (p[step - 1] == 1 && p[step] == 2) {
            continue;
        }
        if (p[step - 1] == 2 && p[step] == 3) {
            continue;
        }
        if (p[step - 1] == 3 && p[step] == 1) {
            continue;
        }
        dfs(step + 1);
    }
}

int main()
{
    cin >> n >> k;
    dfs(1);
    return 0;
}