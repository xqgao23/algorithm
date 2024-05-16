/**
 * Description:
 *  考虑一个长为 n 的正整数数列 a1,a2,…,an.。满足如下条件：
 *  （1）1≤ai≤ci（1≤i≤n）
 *  （2）a≠aj（1≤i<j≤n）
 *  其中 c1,c2,...,cn 是已知的正整数。
 *  你要求出有多少种不同的数列 a 满足条件。答案会很大，所以只需要输出答案除以 10<9>+7 的余数。
 *
 * Input:
 *  第 1 行，1 个正整数n
 *  第 2 行，n 个正整数c1,c2,...,cn
 *
 * Output:
 *  输出答案除以10<9>+7的余数
 *
 * Hints:
 *  1≤n≤2*10<5>, 1≤ci≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
3 4 2
 *
 *  output:
8
 *
 *  2):
 *  input:
4
2 2 5 2
 *
 *  output:
0
 *
 *  3):
 *  input:
6
999999917 999999914 999999923 999999985 999999907 999999965
 *
 *  output:
445098549
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL n, c[200010], ans = 1, mod = 1e9 + 7;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
        if (c[i] < i) {
            cout << 0 << endl;
            return 0;
        }
        ans = ans * (c[i] - i + 1) % mod;
    }
    cout << ans << endl;
    return 0;
}