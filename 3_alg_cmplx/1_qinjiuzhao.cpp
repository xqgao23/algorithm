/**
 * Description:
 *  计算多项式的值：
 *      f(x)=anx<n>+an-1xn-1+…+a1x+x和 ai 都是整数，输出 (x) 除以 998244353 的非负余数。
 * 
 * Input:
 *  第1行，2 个整数 n,x
 *  第2行，n+1 个正整数 a0,a1,⋯,an
 * 
 * Output:
 *  输出 f(x) 除以998244353 的非负余数。
 * 
 * Hints:
 *  1<=n<=10<6>
 *  -10<9> <= x <= 10<9>
 *  -10<9> <= ai <= 10<9>
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
2 3
-4 3 1
 * 
 *  output:
14
 *
 *  2):
 *  input:
2 3
1 3 -4
 * 
 *  output:
998244327
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, x, a[1000010], mod = 998244353;

int main()
{
    cin >> n >> x;

    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    
    long long ans = a[n];
    
    for (int i = n - 1; i >= 0; i--) {
        ans = ((ans * x + a[i]) % mod + mod) % mod;
    }
    
    cout << ans << endl;
    
    return 0;
}