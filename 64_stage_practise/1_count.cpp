/**
 * Description:
 *  有N个小孩围成一圈，给他们从1开始依次编号，现指定从第W个开始报数，报到第S个时，该小孩出列，然后从下一个小孩开始报数，仍是报到S个出列，如此重复下去，直到所有的小孩都出列（总人数不足S个时将循环报数），求小孩出列的顺序。
 *
 * Input:
 *  第一行输入小孩的人数N（N≤10000），接下来每行输入一个小孩的名字(人名不超过15个字符)。
 *  最后一行输入W,S (W,S≤N)，用空格间隔。
 *
 * Output:
 *  按人名输出小孩按顺序出列的顺序，每行输出一个人名。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
Xiaoming
Xiaohua
Xiaowang
Zhangsan
Lisi
2 3
 *
 *  output:
Zhangsan
Xiaohua
Xiaoming
Xiaowang
Lisi
 *
 */

#include <iostream>
#include <list>
using namespace std;
int n, w, s;
list<string> ls;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        ls.insert(ls.end(), s);
    }
    cin >> w >> s;
    auto pos = ls.begin();
    for (int i = 1; i < w; i++) {
        pos++;
    }
    while (ls.size()) {
        for (int i = 1; i < s; i++) {
            pos++;
            if (pos == ls.end()) {
                pos = ls.begin();
            }
        }
        cout << *pos << endl;
        pos = ls.erase(pos);
        if (pos == ls.end()) {
            pos = ls.begin();
        }
    }
    return 0;
}