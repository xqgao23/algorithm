/**
 * Description:
 *  给出一个长为N的字符串S，字符串只包含ACGT四种字符。你需要回答Q次询问，第i次询问如下:
 *  第i次询问包含两个正整数li, ri, (1<=li < ri <=
 * N)。你需要回答从第li个到第ri个字符构成的字符串中，包含多少个子串"AC"？
 *
 * Input:
 *  第1行，2个正整数N,Q
 *  第2行，1个字符串S
 *  接下来Q行，每行两个正整数li, ri.
 *
 * Output:
 *  输出Q行，第i行输出第i次询问的答案。
 *
 * Hints:
 *  2<=N<=10<5>, 1<=Q<=10<5>
 */

/**
 *  Samples:
 *  1):
 *  input:
8 3
ACACTACG
3 7
2 3
1 8
 *
 *  output:
2
0
3
 *
 */

#include <iostream>
using namespace std;
int n, q, c[100010];
string s;
int main()
{
    cin >> n >> q >> s;
    s = ' ' + s;
    for (int i = 2; i <= n; i++) {
        c[i] = c[i - 1];
        if (s[i - 1] == 'A' && s[i] == 'C') {
            c[i]++;
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << c[r] - c[l] << endl;
    }
    return 0;
}