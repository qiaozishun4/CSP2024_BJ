#include <cstdio>
#include <iostream>
using namespace std;
string s;
bool a[5][15];
int n;
void f(int x)
{
    if('2' <= s[1] && s[1] <= '9')
    {
        a[1][s[1] - '0'] = 1;
    }
    else{
        char c = s[1];
        if(c == 'A') a[x][1] = 1;
        else if(c == 'T') a[x][10] = 1;
        else if(c == 'J') a[x][11] = 1;
        else if(c == 'Q') a[x][12] = 1;
        else a[x][13] = 1;
    }
    return;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        if(s[0] == 'D') f(1);
        if(s[0] == 'C') f(2);
        if(s[0] == 'H') f(3);
        if(s[0] == 'S') f(4);
    }
    int cnt = 0;
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 13; j++)
        {
            if(!a[i][j]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
