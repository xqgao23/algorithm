/**
 * Description:
 *  A,B,C三人在玩一个卡片游戏, 规则如下:
 *  游戏开始时, 3人分别有卡片若干枚, 每张卡上写着'a', 'b', 'c'中某一个字母. 卡片的顺序严格按照输入顺序排列, 不允许改变顺序.
 *  游戏从A的回合开始.
 *  果轮到某人的回合, 且这个人手上有牌, 他必须出自己手上的第1张牌. 之后轮到这张牌的写着的字母同名的人的回合. (例如出'a'牌之后就轮到A的回合)
 *  如果轮到某人的回合, 且这个人手没有牌, 这个人就是赢家.
 *  三人的起始手牌以字符串SA,SB,SC的形式给出, 字符串开头是第1张牌.
 * 
 * Input:
 *  三行，分别是字符串SA,SB,SC判断谁是赢家.
 * 
 * Output:
 *  如果A胜出输出'A', 如果B胜出输出'B', 如果C胜出输出'C'
 * 
 * Hints:
 *  字符串SA,SB,SC长度不超过100, 只包含'a', 'b', 'c'三种字符.
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
aca
accc
ca
 * 
 *  output:
A
 *
 *  2):
 *  input:
abcb
aacb
bccc
 * 
 *  output:
C
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string sa, sb, sc;

    cin >> sa >> sb >> sc;
    
    int cnta = 0, cntb = 0, cntc = 0;
    char now = 'a';

    while (true) {
        if (now == 'a') {
            if (cnta == sa.size()) {
                cout << "A" << endl;
                break;
            }
            now = sa[cnta];
            cnta++;
        } else if (now == 'b') {
            if (cntb == sb.size()) {
                cout << "B" << endl;
                break;
            }
            now = sb[cntb];
            cntb++;
        } else {
            if (cntc == sc.size()) {
                cout << "C" << endl;
                break;
            }
            now = sc[cntc];
            cntc++;
        }
    }
    
    return 0;
}