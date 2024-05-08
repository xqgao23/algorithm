/**
 * Description:
 *  给出一个n个数组成的数组a[1],a[2],⋯,a[n]。你需要处理Q次询问，每次询问包含两个正整数l,r(1≤l≤r≤n)，对每个询问，你需要回答和式a[l]+a[l+1]+⋯+a[r]的值。
 *
 * Input:
 *  第1行，1个正整数n。
 *  第2行，n个整数a[1],a[2],⋯,a[n]，以空格分隔。
 *  第3行，1个正整数Q。
 *  接下来Q行，每行两个正整数l,r。
 *
 * Output:
 *  输出Q行，第i行输出第i次询问的答案。
 *
 * Hints:
 *  n,Q≤10<5>；−1000≤a[i]≤1000；1≤l≤r≤n；
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
1 -6 5 -4 2 4
3
1 6
2 5
3 6
 *
 *  output:
2
-3
7
 *
 */
#include <iostream>

using namespace std;

int n, q, a[100010], s[100010];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}