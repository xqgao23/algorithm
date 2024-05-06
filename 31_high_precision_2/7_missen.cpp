/**
 * Description:
 *  形如2<P>−1的素数称为麦森数，这时P一定也是个素数。但反过来不一定，即如果P是个素数，2<P>−1不一定也是素数。到1998年底，人们已找到了37个麦森数。最大的一个是P=3021377，它有909526位。麦森数有许多重要应用，它与完全数密切相关。
 *  输入P（1000<P<3100000），计算2<P>−1的位数和最后500位数字（用十进制高精度数表示）
 *
 * Input:
 *  一个整数P（1000<P<3100000）
 *
 * Output:
 *  第1行：十进制高精度数2<P>−1的位数。
 *  第2-11行：十进制高精度数2<P>−1的最后500位数字。（每行输出50位，共输出10行，不足500位时高位补0）
 *  不必验证2<P>−1与P是否为素数。
 *
 * Hints:
 *  0≤m≤n≤200,保证输出不超过1000位
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
1279
 *
 *  output:
386
00000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000000000000000
00000000000000104079321946643990819252403273640855
38615262247266704805319112350403608059673360298012
23944173232418484242161395428100779138356624832346
49081399066056773207629241295093892203457731833496
61583550472959420547689811211693677147548478866962
50138443826029173234888531116082853841658502825560
46662248318909188018470682222031405210266984354887
32958028878050869736186900714720710555703168729087
 *
 */

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

void s2BIG(string s, int a[])
{ // 高精度输入
    int lena = s.size();
    for (int i = 1; i <= lena; i++) {
        a[i] = s[lena - i] - '0';
    }
    a[0] = lena;
}

void printBIG(int a[])
{ // 高精度输出
    int lena = a[0];
    for (int i = lena; i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
}

// 高精*单精
void mulBIG(int a[], int b, int c[])
{
    int lenc = a[0], u = 0;
    for (int i = 1; i <= lenc; i++) {
        int t = a[i] * b + u;
        c[i] = t % 10;
        u = t / 10;
    }
    while (u > 0 && lenc <= 500) {
        c[++lenc] = u % 10;
        u /= 10;
    }
    c[0] = lenc;
}

int p, x[1010], a[1010];

int main()
{
    int p;
    cin >> p;
    cout << int(p * log10(2)) + 1 << endl;
    s2BIG("1", x);
    for (int i = 1; i <= p / 20; i++) {
        mulBIG(x, 1048576, x);
    }
    for (int i = 1; i <= p % 20; i++) {
        mulBIG(x, 2, x);
    }
    x[1]--;
    for (int i = 500; i >= 1; i--) {
        cout << x[i];
        if (i % 50 == 1) {
            cout << endl;
        }
    }
    return 0;
}