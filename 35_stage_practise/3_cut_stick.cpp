/**
 * Description:
 *  有n根木棍，长度分别是a1,a2,…,an，可以最多切割k次，每次切割只能将一根木棍切成两段整数长度的木棍。切割得到的木棍也可以再被切成两段。
 *  在所有切割k次的方法中，最长的一段木棍的长度最小可能有多短？
 *
 * Input:
 *  第1行，2个正整数n,k
 *  第2行，n个正整数a1,a2,...,an
 *
 * Output:
 *  1个整数，输出答案。
 *
 * Hints:
 *  1≤n≤2*10<5>, 0≤k≤10<9>,1≤ai≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 3
7 9
 *
 *  output:
4
 *
 *  2):
 *  input:
3 0
3 4 5
 *
 *  output:
5
 *
 *  3):
 *  input:
10 10
158260522 877914575 602436426 24979445 861648772 623690081 433933447 476190629 262703497 211047202
 *
 *  output:
292638192
 *
 */

#include <iostream>
using namespace std;
int n, k, a[200010];

bool check(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        // 段数 = 切割次数 + 1
        cnt += (a[i] + x - 1) / x - 1;
    }
    return cnt <= k;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}