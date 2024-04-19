/**
 * Description:
 *  Polycarp非常喜欢等比数列，尤其喜欢长度为3的等比数列。
 *  他想知道对于一个给定长度n的数列a和公比q，a中有多少个长度为3的子序列是以q为公比的等比数列。
 *  ai,aj,ak是一个公比为q的等比数列是指ak=q×aj且aj=q×ai
 *  你要找出使得ai,aj,ak是一个公比为q的等比数列的三元组(i,j,k)的个数，且要保证1≤i<j<k≤n。
 *
 * Input:
 *  第一行两个整数n(1≤n≤2×10<5>)和q(−1×10<3>≤q≤1×10<3>,q!=0)。
 *  第二行n个整数表示ai(−10<9>≤ai≤10<9>, ai!=0)，ai表示给定数列的第i项。
 *
 * Output:
 *  输出一个整数，表示a中有多少个不同的以q为公比，长度为3的子序列。
 *
 * Hints:
 *  1<=n<=1000; 1<=a<=10<6>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 2
1 2 4 2 4
 *
 *  output:
3
 *
 *  2):
 *  input:
3 1
1 1 1
 *
 *  output:
1
 *
 *  3):
 *  input:
10 3
1 2 6 2 3 6 9 18 3 9
 *
 *  output:
6
 *
 */

#include <iostream>
#include <map>
using namespace std;
int n, q, a[200010];
map<int, int> cnt1, cnt2;

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cnt1[a[1]] = 1;
    for (int i = 3; i <= n; i++) {
        cnt2[a[i]]++;
    }
    long long ans = 0;
    for (int j = 2; j <= n; j++) {
        int ai = a[j] / q, ak = a[j] * q;
        if (a[j] % q == 0 && cnt1.count(ai) && cnt2.count(ak)) {
            ans += cnt1[ai] * cnt2[ak];
        }
        cnt1[a[j]]++;
        cnt2[a[j + 1]]--;
    }
    cout << ans << endl;
    return 0;
}