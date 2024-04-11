/**
 * Description:
 *  Atcoder国新建成了一条铁路, 铁路沿东西方向, 沿线共有N站, 从西到东依次编号为1,2,⋯,N
 *  明天铁路将进行通车式, 所有列车都是从西向东运行, 并且只在相邻的站点之间有列车运行, 从第i站到第i+1站的列车全程需要花费Ci秒.
 *  第i站出发开往第i+1站的第一班列车在通车式开始后Si秒发车, 之后每过Fi秒发出一班列车(保证Si一定是Fi的倍数)
 *  如果不计换乘的时间, 请计算从第i站出发的乘客到达最后的第N站的时刻, 最早可能在通车式开始后多少秒.
 * 
 * Input:
 *  第一行一个正整数N
 *  接下来N−1行, 每行三个正整数Ci,Si,Fi
 * 
 * Output:
 *  输出N行, 第i行输出从第站出发的乘客到达第N站的最早时间.
 * 
 * Hints:
 *  1≤N≤500 1≤Ci≤100 1≤Si≤10<5> 1≤Fi≤100
 *  保证Si一定是Fi的倍数
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
3
6 5 1
1 10 2
 * 
 *  output:
13
11
0
 *
 *  2):
 *  input:
4
12 24 6
52 16 4
99 2 2
 * 
 *  output:
187
167
101
0
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, c[510], s[510], f[510];

int main()
{
    cin >> n;

    for (int i = 1; i < n; ++i) {
        cin >> c[i] >> s[i] >> f[i];
    }

    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = i; j < n; ++j) {//模拟每一辆始发车经过的每一个车站，到达终点站就结束了，所以终点站不用管
            if (ans < s[j]) {
                ans = s[j];
            }
            if (ans % f[j] != 0) {
                ans += f[j] - ans % f[j];
            }
            ans += c[j];
        }
        cout << ans << endl;
    }
    
    return 0;
}