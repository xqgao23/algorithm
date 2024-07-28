/**
 * Description:
 *  字符串中只含有括号 (),[],<>,{},判断输入的字符串中括号是否匹配。如果括号有互相包含的形式，从内到外必须是<>,(),[],{}，例如。输入: [()] 输出:YES，而输入([])，([)]都应该输出NO。
 *
 * Input:
 *  第一行为一个整数n，表示以下有多少个由括号组成的字符串。接下来的n行，每行都是一个由括号组成的长度不超过255的字符串。
 *
 * Output:
 *  在输出文件中有n行，每行都是YES或NO。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
{}{}<><>()()[][]
{{}}{{}}<<>><<>>(())(())[[]][[]]
{{}}{{}}<<>><<>>(())(())[[]][[]]
{<>}{[]}<<<>><<>>>((<>))(())[[(<>)]][[]]
><}{{[]}<<<>><<>>>((<>))(())[[(<>)]][[]]
 *
 *  output:
YES
YES
YES
YES
NO
 *
 */

#include <iostream>
#include <stack>

using namespace std;

int pri[128];

bool is_brace_match(char a, char b)
{
    if (a == '{' && b == '}') return true;
    if (a == '[' && b == ']') return true;
    if (a == '<' && b == '>') return true;
    if (a == '(' && b == ')') return true;

    return false;
}

int main()
{
    int n;

    cin >> n;
    pri['<'] = 1;
    pri['('] = 2;
    pri['['] = 3;
    pri['{'] = 4;

    while (n--) {
        stack<char> s;
        string st;
        cin >> st;
        for (int i = 0; i < st.length(); i++) {
            if (!s.empty()) {
                if (pri[st[i]] > pri[s.top()]) {
                    break;
                }
                if (is_brace_match(s.top(), st[i])) {
                    s.pop();
                } else {
                    s.push(st[i]);
                }
            } else {
                s.push(st[i]);
            }
        }
        if (s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}