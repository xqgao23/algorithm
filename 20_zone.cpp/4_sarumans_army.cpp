/**
 * Description:
 *  白袍巫师萨鲁曼需要指挥他的军队前往圣盔谷.
 * 士兵们在行军过程中的队形是长长的一列,
 * 萨鲁曼需要在士兵中选出若干名任命为传令官,
 * 传令官只能将命令传到与自己距离不超过R的范围
 * (如果R=0,则命令只能传到和自己位置相同的士兵).
 * 萨鲁曼需要保证每位士兵都能听到命令, 并且任命的传令官越少越好.
 * 输入士兵人数n和每位士兵的位置xi, 输出所需的传令官的最少人数.
 *
 * Input:
 *  输入第一行包含两个正整数R和n分别代表半径和军队人数
 *  输入第二行包含n个正整数x1,x2,…,xn, 代表每位士兵的位置.
 *
 * Output:
 *  输出所需的传令官的最少人数.
 *
 * Hints:
 *  1≤n≤1000, 0<=R<=1000, 0<=xi<=1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
0 3
10 20 20
 *
 *  output:
2
 *
 *  2):
 *  input:
10 7
70 30 1 7 15 20 50
 *
 *  output:
4
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int R, n, x[1010];

int main()
{
    cin >> R >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    int last = -1e9, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (last + R < x[i]) {
            for (int j = i; j <= n; j++) {
                if (x[j] <= x[i] + R) {
                    last = x[j];
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}