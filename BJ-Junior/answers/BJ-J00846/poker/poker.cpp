#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
bool pok[5][14];
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='C')
        {
            if(s[1]<='9'&&s[1]>='2')pok[1][s[1]-'0']=true;
            if(s[1]=='T')pok[1][10]=true;
            if(s[1]=='J')pok[1][11]=true;
            if(s[1]=='Q')pok[1][12]=true;
            if(s[1]=='K')pok[1][13]=true;
            if(s[1]=='A')pok[1][1]=true;
        }
        if(s[0]=='S')
        {
            if(s[1]<='9'&&s[1]>='2')pok[2][s[1]-'0']=true;
            if(s[1]=='T')pok[2][10]=true;
            if(s[1]=='J')pok[2][11]=true;
            if(s[1]=='Q')pok[2][12]=true;
            if(s[1]=='K')pok[2][13]=true;
            if(s[1]=='A')pok[2][1]=true;
        }
        if(s[0]=='H')
        {
            if(s[1]<='9'&&s[1]>='2')pok[3][s[1]-'0']=true;
            if(s[1]=='T')pok[3][10]=true;
            if(s[1]=='J')pok[3][11]=true;
            if(s[1]=='Q')pok[3][12]=true;
            if(s[1]=='K')pok[3][13]=true;
            if(s[1]=='A')pok[3][1]=true;
        }
        if(s[0]=='D')
        {
            if(s[1]<='9'&&s[1]>='2')pok[4][s[1]-'0']=true;
            if(s[1]=='T')pok[4][10]=true;
            if(s[1]=='J')pok[4][11]=true;
            if(s[1]=='Q')pok[4][12]=true;
            if(s[1]=='K')pok[4][13]=true;
            if(s[1]=='A')pok[4][1]=true;
        }
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
        {
            if(pok[i][j]==true)
            {
                ans--;
            }
        }
    cout<<ans;
    return 0;
}
