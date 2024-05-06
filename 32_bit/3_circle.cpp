/**
 * Description:
 *  n 个小伙伴（编号从 0 到 n−1）围坐一圈玩游戏。按照顺时针方向给 n 个位置编号，从0 到 n−1。最初，第 0 号小伙伴在第 0 号位置，第 1 号小伙伴在第 1 号位置，......，依此类推。游戏规则如下：每一轮第 0 号位置上的小伙伴顺时针走到第 m 号位置，第 1 号位置小伙伴走到第 m+1 号位置，......，依此类推，第 n−m 号位置上的小伙伴走到第 0 号位置，第n−m+1 号位置上的小伙伴走到第 1 号位置，......，第 n−1 号位置上的小伙伴顺时针走到第 m−1 号位置。
 *  现在，一共进行了 10<k> 轮，请问 x 号小伙伴最后走到了第几号位置。
 *
 * Input:
 *  n,m,k,x
 *
 * Output:
 *  10<k>轮后x 号小伙伴所在的位置编号。
 *
 * Hints:
 *  1<n<1000000, 0<m<n, 1≤x≤n, 0<k<10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 3 4 5
 *
 *  output:
5
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
LL n, m, k, x;

LL ksm(LL a, LL b, LL p)
{
    LL ans = 1 % p;
    while (b) {
        if (b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cin >> n >> m >> k >> x;
    cout << (x + m * ksm(10, k, n) % n) % n << endl;
    return 0;
}