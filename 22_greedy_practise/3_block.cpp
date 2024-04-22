/**
 * Description:
 *  春春幼儿园举办了一年一度的"积木大赛"。今年比赛的内容是搭建一座宽度为n的大厦，大厦可以看成由n块宽度为1的积木组成，第i块积木的最终高度需要是hi。
 *  在搭建开始之前，没有任何积木（可以看成n块高度为0的积木）。接下来每次操作，小朋友们可以选择一段连续区间[l,r]，然后将第第L块到第R 块之间（含第L 块和第 R块）所有积木的高度分别增加1。
 *  小M是个聪明的小朋友，她很快想出了建造大厦的最佳策略，使得建造所需的操作次数最少。但她不是一个勤于动手的孩子，所以想请你帮忙实现这个策略，并求出最少的操作次数。
 *
 * Input:
 *  包含两行，第一行包含一个整数n，表示大厦的宽度。
 *  第二行包含n个整数，第i个整数为hi
 *
 * Output:
 *  建造所需的最少操作数。
 *
 * Hints:
 *  1≤n≤100000,0≤hi≤10000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
2 3 4 1 2
 *
 *  output:
5
 *
 */

// 方法一
#include <cmath>
#include <iostream>
using namespace std;
int n, d[100010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    int l = 1, r, ans = 0;
    while (true) // 从左到右修改d
    {
        while (l <= n && d[l] == 0) {
            l++; // 找第一个不是0的元素
        }
        if (l > n) {
            break; // 全部都变为0了，修改完成
        }
        r = l;
        int c = d[l]; // 可以一次修改的最大操作数
        while (d[r] > 0) {
            c = min(c, d[r]);
            r++;
        }
        for (int i = l; i < r; i++) {
            d[i] -= c;
        }
        ans += c; // 修改c次
    }
    cout << ans << endl;
    return 0;
}