/**
 * Description:
 *  一个湖边有N户人家， 沿着湖边环湖一周的路程是K米。
 *  第i户的位置是，从湖最北端顺时针走Ai米的位置。
 *  每户之间的移动只能沿着湖边进行。
 *  推销员可以从任何一家出发，他的目的是访问湖边的所有N户人家，求出推销员需要走最少路程。
 *
 * Input:
 *  第1行，两个正整数K,N，代表环湖一周长度和家的个数，以空格分隔。
 *  第2行，N个正整数A1,A2,...,AN，以空格分隔。
 *
 * Output:
 *  输出1个整数，推销员需要走最少路程。
 *
 * Hints:
 *  2<=K<=10<8>, 2<=N<=2*10<5>, 0<=A1<A2<...<AN<K
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
20 3
1 2 10
 *
 *  output:
9
 *
 *  2):
 *  input:
20 3
0 5 15
 *
 *  output:
10
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int k, n, a[200010], b[200010];

int main()
{
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) {
        b[i] = a[i + 1] - a[i];
    }
    b[n] = k - (a[n] - a[1]);
    sort(b + 1, b + n + 1);
    cout << k - b[n] << endl;
    return 0;
}