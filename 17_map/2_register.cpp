/**
 * Description:
 *  你接到了一个设计注册系统的任务，需要根据如下要求实现这个注册系统。
 *  每当一个用户想要注册，他会向系统发送一个字符串name要求注册，如果这个name在系统数据库中不存在，那么就会将name插入到系统数据库中，并给用户返回OK表示注册成功。
 *  如果name已经在系统数据库中存在，那么系统会生成一个新的用户名，将其插入数据库并返回给用户。
 *  新的用户名按照如下规则生成：数字i从1开始，会一个接一个地添加到name后面，形成name1，name2
 * ......系统会找到一个最小的i(i≥1)，使得namei不在数据库中，将namei作为生成的新用户名。
 *
 * Input:
 *  第一行一个整数n(1≤n≤10<5>)，表示有n个注册请求。
 *  接下来n行，每行一个字符串si，表示用户向系统提交的用户名。
 *  数据保证：1<=|si|≤32，且si仅由小写字母组成。
 *
 * Output:
 *  n行，如果用户名成功注册，输出"OK"，否则输出系统返回给用户的用户名。
 *
 * Hints:
 *  1<=n<=1000; 1<=a<=10<6>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
abacaba
acaba
abacaba
acab
 *
 *  output:
OK
OK
abacaba1
OK
 *
 *  2):
 *  input:
5
first
first
first
second
second
 *
 *  output:
OK
first1
first2
OK
second1
 *
 */

#include <iostream>
#include <map>
using namespace std;
int n;
map<string, int> mp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (mp.count(s) == 0) {
            cout << "OK" << endl;
            mp[s] = 1;
        } else {
            cout << s << mp[s] << endl;
            mp[s]++;
        }
    }
    return 0;
}