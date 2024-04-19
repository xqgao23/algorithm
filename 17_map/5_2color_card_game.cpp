/**
 * Description:
 *  高桥君有蓝色卡片N张, 红色卡片M张. 每张卡上都写了一个单词.
 *  高桥君宣言一个单词, 然后确认所有卡片,
 * 每有一张蓝色卡片上的单词和宣言的单词完全相同 , 就得+1分.
 * 每有一张红色卡片上的单词和宣言的单词完全相同, 就得−1分.
 *  高桥君最多可以得到多少分?
 *
 * Input:
 *  第1行, 一个正整数N, 表示蓝色卡片数量
 *  接下来N行, 每行一个字符串, 表示蓝色卡片上写的单词
 *  第N+2行, 一个正整数M, 表示红色卡片数量
 *  接下来M行, 每行一个字符串, 表示红色卡片上写的单词
 *
 * Output:
 *  输出一个整数, 高桥君可以得到的最高分
 *
 * Hints:
 *  1≤N,M≤10<5>，所有字符串只包含小写英文字母, 长度不超过10
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
apple
orange
apple
5
apple
apple
apple
apple
apple
 *
 *  output:
1
 *
 *  2):
 *  input:
1
voldemort
2
voldemort
voldemort
 *
 *  output:
0
 *
 *  3):
 *  input:
6
red
red
blue
yellow
yellow
red
5
red
red
yellow
green
blue
 *
 *  output:
1
 *
 */

#include <iostream>
#include <map>
using namespace std;
int n, m;
map<string, int> mp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        mp[s]--;
    }
    int ans = 0;
    for (auto it : mp) {
        ans = max(ans, it.second);
    }
    cout << ans << endl;
    return 0;
}