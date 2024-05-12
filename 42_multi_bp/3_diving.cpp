/**
 * Description:
 *  Marsha 和 Bill 拥有一些玻璃珠。每个玻璃珠具有它自己的价值，Marsha 和 Bill 将每个玻璃珠的价值量化为1到6的一个整数。他们二人想要把所有玻璃珠分成价值恰好相等的两份，问能否做到？
 *
 * Input:
 *  输入包含多组测试数据
 *  第一行，1个正整数T，表示有T组数据。
 *  接下来T行，每行表示一组测试数据。
 *  每行包括6个整数，分别代表了价值从1到6的玻璃珠的个数。
 *
 * Output:
 *  对第k组数据，输出2行：
 *  第1行："Collection #k:"，k是测试数据在输入中的次序
 *  第2行：如果可以分成价值恰好相等的两份，输出"Can be divided."；否则输出"Can't be divided."。
 *
 * Hints:
 *  1≤T≤10, 对于每组数据，玻璃珠总数不超过20000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
1 0 1 2 0 0
1 0 0 0 1 1
 *
 *  output:
Collection #1:
Can't be divided.
Collection #2:
Can be divided.
 *
 */

#include<iostream>
#include<cstring>

using namespace std;

int t, c[72], f[200010];

int main()
{
    cin >> t;
    
    for (int r = 1; r <= t; r++) {
        printf("Collection #%d:\n", r);
        int sum = 0, n = 0;
        
        for (int i = 1; i <= 6; i++) {
            int x, s = 1;
            cin >> x;
            sum += x * i;
            while (s <= x) {
                c[++n] = s * i;
                x -= s;
                s *= 2;
            }
            if (x > 0) {
                c[++n] = x * i;
            }
        }
        if (sum & 1) {
            cout << "Can't be divided." << endl;
            continue;
        }
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = sum/2; j >= c[i]; j--) {
                f[j] |= f[j - c[i]];
            }
        }
        if (f[sum/2]) {
            cout << "Can be divided." << endl;
        } else {
            cout << "Can't be divided." << endl;
        }
    }
    
    return 0;
}