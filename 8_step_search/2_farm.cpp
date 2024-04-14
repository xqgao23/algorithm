/**
 * Description:
 *  和所有人一样，奶牛喜欢变化。它们正在设想新造型的牧场。奶牛建筑师 Hei
 * 想建造围有漂亮白色栅栏的三角形牧场。她拥有 n 块木板，每块的长度 li都是整数，她想用所有的木板围成一个三角形使得牧场面积最大。
 *  请帮助 Hei 小姐构造这样的牧场，并计算出这个最大牧场的面积。
 *
 * Input:
 *  第1 行：一个整数n；
 *  第2 到第 (n+1) 行，每行一个整数，第 (i+1) 行的整数 li表示第 i 块木板的长度。
 *
 * Output:
 *  仅一个整数：最大牧场面积乘以100 然后舍尾的结果。如果无法构建，输出−1。
 *
 * Hints:
 *  3≤n≤12, 1≤li≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
1
1
3
3
4
 *
 *  output:
692
 *
 */

#include <cmath>
#include <iostream>
using namespace std;
int n, l[25], p[25];
long long ans = -1;

long long Heron(int a, int b, int c)
{
    double p = (a + b + c) / 2.0;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s * 100;
}

void dfs(int step)
{
    if (step > n) {
        int a = 0, b = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] == 1) {
                a += l[i];
            }
            if (p[i] == 2) {
                b += l[i];
            }
            if (p[i] == 3) {
                c += l[i];
            }
        }
        if (a + b > c && b + c > a && a + c > b) {
            ans = max(ans, Heron(a, b, c));
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        p[step] = i;
        dfs(step + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}