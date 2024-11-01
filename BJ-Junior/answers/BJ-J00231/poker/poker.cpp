#include<bits/stdc++.h>
using namespace std;
bool f[8][58];
int n,cnt;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        int k,t;
        if(s[0]=='D') 
        {
            k=1;
        }
        else if(s[0]=='C')
        {
            k=2;
        }
        else if(s[0]=='H')
        {
            k=3;
        }
        else 
        {
            k=4;
        }
        if(s[1]>='J') t=s[1]-'A'+1;
        else if(s[1]=='A') t=1;
        else t=s[1]-'0';
        if(!f[k][t]) cnt++;
        f[k][t]=true;
    }
    cout<<52-cnt;
    return 0;
}