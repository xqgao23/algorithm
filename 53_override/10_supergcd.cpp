/**
 * Description:
 *  《九章算术》是中国古代的数学专著，其中的"更相减损术"可以用来求两个数的最大公约数，原文是： 可半者半之，不可半者，副置分母、子之数，以少减多，更相减损，求其等也。以等数约之。
 *  具体做法是：
 *  第一步：任意给定两个正整数；判断它们是否都是偶数。若是，则用2约简；直到有一个不是偶数为止。 进入第二步。
 *  第二步：如果有一个偶数，则用2约简，直到变成奇数为止。 进入第三步。
 *  第三步：以较大的数减较小的数，此时一定变成一奇一偶。 如果那个偶数不是0，回到第二步。
 *  如果第三步得到的偶数是0，则第一步中约掉的若干个2的积与第三步中最后等到的奇数的乘积就是所求的最大公约数。
 *  输入两个很大的正整数a 和 b。 使用更相减损术，计算两个数的最大公约数
 *
 * Input:
 *  共两行，第一行一个整数 a，第二行一个整数 b。
 *
 * Output:
 *  一行，表示 a 和 b 的最大公约数
 *
 * Hints:
 *  0≤a,b≤10<10000>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
12
54
 *
 *  output:
6
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

int operator%(BIG a, int b)
{
    // return a.num[1] % 2;
    int r = 0;
    for (int i = a.len; i >= 1; i--) {
        r = r * 10 + a.num[i];
        r %= b;
    }
    return r;
}

string sa, sb;
BIG a, b;
int c;

int main()
{
    cin >> sa >> sb;
    a.s2BIG(sa);
    b.s2BIG(sb);
    while (a % 2 == 0 && b % 2 == 0) {
        c++;
        a = a / 2;
        b = b / 2;
    }
    while (1) {
        while (a % 2 == 0) {
            a = a / 2;
        }
        while (b % 2 == 0) {
            b = b / 2;
        }
        if (a < b) {
            b = b - a;
        } else if (b < a) {
            a = a - b;
        } else {
            break;
        }
    }
    while (c--) {
        a = a * 2;
    }
    a.print();
    return 0;
}