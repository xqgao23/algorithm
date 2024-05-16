/**
 * Description:
 *  数轴上有 n 个城市，第 i 座城市的坐标为 xi。
 *  开始时小明位于坐标 X 位置，小明的目的是访问所有城市至少一次。他一开始会设定一个正整数 D，然后每次只可以向左或向右移动 D 个单位长度。移动次数没有任何限制。
 *  问小明要达成他的目的，D 的值最大可以设定为多少？
 *
 * Input:
 *  第 1 行，2 个正整数 n,X。
 *  第 2 行，n 个正整数x1,x2,...,xn.
 *
 * Output:
 *  输出 D 的最大值。
 *
 * Hints:
 *  1≤N≤10<5>, 1≤X≤10<9>,  1≤xi≤10<9>,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 3
1 7 11
 *
 *  output:
2
 *
 *  2):
 *  input:
3 81
33 105 57
 *
 *  output:
24
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int x, y;

    if (a > b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }

    if (y == 0) {
        return x;
    }

    while (true) {
        int t = x % y;
        if (t == 0) {
            return y;
        }
        x = y;
        y = t;
    }
}

int main()
{
    int n, x, ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        ans = gcd(ans, abs(x - t));
    }
    cout << ans << endl;
    return 0;
}