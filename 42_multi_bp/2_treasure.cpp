/**
 * Description:
 *  终于，破解了千年的难题。小 FF 找到了王室的宝物室，里面堆满了无数价值连城的宝物。
 *  这下小 FF 可发财了。但是这里的宝物实在是太多了，小 FF 的采集车似乎装不下那么多宝物。看来小 FF 只能含泪舍弃其中的一部分宝物了。
 *  小 FF 对洞穴里的宝物进行了整理，他发现每样宝物都有一件或者多件。他粗略估算了下每样宝物的价值，之后开始了宝物筛选工作：小 FF 有一个最大载重为 W 的采集车，洞穴里总共有 n 种宝物，每种宝物的价值为 vi，重量为 wi，每种宝物有 mi 件。小 FF 希望在采集车不超载的前提下，选择一些宝物装进采集车，使得它们的价值和最大。
 *
 * Input:
 *  第一行为一个整数 n 和 W，分别表示宝物种数和采集车的最大载重。
 *  接下来 n 行每行三个整数vi,wi,mi
 *
 * Output:
 *  输出仅一个整数，表示在采集车不超载的情况下收集的宝物的最大价值。
 *
 * Hints:
 *  n≤∑mi≤10<5>, 0≤W≤4*10<4>, 1≤vi,wi≤4*1000, 1≤n≤100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 20
3 9 3
5 9 1
9 4 2
8 1 3
 *
 *  output:
47
 *
 */

#include<iostream>
#include<algorithm>

using namespace std;

int W, N, w[2010], v[2010], f[40010], n;

int main()
{
    cin >> N >> W;
    
    for (int i = 1; i <= N; i++) {
        int a, b, c, s = 1;
        cin >> a >> b >> c;
        
        while (s <= c) {
            w[++n] = b * s;
            v[n] = a * s;
            c -= s;
            s *= 2;
        }
        if (c > 0) {
            w[++n] = b * c;
            v[n] = a * c;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    
    cout << f[W] << endl;
    
    return 0;
}