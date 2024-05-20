/**
 * Description:
 *  小杨的班级里共有 N名同学，学号从 0至 N−1。
 *  某节课上，老师安排全班同学进行一次握手游戏，具体规则如下：老师安排了一个顺序，让全班 N名同学依次进入教室。每位同学进入教室时，需要和 已经在教室内 且 学号小于自己 的同学握手。
 *  现在，小杨想知道，整个班级总共会进行多少次握手。
 *  提示：可以考虑使用归并排序进行降序排序，并在此过程中求解。
 *
 * Input:
 *  输入包含 2行。第一行一个整数 N，表示同学的个数；第二行 N个用单个空格隔开的整数，依次描述同学们进入教室的顺序，每个整数在 0 - N−1之间，表示该同学的学号。
 *  保证每位同学会且只会进入教室一次。
 *
 * Output:
 *  输出一行一个整数，表示全班握手的总次数。
 *
 * Hints:
 *  2≤N≤3*10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
2 1 3 0
 *
 *  output:
2
 *
 *  2):
 *  input:
6
0 1 2 3 4 5
 *
 *  output:
15
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
int n, a[300010], b[300010];

LL merge_sort(int a[], int l, int r)
{
    if (l >= r) {
        return 0;
    }
    int mid = (l + r) >> 1;
    LL cnt = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++], cnt += mid - i + 1;
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= r) {
        b[k++] = a[j++];
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
    cout << 1ll * n * (n - 1) / 2 - merge_sort(a, 1, n) << endl;
    return 0;
}