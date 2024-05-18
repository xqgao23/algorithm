/**
 * Description:
 *  某次算法竞赛采用了一种奇怪的评分系统，评分系统支持以下两种操作：
 *  （1）提交。一名选手提交自己的分数，用字符串submit表示，后面跟着两个整数id和score，表示选手的编号和分数。
 *  （2）晋级。用字符串check表示，后面跟着一个整数x。当前提交了分数的选手中，大于等于x分的选手全部晋级，并且输出本次晋级选手id（已晋级的选手的分数将从系统中删除）。如果没有大于等于x分的选手，要输出none。
 *  一共会有m次操作。对于所有check操作，输出每次晋级选手的id。
 *
 * Input:
 *  第1行，1个正整数m，表示操作次数。
 *  接下来m行，每行一个操作。
 *
 * Output:
 *  对每个check操作，用1行输出此次晋级的选手的id，按照分数从大到小顺序输出，分数相同的按id从小到大输出。数与数之间用空格分隔。
 *
 * Hints:
 *  2≤m≤10<5>, 1≤score,id,x≤10<9>, 
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
submit 1 6
submit 5 4
check 6
submit 2 3
submit 6 4
check 3
 *
 *  output:
1
5 6 2
 *
 */

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int id, x;
    bool operator<(const node &_) const
    {
        if (x != _.x) {
            return x < _.x;
        }
        return id > _.id;
    }
};

priority_queue<node> q;
int m;

int main()
{
    cin >> m;
    while (m--) {
        string s;
        int id, x;
        cin >> s;
        if (s == "submit") {
            cin >> id >> x;
            node t = {id, x};
            q.push(t);
        } else {
            cin >> x;
            bool flag = 1;
            while (q.size() && q.top().x >= x) {
                cout << q.top().id << " ";
                q.pop();
                flag = 0;
            }
            if (flag) {
                cout << "none";
            }
            cout << endl;
        }
    }
    return 0;
}