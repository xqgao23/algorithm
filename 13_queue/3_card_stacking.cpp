/**
 * Description:
 *  Bessie和她的N−1名奶牛朋友玩卡牌游戏. 这个游戏使用K张牌(K是N的倍数),
 * 每个人发M=K/N张卡. K张卡中有M=K/N张卡是"好牌",其余K−M张卡是"坏牌".
 * Bessie负责发牌, 她非常想赢,
 * 她要把所有好牌都发给自己.但是其他奶牛认为Bessie会在发牌时作弊,
 * 于是要求Bessie按如下方式发牌. 发牌按逆时针方向.
 *  第1张牌发给Bessie右手边的（逆时针方向的下家）奶牛.
 *  从第2张牌开始, 每次发牌前都要将牌组顶上P张卡按顺序放到牌组最下方.
 *  Bessie想知道, 按照这个发牌规则, 如果想要把所有M张好牌发给自己,
 * 她需要事先把好牌安排在什么位置?
 *
 * Input:
 *  共2行。每行中两个数之间用一个空格隔开。
 *  第一行为两个正整数M,N，代表内存容量和文章的长度。
 *  第二行为N个非负整数，按照文章的顺序，每个数（大小不超过1000）代表一个英文单词。文章中两个单词是同一个单词，当且仅当它们对应的非负整数相同。
 *
 * Output:
 *  输出M=K/N行
 *  每行输出一个正整数, 为Bessie事先安排的"好牌"的位置
 *  按从小到大输出
 *
 * Hints:
 *  2≤N≤100;N≤K≤100,000;1≤P≤10;K一定是N的倍数
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 9 2
 *
 *  output:
3
7
8
 *
 */

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int n, k, p, ans[50010], cnt;
queue<int> q;

int main()
{
    cin >> n >> k >> p;
    for (int i = 1; i <= k; i++) {
        q.push(i);
    }
    for (int i = 1; i <= k; i++) {
        if (i % n == 0) {
            ans[++cnt] = q.front();
        }
        q.pop();
        for (int j = 1; j <= p; j++) {
            q.push(q.front());
            q.pop();
        }
    }
    sort(ans + 1, ans + cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}