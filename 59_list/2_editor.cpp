/**
 * Description:
 *  为了简化问题，我们把文本编辑器的功能简化为下述指令：
 *  insert x 在光标前插入新字符x，保证x属于大小写字母。
 *  newline 从光标处换行。
 *  delete 删除光标前的字符，如果光标位于行首，表示取消换行，合并到上一行；如果光标位于编辑器最前方，不发生任何变化。
 *  left 光标左移，如果光标位于行首，左移到达上一行行末；如果光标位于编辑器最前方，不发生任何变化。
 *  right 光标右移，如果光标位于行末，右移到达下一行行首；如果光标位于编辑器最后方，不发生任何变化。
 *  请你输出所有指令结束后，文本编辑器最后显示的文本。
 *
 * Input:
 *  输入包括多行。
 *  第一行整数n，表示一共有多少条指令需要执行。(1≤n≤50000)
 *  下面为n行，每一行都是一个指令。
 *
 * Output:
 *  输出包括若干行，为文本编辑器最后显示的文本，包括空行。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10
insert A
insert r
left
delete
insert d
insert b
newline
insert o
right
insert z
 *
 *  output:
db
orz
 *
 */

#include <iostream>
#include <list>
using namespace std;
int n;
list<char> ls;

int main()
{
    cin >> n;
    auto pos = ls.end();
    for (int i = 1; i <= n; i++) {
        string op;
        char c;
        cin >> op;
        if (op == "insert") {
            cin >> c;
            ls.insert(pos, c);
        } else if (op == "newline") {
            ls.insert(pos, '\n');
        } else if (op == "delete" && pos != ls.begin()) {
            pos = ls.erase(prev(pos));
        } else if (op == "left" && pos != ls.begin()) {
            pos--;
        } else if (op == "right" && pos != ls.end()) {
            pos++;
        }
    }
    for (auto it : ls) {
        cout << it;
    }
    return 0;
}