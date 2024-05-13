/**
 * Description:
 *  Farmer John以及他的N(1≤N≤2,500)头奶牛打算过一条河，但他们所有的渡河工具，仅仅是一个木筏。 由于奶牛不会划船，在整个渡河过程中，FJ必须始终在木筏上。在这个基础上，木筏上的奶牛数目每增加1，FJ把木筏划到对岸就得花更多的时间。
 *  当FJ一个人坐在木筏上，他把木筏划到对岸需要M (1≤M≤1000)分钟。当木筏搭载的奶牛数目从i−1增加到i时，FJ得多花Mi(1≤Mi≤1000)分钟才能把木筏划过河（也就是说，船上有1头奶牛时，FJ得花M+M1分钟渡河；船上有2头奶牛时，时间就变成M+M1+M2分钟。后面的依此类推）。
 *  那么，FJ最少要花多少时间，才能把所有奶牛带到对岸呢？当然，这个时间得包括FJ一个人把木筏从对岸划回来接下一批的奶牛的时间。
 *
 * Input:
 *  第1行，两个正整数N,M
 *  接下来N行，每行一个正整数Mi
 *
 * Output:
 *  输出FJ所需的最小时间
 *
 * Hints:
 *  1≤M≤10<5>, 0≤N≤10, 0≤Di,ni≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 10
3
4
6
100
1
 *
 *  output:
50
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int n, m, s[3000], f[3000];
// f[i] 表示把 i 头牛带到对岸花费的最少时间

int main()
{
    cin >> n >> m;
    s[0] = m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        s[i] += s[i - 1] + x;
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i] = min(f[i], f[i - j] + s[j] + m);
        }
    }
    cout << f[n] - m << endl;
    return 0;
}