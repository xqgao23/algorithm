/**
 * Description:
 *  给出一个数列a1,a2,..,an。
 * 之后给出Q个数d1,d2,…,dQ，你需要对每个数dj，回答是否存在一个i，使得ai=i+dj
 *
 * Input:
 *  第1行，两个正整数n，Q
 *  第2行，n个正整数a1,a2,..,an
 *  第3行，Q个正整数d1,d2,...,dQ
 *
 * Output:
 *  输出Q行，第j行代表对每个数dj是否存在一个i，使得ai=i+dj
 *  如果在，输出"Yes"；如果不在，输出"No"
 *
 * Hints:
 *  1≤n,Q≤10<5>
 *  -10<18>≤ai,dj≤10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
6 5 1000000009 1 4008
5 4008 -3
 *
 *  output:
Yes
No
Yes
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int n, q;
LL a[100010], d;

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
        a[i] -= i;
    }
    sort(a + 1, a + n + 1);
    while (q--) {
        cin >> d;
        if (search(1, n, d) == d) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}