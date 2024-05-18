/**
 * Description:
 *  Petya最近在学习数据结构。他正在练习最小堆，Petya对他的堆进行若干操作，并且记录下了每次操作的结果，包括以下三种：
 *  （1）insert x：将一个值为x的数加入堆中。
 *  （2）removeMin：删除堆中的最小数。
 *  （3）getMin x：查询堆中的数的最小值，发现堆中数的最小值等于x。
 *  做好记录后，Vova来到Petya的房间，把Petya的记录弄丢了一部分。于是Vova决定在剩下的记录中添加一些记录，让记录不出现矛盾。
 *  （1）insert x，直接将一个值为x的数加入堆中即可，不会出现矛盾。
 *  （2）遇到 removeMin 时，如果堆中还有数，那么直接删除最小数即可。如果堆中没有数，就会出现矛盾，此时Vova会在 removeMin 前添加一条 insert 0，先将数0加入堆中，再进行删除操作。
 *  （3）遇到 getMin x 时，分3种情况：
 *  （i）堆中最小数等于x，此时不会出现矛盾。
 *  （ii）堆中没有数，或者堆中最小数大于x，此时Vova会先添加一条 insert x 操作，这样堆中的最小数就是x了。
 *  （iii）堆中最小数小于x，此时Vova会添加若干条 removeMin 操作，直到堆中的最小数大于等于x或者堆中没有数为止。这样就化为（i）或（ii）的情况了。
 *  输入Petya剩下的记录，输出Vova添加记录后，记录的条数以及完整记录。
 *
 * Input:
 *  第1行，输出一个正整数m，表示Vova添加记录后，记录的条数。
 *  接下来m行，每行一条记录，表示Vova添加后的完整记录，格式同输入。
 *
 * Output:
 *  对每个询问操作，输出最大的距离。
 *
 * Hints:
 *  1≤n≤10<5>
 *  −10<9>≤x≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
removeMin
getMin 4
getMin 5
 *
 *  output:
7
insert 0
removeMin
insert 4
getMin 4
removeMin
insert 5
getMin 5
 *
 *  2):
 *  input:
4
insert 1
insert 1
insert 4
getMin 2
 *
 *  output:
7
insert 1
insert 1
insert 4
removeMin
removeMin
insert 2
getMin 2
 *
 */

#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int n, cnt;
string s[1000010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string op;
        int x;
        cin >> op;
        if (op == "insert") {
            cin >> x;
            q.push(x);
            s[++cnt] = "insert " + to_string(x);
        } else if (op == "removeMin") {
            if (q.size()) {
                q.pop();
            } else {
                s[++cnt] = "insert 0";
            }
            s[++cnt] = "removeMin";
        } else {
            cin >> x;
            while (q.size() && q.top() < x) {
                s[++cnt] = "removeMin";
                q.pop();
            }
            if (q.empty() || q.top() > x) {
                s[++cnt] = "insert " + to_string(x);
                q.push(x);
            }
            s[++cnt] = "getMin " + to_string(x);
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << s[i] << "\n";
    }
    return 0;
}