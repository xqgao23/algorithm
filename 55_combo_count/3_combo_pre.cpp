/**
 * Description:
 *  读入一个正整数n,请编程打印一个n行的杨辉三角。杨辉三角中的数会很大，你只需要输出它们除以 10<9>+7 的余数。
 *
 * Input:
 *  一个正整数 n<=2000
 *
 * Output:
 *  n层杨辉三角
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
 *
 *  output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
 *
 */

#include <iostream>
using namespace std;
int n, comb[2005][2005], mod = 1e9 + 7;

void init()
{
    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
        }
    }
}

int main()
{
    cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << comb[i][j] <<  " ";
        }
        cout << endl;
    }
    return 0;
}