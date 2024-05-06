/**
 * Description:
 *  为了使得大家高兴，小Q特意出个自认为非常容易的题来满足大家，这道简单题是描述如下：
 *  有一个数列A已知对于所有的A[i]都是1~n的自然数，并且知道对于一些A[i]不能取哪些值，要求你求出所有可能的数列有多少个，输出方案数mod1000000007的值，怎么样，是不是很简单呢？呵呵！
 *
 * Input:
 *  第一行三个整数n,m,k分别表示数列元素的取值范围，数列元素个数，以及已知的限制条数。
 *  接下来k行，每行两个正整数x,y表示A[x]的值不能是y。
 *
 * Output:
 *  一行一个整数表示所有可能的数列的方案数对1000000007取模后的结果。如果一个合法的数列都没有，答案输出0。
 *
 * Hints:
 *  n≤10<9>, m≤10<9>, k≤10<5>, 1≤y≤n, 1≤x≤m
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4 5
1 1
1 1
2 2
2 3
4 3
 *
 *  output:
12
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
LL n, m, k, mod = 1e9 + 7;
struct node {
    int x, y;
} t[100010];

bool cmp(node a, node b)
{
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

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
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> t[i].x >> t[i].y;
    }
    
    sort(t + 1, t + k + 1, cmp);
    LL ans = 1, cnt = 0;
    for (int i = 1; i <= k; i++) {
        if (t[i].x == t[i - 1].x && t[i].y == t[i - 1].y) {
            continue;
        }
        t[++cnt] = t[i];
    }
    int c = 1;
    t[cnt + 1].x = -1;
    for (int i = 2; i <= cnt + 1; i++) {
        if (t[i].x == t[i - 1].x) {
            c++;
        } else {
            ans = ans * (n - c) % mod;
            c = 1;
            m--;
        }
    }
    ans = ans * ksm(n, m, mod) % mod;
    cout << ans << endl;
    return 0;
}