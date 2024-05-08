/**
 * Description:
 *  给出一个数字n，我们按照如下规则把它翻译为字符串：0 翻译成 "a" ，1 翻译成 "b"，......，11 翻译成 "l"，......，25 翻译成 "z"。一个数字可能有多个翻译。请编程计算一个数字有多少种不同的翻译方法。
 *  例如102040有4种不同的翻译方法：分别是"bacaea", "bauea", "kcaea"和"kuea"。
 *
 * Input:
 *  1行,整数n
 *
 * Output:
 *  一个整数，翻译方法数
 *
 * Hints:
 *  0≤n≤10<50>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
102040
 *
 *  output:
4
 *
 *  2):
 *  input:
12258
 *
 *  output:
5
 *
 */

#include <iostream>
#include <string>

using namespace std;

string s;
int f[55];

int main()
{
    cin >> s;
    int n = s.size();
    s = " " + s;
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
        
        if (i > 1 && 10 <= x && x <= 25) {
            f[i] += f[i - 2];
        }
    }
    cout << f[n] << endl;

    return 0;
}