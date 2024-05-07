/**
 * Description:
 *  给出两个数组x1,x2,…,xn;y1,y2,…,yn.
 * 给出一个整数k，每次从两个数组中各自取出一个数xi和yj，要求满足xi+yj=k。
 *  已经取出过的数不能再取，问最多可以取出几对数？
 *
 * Input:
 *  输入共 3 行;
 *  第 1 行，2个正整数 n,k;
 *  第 2 行，用空格隔开的n个正整数x1,x2,...,xn;
 *  第 3 行，用空格隔开的n个正整数y1,y2,...,yn;
 *
 * Output:
 *  输出共 1 行;
 *  第 1 行，一个正整数c,表示最多能取出多少组数.
 *
 * Hints:
 *  1≤n≤2000000, 1≤k≤10<9>,
 *  1≤xi,yi≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 22
1 2 3 4 5 6 7 8 9 10
12 12 12 12 12 12 14 16 18 20
 *
 *  output:
5
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, d, x[200010], y[200010], cnt;

int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        y[i] = d - y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    int l = 1;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(y + l, y + n + 1, x[i]) - y;
        if (y[pos] == x[i]) {
            cnt++;
            l = pos + 1;
        }
    }
    cout << cnt << endl;
    return 0;
}