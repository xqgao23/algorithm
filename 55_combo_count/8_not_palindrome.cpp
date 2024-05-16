/**
 * Description:
 *  Alice 有 n 个字符，它们都是英文小写字母，从 1∼n 编号，分别为 c1,c2,…,cn。
 *  Bob 准备将这些字符重新排列，组成一个字符串 S。Bob 知道 Alice 有强迫症，所以他打算将 S 组成一个非回文串来折磨 Alice。
 *  现在 Bob 想知道他共有多少种不同的排列字符的方案，能使得 S 是个非回文串。一种排列字符的方案指的是一个 1∼n 的排列 pi，它所组成的 S=cp1cp2…cpn。
 *  一个字符串是非回文串，当且仅当它的逆序串与原串不同。例如 abcda 的逆序串为 adcba，与原串不同，故 abcda 是非回文串。而 abcba 的逆序串与原串相同，是回文串。
 *  由于最后的结果可能很大，你只需要告诉 Bob 总方案数对 10<9>+7 取模后的值。
 *
 * Input:
 *  第一行一个正整数 n 表示字符个数。
 *  第二行 n 个英文小写字母ci
 *
 * Output:
 *  仅一行一个整数表示答案。答案对 10<9>+7 取模。
 *
 * Hints:
 *  3≤n≤2000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
aba
 *
 *  output:
4
 *
 *  1):
 *  input:
8
aabbbbcc
 *
 *  output:
39168
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
int n, c[30], mod = 1e9 + 7;
string s;
int fact(int n, int x) // x * ...* n
{
    LL ans = 1;
    for (int i = x; i <= n; i++) {
        ans = ans * i % mod;
    }
    return ans;
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        c[s[i] - 'a']++;
    }

    LL k = 0, ans = fact(n, 1), t = fact(n / 2, 1);

    for (int i = 0; i <= 25; i++) {
        k += c[i] & 1;
    }

    if (k > 1) {
        cout << ans << endl;
        return 0;
    }

    for (int i = 0; i <= 25; i++) {
        t = t * fact(c[i], c[i] / 2 + 1) % mod;
    }

    cout << (ans - t + mod) % mod << endl;
    return 0;
}