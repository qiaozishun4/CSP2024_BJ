#include <bits/stdc++.h>
using namespace std;
map<char,int> m;
bool p[10][99];
int n,ans=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    m['D']=1;
    m['C']=2;
    m['H']=3;
    m['S']=4;
    m['A']=1;
    m['2']=2;
    m['3']=3;
    m['4']=4;
    m['5']=5;
    m['6']=6;
    m['7']=7;
    m['8']=8;
    m['9']=9;
    m['T']=10;
    m['J']=11;
    m['Q']=12;
    m['K']=13;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char t1,t2;
        cin>>t1>>t2;
        p[m[t1]][m[t2]]=true;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!p[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
