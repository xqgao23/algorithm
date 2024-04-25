/**
 * Description:
 *  考虑如下的递推函数F(n,0)=0 (n>0)
 *  F(n,n)=1 (n≥0)
 *  F(n,k)=0 (k>n)
 *  F(n,k)=F(n−1,k−1)+kF(n−1,k) (1≤k<n)
 *  输入n,k, 求F(n,k)除以10<9>+7的余数, 用递归函数实现.
 *
 * Input:
 *  两个整数n, k
 *
 * Output:
 *  输出F(n,k)的值除以10<9>+7的余数
 *
 * Hints:
 *  0≤k≤n≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 2
 *
 *  output:
3
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int n, k, mod = 1e9 + 7, f[1010][1010];

int F(int n, int k)
{
    if (f[n][k] != -1) {
        return f[n][k];
    }
    if (k == 0 || k > n) {
        return f[n][k] = 0;
    }
    if (k == n) {
        return f[n][k] = 1;
    }
    return f[n][k] = (F(n - 1, k - 1) + 1ll * k * F(n - 1, k)) % mod;
}

int main()
{
    cin >> n >> k;
    memset(f, -1, sizeof f);
    cout << F(n, k) << endl;
    return 0;
}