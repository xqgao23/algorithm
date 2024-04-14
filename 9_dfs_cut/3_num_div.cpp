/**
 * Description:
 *  你将得到一个整数n,请列出把整数n划分为若干个正整数的每一种方法.
 * 这些正整数必须选自数组a
 *  数组a中可能有重复元素，每个可以选择一次，例如对n=6,a={1,1,2,2,3,4},n=1+1+2+2是可以的，数组a中有2个1和2个2可供选择;n=2+2+2则不正确，因为数组a中没有3个2.
 *
 * Input:
 *  输入共2行;
 *  第1行，2个正整数n,k.k为数组a的元素个数;
 *  第2行，k个用空格隔开的正整数a0,a1,…,an为数组a中的元素;
 *
 * Output:
 *  输出为若干行:
 *  每行为用空格隔开的若干个正整数，为一种n划分为k个数的方法，每组数按a中下标从小到大输出.
 *  若两种方法中前k−1个数在a中的下标相同，则第k个数的下标更小的在前.
 *  如果两种方法选取的数在a中的下标不全相同，则视为不同的方法.
 * 例如对n=6,a={1,1,2,2,3,4},选取a的0,2,4或0,3,4号元素都会得到n=1+2+3,两者都要在合适的位置分别输出.
 *
 * Hints:
 *  1≤n,a0,a1,...,an<= 10<9>, 1≤k≤n≤20
 */

/**
 *  Samples:
 *  1):
 *  input:
6 6
1 1 2 2 3 4
 *
 *  output:
1 1 2 2
1 1 4
1 2 3
1 2 3
1 2 3
1 2 3
2 4
2 4
 *
 */

#include <iostream>
using namespace std;
int n, k, a[30], p[30];

void dfs(int step, int sum)
{
    if (sum == n) {
        for (int i = 1; i <= step - 1; i++) {
            cout << a[p[i]] << " ";
        }
        cout << endl;
        return;
    }
    if (step > k || sum > n) {
        return;
    }
    for (int i = p[step - 1] + 1; i <= k; i++) {
        p[step] = i;
        dfs(step + 1, sum + a[i]);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    p[0] = 0;
    dfs(1, 0);
    return 0;
}