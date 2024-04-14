/**
 * Description:
 *  直线上依次有1∼n号位置，相邻位置距离为1，部分位置上有百合花，只有这些位置青蛙可以站上去。一只青蛙在1号位置，而它的家在n号位置，他每次可以跳1∼d的距离。你要计算青蛙至少跳几次可以到家。
 *
 * Input:
 *  输入共2行:
 *  第1行，两个用空格隔开的整数n,d，意义如题目描述.
 *  第2行,n长度的由0,1组成的字符串，依次表示1∼n号位置是否有百合花，1表示有，0表示无.
 *
 * Output:
 *  输出共1行:
 *  第1行,1个整数，为青蛙到家至少需要跳的次数. 如果它不可能回家则输出−1.
 *
 * Hints:
 *  2<=n<=100; 1<=d<=n-1
 */

/**
 *  Samples:
 *  1):
 *  input:
12 3
101111100101
 *
 *  output:
4
 *
 */

#include <iostream>
using namespace std;
int n, d, ans = 1e9;
string s;

void dfs(int step, int x)
{
    if (x == n) {
        ans = min(ans, step - 1);
        return;
    }
    for (int i = 1; i <= d; i++) {
        if (x + i <= n && s[x + i] == '1') {
            dfs(step + 1, x + i);
        }
    }
}

int main()
{
    cin >> n >> d >> s;
    s = " " + s;
    dfs(1, 1);
    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}