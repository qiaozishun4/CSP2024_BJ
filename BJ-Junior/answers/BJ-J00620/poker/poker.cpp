#include <bits/stdc++.h>//Finally, U Can Know China Computer Foundation
using namespace std;
//桶排序
char s1[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
char s2[] = {'D', 'C', 'H', 'S'};
map <string, int> tong;
int cnt;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (; n; n --)
    {
        string s;
        cin >> s;
        tong[s] ++;
        //cout << tong[s] << ' ';
    }
    for(int i = 0; i < 13; i ++)
    {
        for (int j = 0; j < 4; j ++)
        {

            string s = "";
            s += s2[j];
            s += s1[i];
            //cout << s << ' ' << bool(tong[s]) << ' ';
            cnt += bool(tong[s]);
            //cout << cnt << endl;
        }
    }
    cout << 52 - cnt << endl;
    return 0;
}
