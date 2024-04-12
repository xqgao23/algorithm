/**
 * Description:
 *  对一个给定的自然数M,求出所有的连续的自然数段，这些连续的自然数段中的全部数之和为M.
 *  例子:1998+1999+2000+2001+2002=10000, 所以从1998到2002的一个自然数段为M=10000的一个解.
 * 
 * Input:
 *  一行，包含一个整数，给出M的值.(10≤M≤2000000)
 * 
 * Output:
 *  输出为若干行，每行用1个空格隔开的2个自然数，给出一个满足条件的连续自然数段中的第一个数和最后一个数.
 *  所有输出行按第一个数从小到大的排列，保证至少有一个解.
 * 
 * Hints:
 *  10≤m≤2000000
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
10000
 * 
 *  output:
18 142
297 328
388 412
1998 2002
 *
 */

// 暴力枚举 40分
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;

    for(int i = 1; i <= m; i++) {           // 枚举起点
        for(int j = i + 1; j <= m; j++) {   // 枚举终点
            int sum = 0;

            for (int k = i; k <= j; k++) {
                sum += k; // 求i~j之间的元素和
            }
            if (sum > m) {
                break; // 如果i~j之间的元素和大于k，后面再加 上大于j的数一定大于sum
            }

            if (sum == m) {
                cout << i << " " << j << endl; // 符合题目要 求，输出起点和终点
            }
        }
    }
    
    return 0;
}