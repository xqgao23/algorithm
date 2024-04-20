/**
 * Description:
 *  有一个两端开口的圆桶。给出 Q 次操作，每个操作可能是以下两类的某一类：
 *  （1）1 x
 * c：其中x,c是整数。表示将 c 个写着整数 x 的球从右侧开口依次放进圆桶。 （2）2
 * c：其中c是一个整数。表示从左侧开口依次取出 c 个球，并输出这 c 个球上写着的数的总和。
 *
 * Input:
 *  第1行，1个正整数Q。
 *  接下来Q行，每行一个操作，具体格式见题目描述。
 *
 * Output:
 *  对每个第二类操作，用一行输出取出的球上数字的总和。
 *
 * Hints:
 *  1<=Q<=2*10<5>, 0<=x<=10<9>, 1<=c<=10<9>.
 * 第二类操作时，保证圆桶内至少有c个球。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
1 2 3
2 2
1 3 4
2 3
 *
 *  output:
4
8
 *
 *  2):
 *  input:
2
1 1000000000 1000000000
2 1000000000
 *
 *  output:
1000000000000000000
 *
 */

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, c;
};

int Q, op, c, x;
queue<node> q;

int main()
{
    cin >> Q;
    while (Q--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> c;
            node tt;
            tt.x = x;
            tt.c = c;
            q.push(tt);
        } else {
            cin >> c;
            long long s = 0;
            while (q.size()) {
                if (c == 0) {
                    break;
                }
                if (c >= q.front().c) {
                    c -= q.front().c;
                    s += 1ll * q.front().c * q.front().x;
                    q.pop();
                } else {
                    s += 1ll * c * q.front().x;
                    q.front().c -= c;
                    c = 0;
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}