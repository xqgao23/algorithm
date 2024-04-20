/**
 * Description:
 *  有n个蜡烛，它们的颜色各种各样，我们用1∼10<9>的一个整数表示每根蜡烛的颜色，第i根蜡烛的颜色是ci。蜡烛按照1∼n顺序排成一行。
 *  高桥想要拿走连续k根蜡烛，并且要使得拿走的蜡烛颜色种类最多。他最多可以拿走多少种颜色的蜡烛？
 *
 * Input:
 *  第1行，2个正整数n,k
 *  第2行，n个正整数c1,c2,...,cn
 *
 * Output:
 *  输出能拿走的最多颜色
 *
 * Hints:
 *  1<=k<=n<=3*10<5>, 1<=ci<=10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
7 3
1 2 1 2 3 3 3
 *
 *  output:
3
 *
 *  2):
 *  input:
5 5
4 4 4 4 4
 *
 *  output:
1
 *
 */

#include <iostream>
#include <map>
using namespace std;
const int N = 3e5 + 10;
int n, k, c[N];
map<int, int> mp;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        mp[c[i]]++;
        if (i >= k) {
            ans = max(ans, (int)mp.size());
            mp[c[i - k + 1]]--;
            if (mp[c[i - k + 1]] == 0) {
                mp.erase(c[i - k + 1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}