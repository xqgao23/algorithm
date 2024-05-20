/**
 * Description:
 *  对于一个包含N个非负整数的数组A[1..n]，如果有i<j，且A[i]>A[j]，则称(A[i],A[j])为数组A中的一个逆序对。
 *  例如，数组(3，1，4，5，2)的逆序对有(3,1),(3,2),(4,2),(5,2)，共4个。
 *  给定一个数组，求该数组中包含多少个逆序对。
 *
 * Input:
 *  第一行，一个数n，表示数组中有n个数。
 *  第二行n个数，表示给定的数组。数组中每个数字不超过10<9>
 *
 * Output:
 *  输出数组中逆序对的数目。
 *
 * Hints:
 *  n<500000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
5 4 2 6 3 1
 *
 *  output:
11
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
int n, a[500010], b[500010];

LL merge_sort(int a[], int l, int r)
{
    if (l >= r) {
        return 0;
    }
    int mid = (l + r) >> 1;
    LL cnt = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if ((i <= mid && a[i] <= a[j]) || j > r) {
            b[k] = a[i++];
        } else {
            b[k] = a[j++], cnt += mid - i + 1;
        }
    }
    for (int k = l; k <= r; k++) {
        a[k] = b[k];
    }
    return cnt;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << merge_sort(a, 1, n) << endl;
    return 0;
}