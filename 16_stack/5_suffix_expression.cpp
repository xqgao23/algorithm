/**
 * Description:
 *  后缀式是波兰逻辑学家卢卡西维奇（Lukasiewicz)发明的一种表示表达式的方法。
 *  这种表示方式把运算符写在运算对象的后面，例如，把 a+b 写成 a b +，所以也称为后缀式。这种表示法的优点是根据运算对象和算符的出现次序进行计算，不需要使用括号，也便于用程序实现求值。
 *  例如 (a+b)∗(c−d) 的后缀表达式为 a b + c d − ∗。
 *
 * Input:
 *  一行，表示要计算的后缀表达式。所有数都是正整数，数字和运算符、数字和数字、运算符和运算符之间都用空格分隔。
 *
 * Output:
 *  1个数，表达式的值，保留小数点后6位。
 *
 * Hints:
 *  1<=Q<=10, 1<=n<=10000, a1,a2,...,an是1-n的一个排列
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 5 2 - * 7 +
 *
 *  output:
16.000000
 *
 */

#include <iostream>
#include <stack>
using namespace std;
stack<double> st;

int s2d(string s)
{
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        x = x * 10 + (s[i] - '0');
    }
    return x;
}

int main()
{
    string s;
    while (cin >> s) {
        if ('0' <= s[0] && s[0] <= '9') {
            st.push(s2d(s));
        } else {
            double x2 = st.top();
            st.pop();
            double x1 = st.top();
            st.pop();
            if (s == "+") {
                st.push(x1 + x2);
            }
            if (s == "-") {
                st.push(x1 - x2);
            }
            if (s == "*") {
                st.push(x1 * x2);
            }
            if (s == "/") {
                st.push(x1 / x2);
            }
        }

        if (cin.get() == '\n') {
            break;
        }
    }
    printf("%.6lf\n", st.top());
    return 0;
}