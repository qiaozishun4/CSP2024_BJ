#include<bits/stdc++.h>
using namespace std;
int n;
string ss[55];
bool vis[55];
int cnt=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i  =1; i <= n; i++)
    {
        string s;
        cin >> s;
        bool f=0;
        for(int i  =1; i <= cnt; i++)
        {
            if(s==ss[i])
            {
                f=1;
            }
        }
        if(!f)ss[++cnt]=s;
    }
    cout << 52-cnt;
    return 0;
}
