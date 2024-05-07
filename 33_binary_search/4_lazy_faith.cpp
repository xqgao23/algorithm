/**
 * Description:
 *  一条东西向的道路有A家书店和B家花店。以道路最西面为坐标0点，第i家书店位于坐标si，第j家花店位于坐标tj处。
 *  你需要回答以下Q个询问：
 *  问k：从坐标xk出发，要至少访问一家书店和一家花店，最少需要移动多少距离？
 *
 * Input:
 *  第1行，3个正整数A,B,Q
 *  第2行，A个正整数s1,s2,...,sA
 *  第3行，B个正整数t1,t2,...,tB
 *  第4行，Q个正整数x1,x2,...,xQ
 *
 * Output:
 *  输出Q行，第k行输出第k次询问的答案。
 *
 * Hints:
 *  1≤A,B,Q≤10<5>
 *  1≤si,tj,xk≤10<10>, si,tj,xk都互不相同
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 3 4
100 600
400 900 1000
150 2000 899 799
 *
 *  output:
350
1400
301
399
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int A, B, Q;
LL s[100010], t[100010], x;

int main()
{
    cin >> A >> B >> Q;
    for (int i = 1; i <= A; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= B; i++) {
        cin >> t[i];
    }
    sort(s + 1, s + A + 1);
    sort(t + 1, t + B + 1);
    while (Q--) {
        cin >> x;
        int pos_s = lower_bound(s + 1, s + A + 1, x) - s;
        int pos_t = lower_bound(t + 1, t + B + 1, x) - t;
        LL ans = 1e18;

        if (pos_s <= A && pos_t <= B) {
            ans = min(ans, max(s[pos_s], t[pos_t]) - x);
        }
        if (pos_s - 1 >= 1 && pos_t - 1 >= 1) {
            ans = min(ans, x - min(s[pos_s - 1], t[pos_t - 1]));
        }
        if (pos_s - 1 >= 1 && pos_t <= B) {
            ans = min(ans, min(x - s[pos_s - 1], t[pos_t] - x) + t[pos_t] -
                               s[pos_s - 1]);
        }
        if (pos_s <= A && pos_t - 1 >= 1) {
            ans = min(ans, min(x - t[pos_t - 1], s[pos_s] - x) + s[pos_s] -
                               t[pos_t - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}