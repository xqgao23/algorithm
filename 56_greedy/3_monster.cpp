/**
 * Description:
 *  有n个怪物排队等待玩家来消灭它们。第i个怪物的体力为hi。玩家A的攻击力为a，玩家B的攻击力为b。
 *  对于每只怪物，两位玩家按如下顺序交替行动，直到怪物血量小于等于0：
 *  （1）玩家A攻击怪物，怪物血量减少a。如果攻击后怪物血量小于等于0，玩家A得到1分。
 *  （2）玩家B攻击怪物，怪物血量减少b。如果攻击后怪物血量小于等于0，玩家A不得分。
 *  每个怪都是由A先发起攻击。
 *  玩家A另外有一种特殊能力，可以迫使B放弃一次攻击。他最多可以使用这个能力k次。
 *  求出玩家A最多可以得到多少分。
 *
 * Input:
 *  第1行，4个整数n,a,b,k
 *  第2行，n个正整数h1,h2,...,hn
 *
 * Output:
 *  输出A能得到的最多分数
 *
 * Hints:
 *  1≤n≤2*10<5>, 1≤a,b,k≤10<9>, 1≤hi≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 2 3 3
7 10 20 12 1 8
 *
 *  output:
5
 *
 *  2):
 *  input:
1 1 100 99
100
 *
 *  output:
1
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, a, b, k, h[200010], ans;

int main()
{
    cin >> n >> a >> b >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        h[i] %= a + b;
        if (h[i] == 0) {
            h[i] = a + b;
        }
        h[i] = (h[i] - 1) / a;
    }
    sort(h + 1, h + n + 1);
    for (int i = 1; i <= n; i++) {
        k -= h[i];
        if (k < 0) {
            break;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}