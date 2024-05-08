/**
 * Description:
 *  给出数组a的元素a[1],a[2],⋯,a[n]的值，如果我们取连续且非空的一段，那么这段的和最大是多少?
 *
 * Input:
 *  第1行，是一个正整数n,数组a的长度。
 *  第2行，用空格隔开的n个整数，依次是a[1],a[2],⋯,a[n]的值。
 *
 * Output:
 *  1个整数，为所求的最大的和.
 *
 * Hints:
 *  n≤100000；对1≤i≤n,−10000≤a[i]≤10000. 数组a中至少有1个正数
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
1 -6 5 -4 2 4
 *
 *  output:
7
 *
 */

#include <iostream>

using namespace std;

int n, a[100010], f[100010];
// f[i] 表示以 a[i] 结尾的最大子段和

int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], 0) + a[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }
    
    cout << ans << endl;

    return 0;
}