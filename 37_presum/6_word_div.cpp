/**
 * Description:
 *  有一个很长的由小写字母组成字符串。为了便于对这个字符串进行分析，需要将它划分成若干个部分，每个部分都必须是字典中的一个单词。 出于减少分析量的目的，我们希望划分出的单词数越少越好。 你就是来完成这一划分工作的。
 *  给出字符串和字典，输出最少的划分单词数。
 *
 * Input:
 *  第1行，1个字符串。（字符串的长度不超过1000）
 *  第2行，1个整数n，表示字典中单词的个数。（n≤100）
 *  第3到n+2行，每行列出一个字典中的单词。（单词长度不超过100）
 *
 * Output:
 *  输出最少的划分单词数。
 *
 * Hints:
 *  1≤n,ai≤1000, 1≤s≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
realityour
5
real
reality
it
your
our
 *
 *  output:
2
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

string s, t[110];
int n, f[1010];
// f[i] 表示以 s[i] 结尾的子串的最少的单词数

int main()
{
    cin >> s >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    int m = s.size();
    s = ' ' + s;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int len = t[j].size();
            if (i >= len && s.substr(i - len + 1, len) == t[j]) {
                f[i] = min(f[i], f[i - len] + 1);
            }
        }
    }
    
    cout << f[m] << endl;

    return 0;
}