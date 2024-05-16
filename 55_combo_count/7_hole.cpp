/**
 * Description:
 *  探险队在探险途中先后遇到了k个洞窟。出发时探险队有n人，在第i个洞窟，探险队派出xi人进入洞窟探险。问派去洞窟探险的人员分配方案有多少种？因为答案可能会很大，所以只需输出答案除以p的余数。
 *  例如：探险队有4人，遇到了2个洞窟，先后派出1,2个人探索，那么人员分配方案有以下12种(1)(2,3)；(1)(2,4)；(1)(3,4)；(2)(1,3)；(2)(1,4)；(2)(3,4)；(3)(1,2)；(3)(1,4)；(3)(2,4)；(4)(1,2)；(4)(1,3)；(4)(2,3)；
 *
 * Input:
 *  第1行，3个正整数n,k,p
 *  第2行，k个正整数x1,x2,…,xk
 *
 * Output:
 *  输出人员分配方案数除以p的余数
 *
 * Hints:
 *  1≤n≤2000, 1≤k≤50, 2≤p≤10<9>, 1<=Exi<=n
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 2 10007
1 2
 *
 *  output:
12
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
LL n, k, p, x, C[2010][2010], ans = 1;

void init()
{
    for (int i = 0; i <= 2000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
        }
    }
}

int main()
{
    cin >> n >> k >> p;
    init();
    for (int i = 1; i <= k; i++) {
        cin >> x;
        ans = ans * C[n][x] % p;
        n -= x;
    }
    cout << ans << endl;
    return 0;
}