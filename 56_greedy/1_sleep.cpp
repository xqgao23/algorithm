/**
 * Description:
 *  有n间房间排成一排，有些房间亮着灯，有些房间关着灯。
 *  如果一个房间关着灯，但是旁边两个房间都亮着灯，那么这个房间的人就会受到灯光打扰无法入睡。ai表示第i个房间是否开着灯，对于2≤i≤n−1，如果ai=0且ai-1= ai+1=1，那么第i个房间的人就受到打扰。
 *  现在给出哪些房间开着灯，问最少关掉多少房间的灯，就可以让所有关着灯的房间的人不受到打扰。
 *
 * Input:
 *  第1行，1个正整数n
 *  第2行，n个整数a1,a2,...,an.
 *  ai=0表示第i个房间关着灯，ai=1表示第i个房间开着灯。
 *
 * Output:
 *  输出一个整数表示答案
 *
 * Hints:
 *  3≤n≤100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10
1 1 0 1 1 0 1 0 1 0
 *
 *  output:
2
 *
 *  2):
 *  input:
5
1 1 0 0 0
 *
 *  output:
0
 *
 */

#include <iostream>
using namespace std;
int n, a[110], ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < n; i++) {
        if (a[i - 1] && !a[i] && a[i + 1]) {
            ans++;
            a[i + 1] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}