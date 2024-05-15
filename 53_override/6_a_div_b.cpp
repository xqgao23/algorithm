/**
 * Description:
 *  输入两个正整数a和b, 计算a/b的值并输出
 *
 * Input:
 *  两行 , 每行一个正整数 , 分别代表a和b
 *
 * Output:
 *  一行 , 输出a/b的结果
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
9
 *
 *  output:
111111111111111111111111
 *
 *  2):
 *  input:
1634254846899862270311363684648
112233
 *
 *  output:
14561268494113694459841256
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

BIG operator/(BIG a, int b)
{
    BIG c;
    int len = a.len;
    int r = 0;
    for (int i = len; i >= 1; i--) {
        int t = r * 10 + a.num[i];
        c.num[i] = t / b;
        r = t % b;
    }
    while (c.num[len] == 0 && len > 1) {
        len--;
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
    c = a / b;
    c.print();
    return 0;
}