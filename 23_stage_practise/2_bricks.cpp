/**
 * Description:
 *  有N个砖块排成一排，左起第i个砖块上写着整数ai。你可以选择不超过N−1个任意砖块打碎，从而剩下K个砖块，并且剩下的砖块上写的数字恰好从左到右是1∼K。
 *  注意，不能改变砖块的原始顺序，即要使得打碎之后剩余的砖块上的数字，从左到右恰好是1∼K。
 *  为了满足要求，最少需要打碎多少个砖块。如果不可能满足要求，输出 −1。
 *
 * Input:
 *  第1行，一个正整数N。
 *  第2行，N个正整数a1, a2, ..., aN.
 *
 * Output:
 *  最少需要打碎的砖块数量；如果不能满足要求，输出-1
 *
 * Hints:
 *  1<=N<=200000, 1<=ai<=N
 */

/**
 *  Samples:
 *  1):
 *  input:
3
2 1 2
 *
 *  output:
1
 *
 *  2):
 *  input:
3
2 2 2
 *
 *  output:
-1
 *
 *  3):
 *  input:
10
3 1 4 1 5 9 2 6 5 3
 *
 *  output:
7
 *
 */

#include <iostream>
using namespace std;
int n, a[200010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == k) {
            k++;
        }
    }
    if (k == 1) {
        cout << -1 << endl;
    } else {
        cout << n - k + 1 << endl;
    }
    return 0;
}