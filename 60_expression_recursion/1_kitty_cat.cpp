/**
 * Description:
 *  小可可选修了基础生物基因学。教授告诉大家 Super Samuel 星球上 Kitty猫的基因的长度都是 2 的正整数次幂 )， 全是由两种不同的基因单元组成的。 这两种不同的基因单元分别记成 0 和 1，于是 Kitty 猫基因可以写成一个 01 串表达式 。
 *  为了便于分析和降低数据存储量，教授发明了 ABC 编码规则。该编码规则是不断地按照以下规则对 Kitty 猫基因 01 串表达式 进行改写， 直至最终被改写成只含有字符 “A”、“B”、“C”的符号串。
 *  T(s) = 1) A	若 s 串全是 0
 *       = 2) B 若 s 串全是 1
 *       = 3) CT(s1)T(s2)，否则把s串分成两个等长子串s1，s2
 *  T(01001011) =CT(0100)T(1011)
 *              =CCT(01)T(00)CT(10)T(11)
 *              =CCCT(0)T(1)ACCT(1)T(0)B
 *              =CCCABACCBAB
 *
 * Input:
 *  一行，一个字符串s
 *
 * Output:
 *  一行，输出 s 的ABC编码
 *
 * Hints:
 *  字符串s 只含字符0和1。长度一定是2<k>, k<=20
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
00
 *
 *  output:
A
 *
 *  2):
 *  input:
01001011
 *
 *  output:
CCCABACCBAB
 *
 */

#include <iostream>
using namespace std;

void dfs(string s)
{
    if (s.find('0') == -1) {
        cout << 'B';
        return;
    }
    if (s.find('1') == -1) {
        cout << 'A';
        return;
    }
    cout << 'C';
    dfs(s.substr(0, s.size() / 2));
    dfs(s.substr(s.size() / 2));
}

int main()
{
    string s;
    cin >> s;
    dfs(s);
    return 0;
}