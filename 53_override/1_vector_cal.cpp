/**
 * Description:
 *  给出一个点的坐标(x,y), 和n次运算操作, 操作分为以下3种:
 *  (1) 加法: + a b: 当前x坐标加a, y坐标加b
 *  (2) 减法: - a b: 当前x坐标减a, y坐标减b
 *  (3) 乘法: *k: 当前x坐标乘k, y坐标也k
 *  题目主程序已经给出, 使用运算符重载完成本题
 *
 * Input:
 *  第1行, 3个正整数n,x,y, 用空格分隔
 *  接下来n行, 每行代表一个操作
 *
 * Output:
 *  输出操作结束后的点(x,y), 用空格分隔
 *
 * Hints:
 *  1≤n≤50, 0≤x,y,a,b,k≤100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 0 0
+ 1 5
- 4 1
+ 2 2
 *
 *  output:
-1 6
 *
 *  2):
 *  input:
3 1 1
+ 4 2
- 2 1
* 100
 *
 *  output:
300 200
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct Point {
    int x, y;
    void read()
    {
        cin >> x >> y;
    }
    void print()
    {
        cout << x << ' ' << y << endl;
    }
};

// 在此重定义运算符
Point operator+(Point a, Point b)
{
    Point c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

Point operator-(Point a, Point b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

Point operator*(Point a, int k)
{
    Point c;
    c.x = a.x * k;
    c.y = a.y * k;
    return c;
}

int main()
{
    int n, k;
    char op;
    Point a, b;
    cin >> n;
    a.read();
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch (op) {
        case '+':
            b.read();
            a = a + b;
            break;
        case '-':
            b.read();
            a = a - b;
            break;
        case '*':
            cin >> k;
            a = a * k;
            break;
        }
    }
    a.print();
    return 0;
}