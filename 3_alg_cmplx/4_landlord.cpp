/**
 * Description:
 *  小明在玩超级斗地主，超级斗地主的牌的点数可能是从1到5000的任意一个数。小明的手牌有N张。他想通过出一个"k连顺"的方式，一次打出大量的手牌。"k连顺"定义如下：
 *  一个"k连顺"包含k种不同的点数，这些点数必须是连续的，并且每种点数的牌的数量必须相同。
 *  例如：333444555 就是一个"3连顺"，包含9张牌；56789是一个"5连顺"，包含5张牌；999999999999 是一个"1连顺"，包含12张牌。
 *  给出小明的所有手牌，他手中包含卡牌数量最多的"k连顺"包含多少张牌？
 * 
 * Input:
 *  第1行，1个正整数N，表示小明的手牌张数
 *  第2行，N个正整数，用空格分隔，表示小明所有手牌的点数
 * 
 * Output:
 *  输出一个正整数，卡牌数量最多的"k连顺"包含的张数
 * 
 * Hints:
 *   1≤N≤10<6>小明的手牌的点数不超过5000
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
17
3 3 4 4 5 5 6 7 8 9 9 9 9 9 9 9 9
 * 
 *  output:
8
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt[5010], ans;

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    // 如果确定了连顺的起点i和终点j,
    // 那么连顺的张数min(a[i],a[i+1],...,a[j])*(j-i+1)
    for(int i = 1; i <= 5000; i++) {
        int x = 1e9;
        for(int j = i; j <= 5000; j++) {
            x = min(x, cnt[j]);
            ans = max(ans, x * (j - i + 1));
        }
    }
    
    cout << ans << endl;

    return 0;
}