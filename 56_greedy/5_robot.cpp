/**
 * Description:
 *  Imp家里有一个扫地机器人，他还养了一条狗。扫地机器人工作时会发出很多噪音，狗很害怕这些噪音。
 *  有一天，Imp提取了机器人的运行记录，这些记录是n个字符串t1,t2,…,tn，每个字符串只包含英文字母's'和'h'。但是他无法知道这些记录的时间先后顺序，他将这些字符串连接成一个字符串T，使T中子序列"sh"的个数最多。
 *  噪音的数量定义为：字符串中子序列"sh"的个数。准确地说，是满足i<j且Ti=s,Tj=h的(i,j)个数。
 *
 * Input:
 *  第1行，1个正整数n
 *  接下来n行，每行1个字符串ti
 *
 * Output:
 *  输出1个整数，为最大的噪音数量。
 *
 * Hints:
 *  1≤n≤10<5>,所有字符串长度总和不超过10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
ssh
hs
s
hhhs
 *
 *  output:
18
 *
 *  2):
 *  input:
2
h
s
 *
 *  output:
1
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct node {
    int s, h;
    string t;
} p[100010];
long long n, ans, s;

bool cmp(node x, node y)
{
    return x.s * y.h > y.s * x.h;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].t;
        for (int j = 0; j < p[i].t.size(); j++) {
            if (p[i].t[j] == 'h') {
                p[i].h++;
            } else {
                p[i].s++;
            }
        }
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < p[i].t.size(); j++) {
            if (p[i].t[j] == 'h') {
                ans += s;
            } else {
                s++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}