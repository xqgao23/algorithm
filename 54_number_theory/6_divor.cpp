/**
 * Description:
 *  小明在研究约数，他发现一个数的约数中，有一些约数恰好是一个平方数。他将这些约数称作“平方约数”
 *  例如600的约数中，4=2<2>、25=5<2>和100=10<2>是“平方约数”。
 *  给出整数n,m，小明想要知道n,n<2>,n<3>,⋯中，第一个拥有至少m个“平方约数”的数是哪一个？
 *  你需要输出使得n<b>拥有至少m个“平方约数”的最小正整数b。
 *
 * Input:
 *  第1行，两个正整数n,m
 *
 * Output:
 *  最小正整数b
 *
 * Hints:
 *  1≤n,m≤10<12>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 12
 *
 *  output:
6
 *
 *  2):
 *  input:
2016 9999
 *
 *  output:
20
 *
 *
 *  3):
 *  input:
2401 1000000000000
 *
 *  output:
500000000000
 *
 */

// 二分枚举
#include <iostream>
using namespace std;
typedef long long LL;
LL n, m, c[20], cnt;

bool check(LL b)
{
    LL s = 1;
    for (int i = 1; i <= cnt; i++) {
        if (b * c[i] / 2 + 1 > m / s) {
            return true;
        }
        s *= b * c[i] / 2 + 1;
    }
    return s >= m;
}

int main()
{
    cin >> n >> m;
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            while (n % i == 0) {
                c[cnt]++, n /= i;
            }
        }
    }
    if (n > 1) {
        c[++cnt] = 1;
    }
    LL l = 1, r = 2 * m, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}