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

// 暴力枚举
#include <iostream>
#include <algorithm>

using namespace std;
// s[i]表示a[1]~a[i]的元素和
int n, a[100010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int sum = 0;

            for (int k = i; k <= j; k++) {
				sum += a[k];
			}
            ans = max(ans, sum);
        }
	}
    cout << ans << endl;
    return 0;
}