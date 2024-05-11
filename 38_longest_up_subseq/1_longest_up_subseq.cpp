/**
 * Description:
 *  在 a1,a2,…,an 中 , 一个 k 长度子序列指 ai1,ai2,…,aik, 使得1≤i1<i2<⋯<ik≤n
 *  如果ai1<ai2<⋯<aik , 请输出k的最大值 . （即求出数组a 的最长上升子序列⻓度）
 *
 * Input:
 *  输入共 2 行：
 *  第 1 行 , 一个正整数n, 为原数组a中的元素的个数 ;
 *  第 2 行 ,n个用空格隔开的正整数a1,a2,…,an.
 *
 * Output:
 *  输出共 1 行：
 *  第 1 行 , 一个正整数ans, 为k的最大值（即a的最长上升子序列长度）
 *
 * Hints:
 *  10≤n≤5000；1≤ai≤1000000000；
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
12
35 42 4 12 29 21 29 11 1 42 43 49
 *
 *  output:
7
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, a[5010], f[5010], ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}