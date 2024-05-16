/**
 * Description:
 *  高桥君在做一道数学题, 答案是两个不超过N的正整数(a,b). 高桥君只知道a除以b的余数大于等于K.
 *  满足条件的正整数二元组(a,b)共有多少组?
 *
 * Input:
 *  2个正整数N,K。
 *
 * Output:
 *  输出一个正整数, 满足条件的正整数二元组(a,b)个数
 *
 * Hints:
 *  1≤N≤10<5>, 0≤K≤N-1 
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 2
 *
 *  output:
7
 *
 *  2):
 *  input:
10 0
 *
 *  output:
100
 *
 *  3):
 *  input:
31415 9265
 *
 *  output:
287927211
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 1ll * n * n << endl;
        return 0;
    }
    LL ans = 0;
    for (int b = k + 1; b <= n; b++) {
        ans += n / b * (b - k) + max(0, n % b - k + 1);
    }
    cout << ans << endl;
    return 0;
}