/**
 * Description:
 *  给出一个只包含左右括号的字符串，得分规则如下：
 *  每对括号的得分等于这对括号之间字符数量 +1 的平方。整个字符串的得分是所有括号对的得分之和。
 *  例如：对于这样一个字符串："()()"，两对括号的得分都是 1 ，总得分为 1+1=2。
 *  而对于这样一个字符串："(())"，最外层的括号内包含2个字符，所以这对括号得分为 (2+1)<2>=9。内层括号的分数是 1，总得分为 9+1=10。
 *  现在给你一个长度为 n、只包含括号的字符串 2≤n≤100000），计算其得分。
 *
 * Input:
 *  1行，字符串s
 *
 * Output:
 *  1 个整数，字符串的得分。
 *
 * Hints:
 *  s只包含左右括号，长度不超过10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
(())
 *
 *  output:
10
 *
 */

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<int> st;
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            int x = st.top();
            st.pop();
            ans += 1ll * (i - x) * (i - x);
        }
    }
    cout << ans << endl;
    return 0;
}