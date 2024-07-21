/**
 * Description:
 *  现在 absi2011 拿出了x 个迷你装药物（嗑药打人可耻…），准备开始与那些人打了。
 *  由于迷你装药物每个只能用一次，所以 absi2011 要谨慎的使用这些药。悲剧的是，用药量没达到最少打败该人所需的属性药药量，则打这个人必输。例如他用2 个药去打别人，别人却表明 3 个药才能打过，那么相当于你输了并且这两个属性药浪费了。
 *  现在有n 个好友，给定失败时可获得的经验、胜利时可获得的经验，打败他至少需要的药量。
 *  要求求出最大经验 s，输出 5s。
 *
 * Input:
 *  第一行两个数，n 和 x。
 *  后面n 行每行三个数，分别表示失败时获得的经验lose i ，胜利时获得的经验 win i和打过要至少使用的药数量 use i​
 *
 * Output:
 *  一个整数，最多获得的经验的五倍。
 *
 * Hints:
 *  对于100% 的数据，保证 0≤n,x≤10<3>, 0<lose i ≤win i≤10<6>，0≤use i≤10<3>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 8
21 52 1
21 70 5
21 48 2
14 38 3
14 36 1
14 36 2
 *
 *  output:
1060
 *
 */

#include <iostream>

using namespace std;

int w[1001], l[1001], u[1001];
long long dp[1001];

int main()
{
    int x, n;

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> w[i] >> u[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            if (u[i] <= j) {
                dp[j] = max(dp[j] + l[i], dp[j - u[i]] + w[i]);
            } else {
                dp[j] += l[i];
            }
        }
    }

    cout << 5ll * dp[x] << endl;

    return 0;
}