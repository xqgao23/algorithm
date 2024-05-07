/**
 * Description:
 *  对于给定的一个长度为N的正整数数列A，现要将其分成M段，并要求每段连续，且每段和的最大值最小。
 *  例如，将数列4 2 4 5 1要分成3段：
 *  若分为[4 2][4 5][1]，各段的和分别为6,9,1，和的最大值为9；
 *  若分为[4][2 4][5 1]，各段的和分别为4,6,6，和的最大值为6；
 *  并且无论如何分段，最大值不会小于6。
 *  所以可以得到要将数列[4 2][4 5][1]分成3段，每段和的最大值最小为6。
 *
 * Input:
 *  第1行包含两个正整数N，M；
 *  第2行包含N个空格隔开的非负整数Ai，含义如题目所述。
 *
 * Output:
 *  仅包含一个正整数，即每段和最大值最小为多少。
 *
 * Hints:
 *  N≤10<5>, M≤N, Ai之和不超过10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
4 2 4 5 1
 *
 *  output:
6
 *
 */

#include <iostream>
using namespace std;
int n, m, a[100010];

bool check(int x)
{
    int sum = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) {
            return false;
        }
        if (sum + a[i] > x) {
            cnt++;
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    return cnt <= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1e9, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}