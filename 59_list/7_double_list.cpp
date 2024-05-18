/**
 * Description:
 *  实现一个双向链表，双向链表初始为空，支持 5 种操作：
 *  在最左侧插入一个数；
 *  在最右侧插入一个数；
 *  将第 k 个插入的数删除；
 *  在第 k 个插入的数左侧插入一个数；
 *  在第 k 个插入的数右侧插入一个数
 *  现在要对该链表进行 M 次操作，进行完所有操作后，从左到右输出整个链表。
 *  注意：题目中第 k 个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，这 n 个数依次为：第 1 个插入的数，第 2 个插入的数，…，第 n 个插入的数。
 *
 * Input:
 *  第一行包含整数 M，表示操作次数。
 *  接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：
 *   •	L x，表示在链表的最左端插入数 x。
 *  	•	R x，表示在链表的最右端插入数 x。
 *  	•	D k，表示将第 k 个插入的数删除。
 *  	•	IL k x，表示在第 k 个插入的数左侧插入一个数。
 *  	•	IR k x，表示在第 k 个插入的数右侧插入一个数。
 *
 * Output:
 *  共一行，将整个链表从左到右输出。
 *
 * Hints:
 *  1≤M≤100000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
 *
 *  output:
8 7 7 3 2 9
 *
 */

#include <iostream>
#include <list>
using namespace std;

int m, n;
list<int> ls;
list<int>::iterator pos[100010];
int main()
{
    cin >> m;
    while (m--) {
        string op;
        int k, x;
        cin >> op;
        if (op == "L") {
            cin >> x;
            pos[++n] = ls.insert(ls.begin(), x);
        } else if (op == "R") {
            cin >> x;
            pos[++n] = ls.insert(ls.end(), x);
        } else if (op == "D") {
            cin >> k;
            ls.erase(pos[k]);
        } else if (op == "IL") {
            cin >> k >> x;
            pos[++n] = ls.insert(pos[k], x);
        } else {
            cin >> k >> x;
            pos[++n] = ls.insert(next(pos[k]), x);
        }
    }
    for (auto it : ls) {
        cout << it << " ";
    }
    return 0;
}