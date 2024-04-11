/**
 * Description:
 *  小明在玩一个很奇怪的卡牌游戏，这个游戏的每张牌的点数都是一个正整数，小明手里有N张牌的时候，手牌的牌力按如下规则计算：
 *  牌力初始为0，将所有牌按照点数从小到大排序后，对于每对相邻的牌：如果这两张相邻的牌点数相等，牌力增加 k；如果这两张牌点数不相等，那么牌力增加两张牌点数差的平方。
 *  例如5 张牌从小到大为1,1,3,3,4，且k=3，那么牌力为 3+(1−3)<2> + 3 + (4 -3 )<2> = 11 点。
 * 但是N张牌是一张张依次发给小明的，小明想要知道当他手中有1,2,⋯,N 张牌时，牌力分别是多少？（只有1 张牌时的牌力认为是 0）
 * 
 * Input:
 *  第 1 行，2 个正整数N,k，用空格分隔
 *  接下来 N 行，每行一个正整数，第i+1 行的正整数 ai表示第 i 张发给小明的牌的点数。
 * 
 * Output:
 *  输出 N 行，第 i 行表示小明拿到前 i 张牌时，他手牌的牌力
 * 
 * Hints:
 *   n <= 10<5>, 1 <= k <= 10<9>, 1<=ai <= 500
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
5 3
4
1
3
3
1
 * 
 *  output:
0
9
5
8
11
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[100010], cnt[510];

int main()
{
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        
        long long ans = 0;
        
        int last = -1;
        
        for (int j = 1; j <= 500; j++) {
            if (last == -1 && cnt[j]) last = j; if (cnt[j] != 0) {
                ans += (j - last) * (j - last);
                ans += 1ll * (cnt[j] - 1) * k;
                last = j;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}