/**
 * Description:
 *  n 个人围成一圈，编号为1∼n，从第一个人开始报数，从 1 开始，数到 m 的人出列，再由下一个人重新从 1 开始报数，数到 m 的人再出列，依次类推，直到所有的人都出列，请依次输出每次出列人的编号。
 * 
 * Input:
 *  输入两个整数 n,m
 * 
 * Output:
 *  输出一行n 个整数，按出列顺序输出每个出列人的编号。
 * 
 * Hints:
 *  对于 50% 的数据，m,n <= 50。
 *  对于 100% 的数据，m,n < = 1000。
 * 
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
10 3
 * 
 *  output:
3 6 9 2 7 1 8 5 10 4
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, s[105]; // s[i]表示下标为i的人是否出列，1-表示未出列，0表示出列

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i <= n - 1; i++) {
        s[i] = 1;
    }
    
    int p = -1; // 上一个人的下标(位置)
    for (int i = 1; i <= n; i++) {
        int cnt = m; // 往后数m次
        
        while (cnt--) {
            p = (p + 1) % n;
            // 如果当前下标为p的人已经出列，继续往后找到一个未出列的人
            while (s[p] == 0) {
                p = (p + 1) % n;
            }
        }
        s[p]--; // 减一表示p的机会减少一次
        cout << p + 1 << " "; // 输出出列的人的下标
    }

    return 0;
}