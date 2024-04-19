/**
 * Description:
 *  给定一个含n个名字的名单列表，接下来有m次点名。
 *  对于一次点名：
 *  如果这个名字第一次被点到，输出"OK"
 *  如果这个名字已经被点到过，输出"REPEAT"
 *  如果这个名字不在给定的名单中，输出"WRONG"
 *
 * Input:
 *  第一行一个整数n(1≤n≤10<4>)，表示名单中名字的个数。
 *  接下来n行，每行一个字符串si(1<=|si|≤50)，si表示名单中第i个名字（si两两不同）。
 *  第n+2行一个整数m(1≤m≤10<5>)，表示有m次点名。
 *  接下来m行，每行一个字符串si，表示第i次点名的名字。
 *
 * Output:
 *  输出m行，对于一次点名，输出一行，为"OK"或者"WRONG"或者"REPEAT"。（不包含双引号）
 *
 * Hints:
 *  1<=n<=1000; 1<=a<=10<6>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
alice
bob
jack
ray
sucy
3
bob
www
bob
 *
 *  output:
OK
WRONG
REPEAT
 *
 */

#include <iostream>
#include <map>
using namespace std;
int n, m;
string s;
map<string, int> mp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        mp[s] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s;
        if (mp.count(s) == 0) {
            cout << "WRONG" << endl;
        } else {
            if (mp[s] == 1) {
                cout << "OK" << endl;
                mp[s] = 0;
            } else {
                cout << "REPEAT" << endl;
            }
        }
    }
    return 0;
}