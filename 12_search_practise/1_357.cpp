/**
 * Description:
 *  我们定义只由357三种数码组成，相邻数码不同，且包含所有三种数码的正整数为357数。例如35757是一个357数；3557不是一个357数因为两个相同的数码相邻；35353不是一个357数因为只包含两种数码。
 *  给出正整数n，从小到大输出所有n位的357数。
 *
 * Input:
 *  一个正整数N
 *
 * Output:
 *  输出若干行，每行一个从小到大输出所有n位的357数。
 *
 * Hints:
 *  3<=n<=15
 */

/**
 *  Samples:
 *  1):
 *  input:
3
 *
 *  output:
357
375
537
573
735
753
 *
 */

#include <iostream>
using namespace std;
int n;

void dfs(int step, long long x, int c3, int c5, int c7)
{
    if (step > n) {
        if (c3 && c5 && c7) {
            cout << x << endl;
        }
        return;
    }
    if (x % 10 != 3) {
        dfs(step + 1, x * 10 + 3, 1, c5, c7);
    }

    if (x % 10 != 5) {
        dfs(step + 1, x * 10 + 5, c3, 1, c7);
    }

    if (x % 10 != 7) {
        dfs(step + 1, x * 10 + 7, c3, c5, 1);
    }
}

int main()
{
    cin >> n;
    dfs(1, 0, 0, 0, 0);
    return 0;
}