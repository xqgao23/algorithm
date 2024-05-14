/**
 * Description:
 *  大陆上有东西两个国家。西国计划派出一批间谍潜伏在东国，于是，选人的工作就落到了你身上。
 *  你现在有n个人可选，每个人都有3个数据：ai（暴露的风险）、bi（需要花费的资金）、ci（侦察能力）。
 *  派出的人越多，暴露的风险就越大；你的资金也是有限的。你要求出：在总暴露的风险不超过m且总资金不超过x的前提下，派出的间谍侦察能力的总和的最大值。
 *
 * Input:
 *  第1行，3个正整数n,m,x。
 *  接下来n行，每行三个整数ai,bi,ci
 *
 * Output:
 *  1个整数，输出侦察能力的总和的最大值。
 *
 * Hints:
 *  1≤n≤100，1≤m,x≤1000, 1≤ai,bi,ci≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 10 12
10 5 11
1 5 1
7 5 10
 *
 *  output:
11
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, x, a[110], b[110], c[110], f[1010][1010];

int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = m; i >= a[k]; i--) {
            for (int j = x; j >= b[k]; j--) {
                f[i][j] = max(f[i][j], f[i - a[k]][j - b[k]] +
                                           c[k]);
            }
        }
    }
    cout << f[m][x] << endl;
    return 0;
}