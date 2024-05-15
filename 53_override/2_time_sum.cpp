/**
 * Description:
 *  给出当前时刻H小时M分S秒, 我们要输出经过x小时y分z秒后的时刻. 用重载加法的方式完成
 *
 * Input:
 *  第1行三个整数H,M,S, 用空格分隔
 *  第2行三个整数为x,y,z, 用空格分隔
 *
 * Output:
 *  输出经过x小时y分z秒后的时刻
 *
 * Hints:
 *  0≤H,x≤10<9>, 0≤M,y≤59, 0≤S,z≤59
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
0 59 59
3 10 5
 *
 *  output:
4 10 4
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
// 在这里定义结构体, 重载运算符

struct Time {
    int h, m, s;
    void read()
    {
        cin >> h >> m >> s;
    }
    void print()
    {
        cout << h << " " << m << " " << s << endl;
    }
};

Time operator+(Time a, Time b)
{
    Time c;
    c.s = a.s + b.s;
    c.m = a.m + b.m;
    c.h = a.h + b.h;
    c.m += c.s / 60;
    c.s %= 60;
    c.h += c.m / 60;
    c.m %= 60;
    return c;
}

int main()
{
    Time t1, t2;
    t1.read();
    t2.read();
    t1 = t1 + t2;
    t1.print();
    return 0;
}