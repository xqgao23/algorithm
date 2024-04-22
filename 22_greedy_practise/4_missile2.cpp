/**
 * Description:
 *  经过 11年的韬光养晦，某国研发出了一种新的导弹拦截系统，凡是与它的距离不超过其工作半径的导弹都能够被它成功拦截。当工作半径为0时，则能够拦截与它位置恰好相同的导弹。但该导弹拦截系统也存在这样的缺陷：每套系统每天只能设定一次工作半径。而当天的使用代价，就是所有系统工作半径的平方和。
 *  某天，雷达捕捉到敌国的导弹来袭。由于该系统尚处于试验阶段，所以只有两套系统投入工作。如果现在的要求是拦截所有的导弹，请计算这一天的最小使用代价。
 *  两个点(x1,y1), (x2,y2)之间距离的平方是(x1 - x2)<2> + (y1 - y2)<2>
 *  两套系统工作半径r1, r2的平方和，是指r1, r2 分别取平方后再求和，即 r1<2> +
 * r2<2>
 *
 * Input:
 *  第一行包含 4个整数x1, y1, x2,
 * y2，每两个整数之间用一个空格隔开，表示这两套导弹拦截系统的坐标分别为(x1,y1),
 * (x2,y2)
 *  第二行包含1 个整数N，表示有 N颗导弹。接下来N行，每行两个整数 x,y，中间用
 * 一个空格隔开，表示一颗导弹的坐标(x,y)。不同导弹的坐标可能相同
 *
 * Output:
 *  一个整数，即当天的最小使用代价。
 *
 * Hints:
 *  1≤n≤100000, 且所有坐标分量的绝对值都不超过1000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
0 0 10 0
2
-3 3
10 0
 *
 *  output:
18
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 10;
struct node {
    int d1, d2;
} p[N];
int n, a1, b1, a2, b2, last_max[N];

bool cmp(node x, node y) { return x.d1 < y.d1; }

int main()
{
    cin >> a1 >> b1 >> a2 >> b2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        p[i].d1 = (a1 - x) * (a1 - x) + (b1 - y) * (b1 - y);
        p[i].d2 = (a2 - x) * (a2 - x) + (b2 - y) * (b2 - y);
    }
    
    sort(p + 1, p + n + 1, cmp);
    for (int i = n; i >= 1; i--) {
        last_max[i] = max(last_max[i + 1], p[i].d2);
    }
    
    int res = 2e9;
    for (int i = 0; i <= n; i++) {
        int r1 = p[i].d1;
        int r2 = last_max[i + 1];
        res = min(res, r1 + r2);
    }
    cout << res << endl;
    return 0;
}