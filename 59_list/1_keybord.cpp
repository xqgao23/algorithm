/**
 * Description:
 *  你有一个破损的键盘。键盘上的所有键都可以正常工作，但有时 Home 键或者 End 键会自动按下。 Home键会使得光标移动到行首，End键会使得光标移动到行末。你并不知道键盘存在这个问题，只是专心地打稿子，甚至连显示器都没打开。当你打开显示器之后，展现在你面前的是一段悲剧的文本。你的任务是在打开显示器之前计算出这段悲剧文本。
 *
 * Input:
 *  一行，一个字符串，包含不超过 100000 个字母、下划线、字符" [ "或者" ] "。其中字符" [ "表示 Home 键，" ] "表示 End 键。
 *
 * Output:
 *  输出最终显示器上的文本
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
This_is_a_[Beiju]_text
 *
 *  output:
BeijuThis_is_a__text
 *
 */

#include <iostream>
#include <list>
using namespace std;
string s;
list<char> ls;

int main()
{
    cin >> s;
    auto pos = ls.end();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
            pos = ls.begin();
        } else if (s[i] == ']') {
            pos = ls.end();
        } else {
            ls.insert(pos, s[i]);
        }
    }
    for (auto it : ls) {
        cout << it;
    }
    return 0;
}