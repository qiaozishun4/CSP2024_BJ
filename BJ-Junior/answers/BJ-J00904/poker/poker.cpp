#include<bits/stdc++.h>
using namespace std;

int n,ans=52;
bool vis[60];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        string s ;
        cin >> s ;
        int num=0;
        if(s[1]=='A')
            num=1;
        else if(s[1]=='T')
            num=10;
        else if(s[1]=='J')
            num=11;
        else if(s[1]=='Q')
            num=12;
        else if(s[1]=='K')
            num=13;
        else
            num=(int)s[1]-'0';
        if(s[0]=='C')
            num+=13;
        else if(s[0]=='H')
            num+=26;
        else if(s[0]=='S')
            num+=39;
        if(!vis[num])
        {
            ans--;
            vis[num]=1;
        }
    }
    cout << ans << endl ;
    return 0 ;
}