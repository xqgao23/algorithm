/**
 * Description:
 *  轩轩和凯凯正在玩一款叫《龙虎斗》的游戏，游戏的棋盘是一条线段，线段上有n 个兵营（自左至右编号1∼n），相邻编号的兵营之间相隔 1 厘米，即棋盘为长度为 n−1 厘米的线段。i 号兵营里有 Ci位工兵。
 *  轩轩在左侧，代表"龙"；凯凯在右侧，代表"虎"。 他们以 m 号兵营作为分界， 靠左的工兵属于龙势力，靠右的工兵属于虎势力，而第 m 号兵营中的工兵很纠结，他们不属于任何一方。
 *  一个兵营的气势为：该兵营中的工兵数× 该兵营到 m 号兵营的距离；参与游戏 一方的势力定义为：属于这一方所有兵营的气势之和。
 *  游戏过程中，某一刻天降神兵，共有 Si位工兵突然出现在了 p1号兵营。作为轩轩和凯凯的朋友，你知道如果龙虎双方气势差距太悬殊，轩轩和凯凯就不愿意继续玩下去了。为了让游戏继续，你需要选择一个兵营p2 ，并将你手里的 s2位工兵全部派往 兵营p2 ，使得双方气势差距尽可能小。
 *  注意：你手中的工兵落在哪个兵营，就和该兵营中其他工兵有相同的势力归属（如果落在 m 号兵营，则不属于任何势力）。
 * 
 * Input:
 *  输入文件的第一行包含一个正整数n，代表兵营的数量。
 *  接下来的一行包含 n 个正整数，相邻两数之间以一个空格分隔，第 i 个正整数代 表编号为 i 的兵营中起始时的工兵数量 ci
 *  接下来的一行包含四个正整数，相邻两数间以一个空格分隔，分别代表 m,p1,s1,s2.
 * 
 * Output:
 *  输出文件有一行，包含一个正整数，即p2, 表示你选择的兵营编号。如果存在多个编号同时满足最优，取最小的编号。
 * 
 * Hints:
 *  n<=10<5>, ci,s1,s2<=10<9>
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
6
2 3 2 3 2 3
4 6 5 2
 * 
 *  output:
2
 *
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, c[100005], m, p1, s1, p2, s2, sum1, sum2;

int main()
{
    long long minn = 9e18;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    cin >> m >> p1 >> s1 >> s2;
    c[p1] += s1;
    
    for(int i = 1; i <= n; i++) {
        if (i < m) {
            sum1 += (m - i) * c[i];//计算龙方气势;
        }
        if (i > m) {
            sum2 += (i - m) * c[i];//计算虎方气势;
        }
    }

    for(int i = 1; i <= n; i++) {
        if (i < m) {
            sum1 += (m - i) * s2;
        }
        
        if (i > m) {
            sum2 += (i - m) * s2;//算出派出s2后的双方新气势;
        }
        long long tmp = abs(sum1 - sum2);//计算把手上兵力派往i号兵营后的气势差;
        
        if (minn > tmp) {
            minn = tmp;
            p2 = i;
        }
        
        if (i < m) {
            sum1 -= (m - i) * s2;
        }
        
        if (i > m) {
            sum2 -= (i - m) * s2;
        }
    }

    cout << p2 << endl;
    
    return 0;
}