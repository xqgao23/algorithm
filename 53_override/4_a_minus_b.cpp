/**
 * Description:
 *  输入两个正整数a和b, 计算 ∣a−b∣的值并输出
 *
 * Input:
 *  两行 , 每行一个正整数 , 分别代表a和b
 *
 * Output:
 *  一行 , 输出|a-b|的结果
 *
 * Hints:
 *  1≤a,b≤10<1000>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
999999999999999999999999999
187654321987654321987654321
 *
 *  output:
812345678012345678012345678
 *
 *  2):
 *  input:
1
1000000000000000000000000
 *
 *  output:
999999999999999999999999
 *
 *  3):
 *  input:
7777777777777777777777777
7777777777777777777777779
 *
 *  output:
2
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

BIG operator-(BIG a, BIG b)
{
    BIG c;
    int len = max(a.len, b.len), u = 0;
    for (int i = 1; i <= len; i++) {
        int t = a.num[i] - u;
        if (i <= b.len) {
            t -= b.num[i];
        }
        if (t < 0) {
            u = 1;
            c.num[i] = t + 10;
        } else {
            u = 0;
            c.num[i] = t;
        }
    }
    while (c.num[len] == 0 && len > 1) {
        len--;
    }
    c.len = len;
    return c;
}

bool operator<(BIG a, BIG b)
{
    if (a.len != b.len) {
        return a.len < b.len;
    }
    for (int i = a.len; i >= 1; i--) {
        if (a.num[i] != b.num[i]) {
            return a.num[i] < b.num[i];
        }
    }
    return false;
}

string sa, sb;
BIG a, b, c;

int main()
{
    cin >> sa >> sb;
    a.s2BIG(sa);
    b.s2BIG(sb);
    if (a < b) {
        c = b - a;
    } else {
        c = a - b;
    }
    c.print();
    return 0;
}