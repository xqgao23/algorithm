/**
 * Description:
 *  由于店主的要求比较多，皮皮总是找不到书，因此他希望你帮他写一个程序，使得他能够知道每个书架有哪些书。
 *  指令一共有5种：
 *  1、进书指令：
 *  add x a b d
 *  在x号书架放入b本种类为a的书，其中d=0时代表放在最前面，d=1代表放在最后面。1≤b≤10。
 *  2、下架指令
 *  remove x a
 *  把x号书架上所有种类为a的书从书架中拿走。
 *  3、移动指令：
 *  move x y d
 *  把x号书架的书全部放到y号书架上，其中d=0时代表放在最前面，d=1代表放在最后面。指令执行后，x号书架被清空。保证x≠=y
 *  4、翻转指令
 *  reverse x
 *  把x号书架上的书全部翻转
 *  5、查询指令
 *  query x
 *  查询x号书架上的全部书籍，如果x书架上没有任何书，输出空行。
 *
 * Input:
 *  输入包括多行。
 *  第一行两个整数n,m，表示一共有n个书架，有m条指令需要执行。(1≤n≤1000，1≤m≤50000)
 *  下面为m行，每一行都是一个指令。书的编号是小于10<9>的正整数。
 *
 * Output:
 *  输出包括若干行，对于每个query指令输出一行，从左到右输出对应书架上所有书籍的种类，数据之间用空格分隔。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 11
add 1 1 3 1
add 1 2 3 0
add 1 4 2 1
query 1
reverse 1
query 1
add 2 3 2 0
move 1 2 0
query 2
remove 2 1
query 2
 *
 *  output:
2 2 2 1 1 1 4 4
4 4 1 1 1 2 2 2
4 4 1 1 1 2 2 2 3 3
4 4 2 2 2 3 3
 *
 */

#include <iostream>
#include <list>
using namespace std;
int n, m;
list<int> ls[1010];

int main()
{
    cin >> n >> m;
    while (m--) {
        string op;
        int x, y, a, b, d;
        cin >> op;
        if (op == "add") {
            cin >> x >> a >> b >> d;
            if (d == 0) {
                ls[x].insert(ls[x].begin(), b, a);
            } else {
                ls[x].insert(ls[x].end(), b, a);
            }
        } else if (op == "remove") {
            cin >> x >> a;
            // ls[x].remove(a);
            for (auto it = ls[x].begin(); it != ls[x].end(); it++) {
                if (*it == a) {
                    it = ls[x].erase(it);
                    it--;
                }
            }
        } else if (op == "move") {
            cin >> x >> y >> d;
            if (d == 0) {
                ls[y].splice(ls[y].begin(), ls[x]);
            } else {
                ls[y].splice(ls[y].end(), ls[x]);
            }
        } else if (op == "reverse") {
            cin >> x;
            ls[x].reverse();
        } else {
            cin >> x;
            for (auto it : ls[x]) {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}