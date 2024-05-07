/**
 * Description:
 *  给出一个数列a1,a2,..,an。 之后给出Q个数b1,b2,…,bQ，你需要对每个数bj，回答bj是否在数列a中。
 *
 * Input:
 *  第1行，两个正整数n，Q
 *  第2行，n个正整数a1,a2,..,an
 *  第3行，Q个正整数b1,b2,...,bQ
 *
 * Output:
 *  输出Q行，第j行代表bj是否在数列a中。
 *  如果在，输出"Yes"；如果不在，输出"No"
 *
 * Hints:
 *  1≤n,Q≤10<5>
 *  1≤ai,bi≤10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
6 5 1000000009 1 4008
7777 5 4008
 *
 *  output:
No
Yes
Yes
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int n, q;
LL a[100010], b;

LL search(int l, int r, LL x)
{
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return a[l];
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    while (q--) {
        cin >> b;
        if (search(1, n, b) == b) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}