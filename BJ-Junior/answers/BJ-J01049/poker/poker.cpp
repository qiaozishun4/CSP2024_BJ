#include<bits/stdc++.h>
using namespace std;
bool f[1000];

int c1(char x)
{
    if(x == 'A') return 1;
    if(x == 'T') return 10;
    if(x == 'J') return 11;
    if(x == 'Q') return 12;
    if(x == 'K') return 13;
    if(x <= '9' && x >= '0') return x-'0';

}

int c2(char x)
{
    if(x == 'D') return 1;
    if(x == 'C') return 2;
    if(x == 'H') return 3;
    if(x == 'S') return 4;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        char a,b;
        cin >> a >> b;
        f[(c1(b)-1)*4+c2(a)] = 1;
    }
    int cnt = 0;
    for(int i = 1;i <= 52;i++)
    {
        if(!f[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
