/**
 * Description:
 *  输入 n个数字 ai，输出这些数字的第 k 小的数。最小的数是第 0 小。
 *  请不要使用 nth_element 或者STL来写本题，因为本题的重点在于练习分治算法。
 *
 * Input:
 *  第一行两个整数n和k。
 *  第二行n个整数，表示ai
 *
 * Output:
 *  输出一个数字表示数组第 k 小的数。
 *
 * Hints:
 *  1≤n<5000000，1≤ai<10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 1
4 3 2 1 5
 *
 *  output:
2
 *
 */

#include <iostream>
using namespace std;
int n, k, a[5000010];

int quick_sort(int a[], int l, int r, int k)
{
    if (l >= r) {
        return a[l];
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
    if (j - l + 1 >= k) {
        return quick_sort(a, l, j, k);
    }
    return quick_sort(a, j + 1, r, k - (j - l + 1));
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << quick_sort(a, 1, n, k + 1) << endl;
    return 0;
}