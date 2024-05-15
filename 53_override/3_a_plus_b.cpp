/**
 * Description:
 *  输入两个正整数 a 和 b, 计算 a+b 的值并输出
 *
 * Input:
 *  两行 , 每行一个正整数 , 分别代表 a和b
 *
 * Output:
 *  一行 , 输出 a+b 的结果
 *
 * Hints:
 *  1≤a,b≤10<1000>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
999999999999999999999999
1
 *
 *  output:
1000000000000000000000000
 *
 *  2):
 *  input:
14561268494113694459841256
98745632145555569812221111
 *
 *  output:
113306900639669264272062367
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;

struct BIG {
    int len, num[1010];
    void s2BIG(string s)
    {
        len = s.size();
        for (int i = 1; i <= len; i++) {
            num[i] = s[len - i] - '0';
        }
    }
    void print()
    {
        for (int i = len; i >= 1; i--) {
            cout << num[i];
        }
        cout << endl;
    }
};

BIG operator+(BIG a, BIG b)
{
    BIG c;
    int len = max(a.len, b.len), u = 0;
    for (int i = 1; i <= len; i++) {
        int t = u;
        if (i <= a.len) {
            t += a.num[i];
        }
        if (i <= b.len) {
            t += b.num[i];
        }
        c.num[i] = t % 10;
        u = t / 10;
    }
    if (u > 0) {
        c.num[++len] = u;
    }
    c.len = len;
    return c;
}

string sa, sb;
BIG a, b, c;

int main()
{
    cin >> sa >> sb;
    a.s2BIG(sa);
    b.s2BIG(sb);
    c = a + b;
    c.print();
    return 0;
}