#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int p[10][105];
//d-1 c-2 h-3 s-4
//t-10
string s;
int n;
int m[1005];
int ch[1005];
int cnt;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 2;i <= 9;i++)
        m[i]= i;
    m['T'] = 10;
    m['J']  = 11;
    m['Q'] = 12;
    m['K'] = 13;
    m['A'] = 1;
    ch['D'] = 1;
    ch['C'] = 2;
    ch['H'] = 3;
    ch['S'] = 4;
    char a,b;
    for(int i = 1;i <= n;i++)
    {
        cin >> s;
        if(s[1] > '0' && s[1] <= '9')
            p[ch[s[0]]][s[1] - '0']++;
        else p[ch[s[0]]][m[s[1]]]++;
    }
    int k  = 1;
    for(k = 1;k <= 4;k++)
    {
        for(int i = 1;i <= 13;i++)
            if(p[k][i] == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
