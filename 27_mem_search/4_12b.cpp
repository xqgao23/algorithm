/**
 * Description:
 *  小猴想通过以下两种变换，把1变成b.
 *  1.把现有的数x变为x+d;
 *  2.把现有的数x变为px+1.
 *  例如b=43,d=10,p=3,你可以以如下的方式把1变成b
 *  1×3+1=4
 *  4+10=14
 *  14×3+1=43
 *  你需要帮小猴判断一下，把1变成b最少需要多少次变换。
 *
 * Input:
 *  3个正整数b,d,p
 *
 * Output:
 *  输出最小操作次数，如果无法变换成b输出-1。
 *
 * Hints:
 *  1≤b≤10<6>, 1≤d,p≤100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
43 10 3
 *
 *  output:
3
 *
 */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int b, d, p, f[1000010];

int dfs(int x)
{
    if (x > b) {
        return 1e9;
    }
    if (f[x] != -1) {
        return f[x];
    }
    if (x == b) {
        return f[x] = 0;
    }
    return f[x] = min(dfs(x + d), dfs(p * x + 1)) + 1;
}

int main()
{
    cin >> b >> d >> p;
    memset(f, -1, sizeof f);
    int ans = dfs(1);
    if (ans >= 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}