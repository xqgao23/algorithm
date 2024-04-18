/**
 * Description:
 *  输入N个矩阵的行数列数和一些矩阵链乘表达式，输出乘法的次数。如果乘法无法进行，输出error。
 *  假定A是 m 行 n 列矩阵，B是 n 行 p 列矩阵，那么A乘B得到AB是 m 行 p 列矩阵，乘法次数为 m×n×p 。如果A的列数不等于B的行数，乘法无法进行。
 *  例如A是50行10列，B是10行20列，C是20行5列，则(A(BC))的乘法顺序是先计算B乘C，得到一个10行5列的矩阵BC，乘法次数 10×20×5 ；再计算A乘BC，得到50行5列的矩阵，乘法次数 50×10×5 。总共需要的乘法次数为 3500 次。
 *
 * Input:
 *  第1行，1个正整数 N ，表示矩阵的个数。
 *  接下来 N 行，每行1个大写英文字母和2个正整数 x,y ，分别表示矩阵名和这个矩阵的行数列数。
 *  接下来若干行，每行1个字符串，表示矩阵乘法表达式，保证表达式中的括号是合法配对的。
 *
 * Output:
 *  对每个矩阵乘法表达式，用1行输出需要的乘法次数。如果乘法无法进行，输出error。
 *
 * Hints:
 *  1≤N≤26
 *  1≤x,y≤100
 *  矩阵乘法表达式个数不超过 1000 个。
 *  表达式只含大写英文字母和小括号，长度不超过 80 ，保证其中括号是合法配对的。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
A 50 10
B 10 20
C 20 5
A
(AA)
(A(BC))
 *
 *  output:
0
error
3500
 *
 */

#include <iostream>
#include <stack>
using namespace std;
struct node {
    int a, b;
} p[30];
int n;
string s;

int slove(string s)
{
    stack<node> st;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            st.push(p[s[i] - 'A']);
        } else if (s[i] == ')') {
            node y = st.top();
            st.pop();
            node x = st.top();
            st.pop();
            if (x.b != y.a) {
                return -1;
            }
            ans += x.a * x.b * y.b;
            node t;
            t.a = x.a;
            t.b = y.b;

            st.push(t);
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        int k = c - 'A';
        node temp_p;
        temp_p.a = x;
        temp_p.b = y;
        p[k] = temp_p;
    }
    while (cin >> s) {
        int ans = slove(s);
        if (ans == -1) {
            cout << "error" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}