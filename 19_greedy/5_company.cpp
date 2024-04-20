/**
 * Description:
 *  黑心企业的老板黑先生只愿意雇临时工来完成工作。
 *  每项工作都有一个难度w，每个临时工都有一个能力值p，当且仅当w≤p时，这个临时工可以完成这项工作。一个临时工最多只能完成一项工作，而且无论工作的难度如何都会收取固定的工资k×p，其中p是他的能力值，k是一个事先给定的数。
 *  黑先生这里有m项工作需要完成，他拿到了一份n名可用的临时工能力清单，请帮他算一算，他最少花多少钱才能把所有工作完成吧。
 *
 * Input:
 *  输入共 n+1 行：
 *  第 1 行，2 个用空格隔开的整数 n,k，表示人数和船的承重；
 *  之后 n 行，每行 1 个整数，分别表示 n 个人的体重。
 *
 * Output:
 *  输出共1行：
 *  第1行，1个正整数，为黑先生最少需要付的工资
 *
 * Hints:
 *  1≤m<=n<=300000, 1<=k<=10, 1<=p1,p2,...,pn,w1,w2,..,wm<=10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 3 2
100 8 7 6
1 2 99
 *
 *  output:
226
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, k, p[300010], w[300010];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    sort(p + 1, p + n + 1);
    sort(w + 1, w + m + 1);
    long long ans = 0;
    for (int i = 1, j = 1; i <= m; i++, j++) {
        while (p[j] < w[i]) {
            j++;
        }
        ans += 1ll * k * p[j];
    }
    cout << ans << endl;
    return 0;
}