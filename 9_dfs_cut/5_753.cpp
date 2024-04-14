/**
 * Description:
 *  我们定义只由357三种数码组成，且包含所有三种数码的正整数为753数。
 *  给出正整数N，输出不超过N的753数的个数。
 *
 * Input:
 *  一个正整数N
 *
 * Output:
 *  不超过N的753数的个数
 *
 * Hints:
 *  1<=N<=10<9>
 */

/**
 *  Samples:
 *  1):
 *  input:
575
 *
 *  output:
4
 *
 *  2):
 *  input:
3600
 *
 *  output:
13
 *
 */

#include <iostream>
using namespace std;
int n, cnt;

void dfs(int step, long long x, int c3, int c5, int c7)
{
    if (x > n) {
        return;
    }
    if (c3 && c5 && c7) {
        cnt++;
    }
    dfs(step + 1, x * 10 + 3, 1, c5, c7);
    dfs(step + 1, x * 10 + 5, c3, 1, c7);
    dfs(step + 1, x * 10 + 7, c3, c5, 1);
}

int main()
{
    cin >> n;
    dfs(1, 0, 0, 0, 0);
    cout << cnt << endl;
    return 0;
}