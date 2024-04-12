/**
 * Description:
 *  给出数组a的元素a[1],a[2],⋯,a[n]的值，如果我们取连续且非空的一段，那么这段的和最大是多少?
 * 
 * Input:
 *  第1行，是一个正整数n,数组a的长度。
 * 	第2行，用空格隔开的n个整数，依次是a[1],a[2],⋯,a[n]的值。
 * 
 * Output:
 *  1个整数，为所求的最大的和.
 * 
 * Hints:
 *  n≤100000; 对1≤i≤n,-10000≤a[i]≤10000. 数组a中至少有1个正数
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

// 前缀和 + 后缀最值 满分做法
/*
 * 以第i项为起点的最大字段和: max(s[i]-s[i-1],s[i+1]-s[i-1],s[i+2]-s[i-1],...,s[n-1]-s[i- 1],s[n]-s[i-1]) 即:max(s[i],s[i+1],s[i+2],...,s[n-1],s[n])-s[i-1]
 */
#include <iostream>
#include <algorithm>

using namespace std;
// s[i]表示a[1]~a[i]的元素和，maxs[i]表示s[i]~s[n]的最大值
int n, a[100010], s[100010], maxs[100010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    maxs[n] = s[n];
    for (int i = n - 1; i >= 1; i--) {
        maxs[i] = max(maxs[i + 1], s[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {// 以第i项为起点的最大字段和
        ans = max(ans, maxs[i] - s[i - 1]);
    }

    cout << ans << endl;
    return 0;
}