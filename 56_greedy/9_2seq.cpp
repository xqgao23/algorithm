/**
 * Description:
 *  给你两个序列a1,a2,...,an, b1,b2,...bn.
 *  定义一个函数f(l, r) = sum<l<=i<=r> ai*bi
 *  你的任务是重新排列序列b（序列a不变），使得总和S=sum<1<=l<=r<=n>f(l, r)最小。输出最小值。
 *
 * Input:
 *  第1行, 一个正整数n, 代表项数.
 *  第2行, n个正整数, 用空格分隔, 代表a1,a2,...,an
 *  第3行, n个正整数, 用空格分隔, 代表b1,b2,...,bn
 *
 * Output:
 *  1个整数，表示S的最小值。
 *
 * Hints:
 *  1≤n≤2*10<5>, 1≤ai,bi≤10<6>, 保证答案不超过9*10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
1 7 8 
9 7 2
 *
 *  output:
251
 *
 */

#include <iostream>
using namespace std;
long long n, a[200010], b[200010], ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i * (n - i + 1) * a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        ans += a[i] * b[n - i + 1];
    }
    cout << ans << endl;
    return 0;
}