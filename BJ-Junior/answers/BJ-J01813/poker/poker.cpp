#include <iostream>
using namespace std;
bool d[14],c[14],h[14],s[14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        string x;
        cin >> x;
        if(x[0] == 'D')
        {
            if(x[1] == 'A') d[1] = 1;
            else if(x[1] == 'J') d[11] = 1;
            else if(x[1] == 'Q') d[12] = 1;
            else if(x[1] == 'K') d[13] = 1;
            else d[x[i]-'0'] = 1;
        }
        else if(x[0] == 'C')
        {
            if(x[1] == 'A') c[1] = 1;
            else if(x[1] == 'J') c[11] = 1;
            else if(x[1] == 'Q') c[12] = 1;
            else if(x[1] == 'K') c[13] = 1;
            else c[x[i]-'0'] = 1;
        }
        else if(x[0] == 'h')
        {
            if(x[1] == 'A') h[1] = 1;
            else if(x[1] == 'J') h[11] = 1;
            else if(x[1] == 'Q') h[12] = 1;
            else if(x[1] == 'K') h[13] = 1;
            else h[x[i]-'0'] = 1;
        }
        else
        {
            if(x[1] == 'A') s[1] = 1;
            else if(x[1] == 'J') s[11] = 1;
            else if(x[1] == 'Q') s[12] = 1;
            else if(x[1] == 'K') s[13] = 1;
            else s[x[i]-'0'] = 1;
        }
    }
    int cnt = 52;
    for(int i = 1;i <= 13;++i)
    {
        cnt -= d[i] + c[i] + h[i] + s[i];
    }
    cout << cnt;
    return 0;
}
