/**
 * Description:
 *  和所有人一样，奶牛喜欢变化。它们正在设想新造型的牧场。奶牛建筑师 Hei 想建造围有漂亮白色栅栏的三角形牧场。她拥有 n 块木板，每块的长度 li 都是整数，她想用所有的木板围成一个三角形使得牧场面积最大。
 *  请帮助 Hei 小姐构造这样的牧场，并计算出这个最大牧场的面积。
 *
 * Input:
 *  第 1 行：一个整数 n；
 *  第 2 到第 (n+1) 行，每行一个整数，第 (i+1) 行的整数 li 表示第 i 块木板的长度。
 *
 * Output:
 *  仅一个整数：最大牧场面积乘以 100 然后舍尾的结果。如果无法构建，输出 −1
 *
 * Hints:
 *  3≤n≤40，1≤li≤40
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

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, s, x[45], f[805][805], ans = -1;

bool check(int a, int b, int c)
{
    return f[a][b] && a + b > c && a + c > b && b + c > a;
}

int cal(int a, int b, int c)
{
    double p = (a + b + c) / 2.0;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s * 100;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        s += x[i];
    }
    f[0][0] = 1;
    for (int k = 1; k <= n; k++) {
        for (int i = s / 2; i >= 0; i--) {
            for (int j = s / 2; j >= 0; j--) {
                if (i >= x[k]) {
                    f[i][j] |= f[i - x[k]][j];
                }
                if (j >= x[k]) {
                    f[i][j] |= f[i][j - x[k]];
                }
            }
        }
    }
    for (int i = s / 2; i >= 0; i--) {
        for (int j = s / 2; j >= 0; j--) {
            if (check(i, j, s - i - j)) {
                ans = max(ans, cal(i, j, s - i - j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}