/**
 * Description:
 *  有了防护伞，也并不能完全避免 2012 的灾难。地球防卫小队决定去求助外星种族的帮 助。经过很长时间的努力，小队终于收到了外星生命的回信。但是外星人发过来的却是一 串密码。只有解开密码，才能知道外星人给的准确回复。
 *  解开密码的第一道工序就是解压缩密码，外星人对于连续的若干个相同的子串"X"会压缩为"[DX]"的形式（D是一个整数且1≤D≤99 ），比如说字符串"CBCBCBCB"就压缩为"[4CB]"或者"[2[2CB]]"，类 似于后面这种压缩之后再压缩的称为二重压缩。如果是"[2[2[2CB]]]"则是三重的。
 *  现 在我们给你外星人发送的密码，请你对其进行解压缩。
 *
 * Input:
 *  一行：一个字符串，表示外星人发送过来的密码
 *
 * Output:
 *  一行：一个字符串，表示解压后的密码
 *
 * Hints:
 *  解压后的字符串长度在 20000 以内，最多只有十重压缩。保证只包含数字、大写字母、[ 和 ]
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
AC[3FUN]
 *
 *  output:
ACFUNFUNFUN
 *
 *  2):
 *  input:
NI[2[2CONI]]
 *
 *  output:
NICONICONICONICONI
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

string dfs()
{
    string s, t;
    char ch;
    int n;
    while (ch = cin.get()) {
        if (ch == '\n') {
            break;
        }
        if (ch == ' ') {
            continue;
        }
        
        if (ch == '[') {
            cin >> n;
            t = dfs();
            while (n--) {
                s += t;
            }
        } else if (ch == ']') {
            return s;
        } else {
            s += ch;
        }
    }
    return s;
}

int main()
{
    cout << dfs() << endl;
    return 0;
}