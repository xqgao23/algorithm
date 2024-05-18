/**
 * Description:
 *  你有n个盒子在桌子上排成一行，从左往右编号从1到n。
 *  你的任务是模拟如下四种操作，然后求操作完后奇数位置的编号和：
 *  1 X Y，移动编号为X的盒子到编号为Y的盒子的左边（如果X已经在Y的左边则忽略）
 *  2 X Y，移动编号为X的盒子到编号为Y的盒子的右边（如果X已经在Y的右边则忽略）
 *  3 X Y，交换编号为X的盒子和编号为Y的盒子的位置
 *  4，将整行的盒子反转（即第一个盒子变成最后一个盒子，第二个盒子变成倒二个盒子...以此类推）
 *
 * Input:
 *  第一行包含两个整数n,m(1≤n,m≤100000)，表示有n个盒子和m个操作。
 *  接下来m行，每行为上述四种操作之一。
 *  数据保证X≠Y
 *
 * Output:
 *  输出一行，包含一个整数，为操作完后奇数位置的编号的和。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 4
1 1 4
2 3 5
3 1 6
4
 *
 *  output:
12
 *
 *  2):
 *  input:
6 3
1 1 4
2 3 5
3 1 6
 *
 *  output:
9
 *
 *  3):
 *  input:
100000 1
4
 *
 *  output:
2500050000
 *
 */

#include <iostream>
#include <list>
using namespace std;
int n, m, p;
list<int> ls;
list<int>::iterator pos[100010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        pos[i] = ls.insert(ls.end(), i);
    }
    while (m--) {
        int op, x, y;
        cin >> op;
        if (p && op <= 2) {
            op = 3 - op;
        }
        if (op == 1) {
            cin >> x >> y;
            ls.erase(pos[x]);
            pos[x] = ls.insert(pos[y], x);
        } else if (op == 2) {
            cin >> x >> y;
            ls.erase(pos[x]);
            pos[x] = ls.insert(next(pos[y]), x);
        } else if (op == 3) {
            cin >> x >> y;
            auto py = pos[y];
            pos[y] = ls.insert(pos[x], y);
            ls.erase(pos[x]);
            pos[x] = ls.insert(py, x);
            ls.erase(py);
            /*
            或者
            iter_swap(pos[x], pos[y]);
            swap(pos[x], pos[y]);
            */
        } else {
            p = 1 - p;
        }
    }
    if (p) {
        ls.reverse();
    }
    long long ans = 0, id = 0;
    for (auto it : ls) {
        if (++id % 2 != 0) {
            ans += it;
        }
    }
    cout << ans << endl;
    return 0;
}