/**
 * Description:
 *  有若干个团队的人正在排一个长队，每次新来一个人时，如果有他的队友在排队，那么这个新人会插队到最后一个队友的身后。如果没有任何一个队友在排队，他会排到长队的队尾。
 *  每个人的编号z都是一个六位数xxxyyy，前3位表示他所在团队的编号，后3位表示他在团队中的编号。例如当前长队为{003001,003002,001003,001002,002001}，此时编号为001004的人来排队，他属于团队001，于是他将排在001002的后面。
 *  要求支持如下3种指令（前两种指令可以穿插进行）：
 *  （1）ENQUEUE z：编号为z的人入队。
 *  （2）DEQUEUE：长队的队首出队。
 *  （3）STOP：停止模拟。
 *  对于每个DEQUEUE指令，输出出队的人的编号。
 *
 * Input:
 *  第1行，1个正整数T，表示指令的个数。（T≤200000）
 *  接下来T行，每行一条指令，对于ENQUEUE指令，字符串ENQUEUE和编号z之间有一个空格。
 *
 * Output:
 *  输出若干行，对于每个DEQUEUE指令，用一行输出出队的人的编号
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
13
ENQUEUE 001001
ENQUEUE 002001
ENQUEUE 001002
ENQUEUE 002002
ENQUEUE 001003
ENQUEUE 002003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
 *
 *  output:
001001
001002
001003
002001
002002
002003
 *
 *  2):
 *  input:
15
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 260002
ENQUEUE 260004
DEQUEUE
DEQUEUE
ENQUEUE 260003
ENQUEUE 259001
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
 *
 *  output:
259001
259002
259003
259001
260001
260002
 *
 */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> Q, q[1010]; // Q是团队队列，q是团队i中的成员队列
    string s;
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        if (s[0] == 'S') {
            break;
        } else if (s[0] == 'D') {
            int t = Q.front();
            printf("%03d%03d\n", t, q[t].front());
            q[t].pop();
            if (q[t].empty()) {
                Q.pop();
            }
        } else if (s[0] == 'E') {
            int z;
            cin >> z;
            int x = z / 1000, y = z % 1000;
            if (q[x].empty()) {
                Q.push(x);
            }
            q[x].push(y);
        }
    }
    return 0;
}