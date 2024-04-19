/**
 * Description:
 *  有一个数组S，一开始是空的。接下来对这个数组进行N次插入操作.
 *  第i次操作会向数组中加入bi个整数ai，然后将整个数组从小到大排一次序。
 *  求N次操作后, 数组中的第K个数。
 *  例如S={1,2,2,3,3,3}时, 从小到大排序后第4个数是3。
 *
 * Input:
 *  第1行, 包含两个整数N,K, 用空格分隔.
 *  第2行到第N+1行, 每行包含两个整数ai, bi
 *
 * Output:
 *  输出N次操作后集合中第K小的数.
 *
 * Hints:
 *  1<=N<=10<5>, 1<=ai,bi<=10<9>, 1<=K<=b1+b2+...+bN.
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4
1 1
2 2
3 3
 *
 *  output:
3
 *
 *  2):
 *  input:
4 200000
1 100000
1 100000
100000 100000
100000 100000
 *
 *  output:
1
 *
 */

#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
LL n, k;
map<int, LL> mp;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    for (auto it : mp) {
        k -= it.second;
        if (k <= 0) {
            cout << it.first << endl;
            break;
        }
    }
    return 0;
}