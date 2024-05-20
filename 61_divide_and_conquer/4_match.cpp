/**
 * Description:
 *  涵涵有两盒火柴，每盒装有 n 根火柴，每根火柴都有一个高度。 现在将每盒中的火柴各自排成一列， 同一列火柴的高度互不相同， 两列火柴之间的距离定义为：E(ai-bi)<2>其中 ai 表示第一列火柴中第 i 个火柴的高度，bi 表示第二列火柴中第 i 个火柴的高度。
 *  每列火柴中相邻两根火柴的位置都可以交换，请你通过交换使得两列火柴之间的距离最小。请问得到这个最小的距离，最少需要交换多少次？如果这个数字太大，请输出这个最小交换次数对 10<8>−3 取模的结果。
 *
 * Input:
 *  共三行，第一行包含一个整数 n，表示每盒中火柴的数目。
 *  第二行有 n 个整数，每两个整数之间用一个空格隔开，表示第一列火柴的高度。
 *  第三行有 n 个整数，每两个整数之间用一个空格隔开，表示第二列火柴的高度。
 *
 * Output:
 *  一个整数，表示最少交换次数对 10<8>−3 取模的结果。
 *
 * Hints:
 *  1≤n≤10<5>，0≤ 火柴高度 2<31>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
2 3 1 4
3 2 1 4
 *
 *  output:
1
 *
 *  2):
 *  input:
4
1 3 4 2
1 7 2 4
 *
 *  output:
2
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N], c[N], p[N], mod = 1e8 - 3;

void work(int a[])
{
    for (int i = 1; i <= n; i++) {
        p[i] = a[i];
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(p + 1, p + n + 1, a[i]) - p;
    }
}

int merge_sort(int a[], int l, int r)
{
    if (l >= r) {
        return 0;
    }
    int mid = (l + r) >> 1;
    int cnt = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if ((i <= mid && a[i] <= a[j]) || j > r) {
            p[k] = a[i++];
        } else {
            p[k] = a[j++], cnt = (cnt + mid - i + 1) % mod;
        }
    }
    for (int k = l; k <= r; k++) {
        a[k] = p[k];
    }
    return cnt;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    work(a), work(b);
    for (int i = 1; i <= n; i++) {
        c[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = c[b[i]];
    }
    cout << merge_sort(b, 1, n) << endl;
    return 0;
}