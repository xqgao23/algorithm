/**
 * Description:
 *  输入两个正整数a和b, 计算a*b的值并输出
 *
 * Input:
 *  两行 , 每行一个正整数 , 分别代表a和b
 *
 * Output:
 *  一行 , 输出a*b的结果
 *
 * Hints:
 *  1≤a≤10<1000>, 1≤b≤10<9>
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
999999999999999999999999
 *
 *  2):
 *  input:
14561268494113694459841256
112233
 *
 *  output:
1634254846899862270311363684648
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

BIG operator*(BIG a, int b)
{
    BIG c;
    int len = a.len, u = 0;
    for (int i = 1; i <= len; i++) {
        int t = a.num[i] * b + u;
        c.num[i] = t % 10;
        u = t / 10;
    }
    while (u > 0) {
        c.num[++len] = u % 10;
        u /= 10;
    }
    c.len = len;
    return c;
}

string sa, sb;
BIG a, c;
int b;

int main()
{
    cin >> sa >> b;
    a.s2BIG(sa);
    c = a * b;
    c.print();
    return 0;
}