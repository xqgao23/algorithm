/**
 * Description:
 *  利用快速排序算法将读入的 N 个数从小到大排序后输出。
 *  快速排序是信息学竞赛的必备算法之一。对于快速排序不是很了解的同学可以自行上网查询相关资料，掌握后独立完成。（C++ 选手请不要试图使用 STL，虽然你可以使用 sort 一遍过，但是你并没有掌握快速排序算法的精髓。）
 *
 * Input:
 *  第 1 行为一个正整数 N，第 2 行包含 N 个空格隔开的正整数 ai，为你需要进行排序的数，数据保证了 ai 不超过 10<9>
 *
 * Output:
 *  将给定的 N 个数从小到大输出，数之间空格隔开，行末换行且无空格。
 *
 * Hints:
 *  N<=10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
4 2 4 5 1
 *
 *  output:
1 2 4 4 5
 *
 */

#include <iostream>
using namespace std;

int n, a[100010];

void quick_sort(int a[], int l, int r)
{
    if (l >= r) {
        return;
    }
    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j) {
        while (a[++i] < x)
            ;
        while (a[--j] > x)
            ;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}