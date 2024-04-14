/**
 * Description:
 *  写一个递归函数 int gcd(int a, int b), 递归求a,b 的最大公约数
 *
 * Input:
 *  两个整数a,b, 用空格分隔
 *
 * Output:
 *  一个整数, a,b的最大公约数
 *
 * Hints:
 *  1<=a,b<=10<9>
 */

/**
 *  Samples:
 *  1):
 *  input:
12 54
 *
 *  output:
6
 *
 */

#include <iostream>

using namespace std;
// 在此定义函数
int gcd(int x, int y)
{
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}