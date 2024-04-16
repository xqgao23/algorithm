/**
 * Description:
 *  小K是一个海港的海关工作人员，每天都有许多船只到达海港，船上通常有很多来自不同国家的乘客。
 *  小K对这些到达海港的船只非常感兴趣，他按照时间记录下了到达海港的每一艘船只情况；对于第i艘到达的船，他记录了这艘船到达的时间ti（单位：秒），船上的乘
 * 客数ki，以及每名乘客的国籍xi,1, xi,2, …, xik.
 *  小K统计了n艘船的信息，希望你帮忙计算出以每一艘船到达时间为止的24小时(24小时=86400秒）内所有乘船到达的乘客来自多少个不同的国家。
 *  形式化地讲，你需要计算n条信息。对于输出的第i条信息，你需要统计满足ti−86400<tp<=ti的船只p，在所有的xp,j中，总共有多少个不同的数。
 *
 * Input:
 *  第一行输入一个正整数n，表示小K统计了n艘船的信息。
 *  接下来n行，每行描述一艘船的信息：前两个整数ti和ki分别表示这艘船到达海港的时间和船上的乘客数量，接下来ki个整数xij表示船上乘客的国籍。
 *  保证输入的ti是递增的，单位是秒；表示从小K第一次上班开始计时，这艘船在第ti秒到达海港。
 *
 * Output:
 *  输出n行，第i行输出一个整数表示第i艘船到达后的统计信息。
 *
 * Hints:
 *  1<=n<=10<5>, Eki <= 3*10<5>, 1<=x(i,j)<=10<5>, 1<=t(i-1)<=ti<=10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
1 4 4 1 2 2
2 2 2 3
10 1 3
 *
 *  output:
3
4
4
 *
 *  input:
4
1 4 1 2 2 3
3 2 2 3
86401 2 3 4
86402 1 5
 *
 *  output:
3
3
3
4
 *
 */

#include <iostream>
#include <queue>

using namespace std;
int n, t, k, x, f[100010], ans;
struct node {
    int t, g;
};
queue<node> q;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t >> k;
        while (q.size() && q.front().t <= t - 86400) {
            if (--f[q.front().g] == 0) {
                ans--;
            }
            q.pop();
        }
        for (int j = 1; j <= k; j++) {
            cin >> x;
            node temp = {t, x};
            q.push(temp);
            if (++f[x] == 1) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}