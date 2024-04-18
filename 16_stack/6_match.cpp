/**
 * Description:
 *  假设一个表达式由英文字母（小写）、运算符（+,-,*,/）和左右小圆括号构成。请编写一个程序检查表达式中的左右圆括号是否匹配，若匹配，则返回"YES"，并输出每对匹配的括号在字符串中的位置；否则返回"NO"
 *
 * Input:
 *  1 个字符串 s
 *
 * Output:
 *  判断字符串 s 中括号是否匹配。如果匹配，第1行输出YES，然后每行输出两个数，表示一对互相匹配的括号在字符串中的位置（从1开始编号）。先输出左括号位置再输出右括号位置。按左括号位置从前到后顺序输出。
 *  如果不匹配，只输出一个NO
 *
 * Hints:
 *  字符串长度小于255
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2*(x+y)/(1-x)
 *
 *  output:
YES
3 7
9 13
 *
 *  2):
 *  input:
(25+x)*(a*(a+b+b
 *
 *  output:
NO
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct node {
    int l, r;
} p[130];

stack<char> st;

bool cmp(node x, node y)
{
    if (x.l != y.l) {
        return x.l < y.l;
    }
    return x.r < y.r;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size(), cnt = 0;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (st.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            node temp_p;
            temp_p.l = st.top();
            temp_p.r = i;
            p[++cnt] = temp_p;
            st.pop();
        }
    }
    if (st.size()) {
        cout << "NO" << endl;
    } else {
        sort(p + 1, p + cnt + 1, cmp);
        cout << "YES" << endl;
        for (int i = 1; i <= cnt; i++) {
            cout << p[i].l << " " << p[i].r << endl;
        }
    }
    return 0;
}