#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
bool have[4][13];

int change(char c)
{
    if(c=='D')
    {
        return 0;
    }
    if(c=='C')
    {
        return 1;
    }
    if(c=='H')
    {
        return 2;
    }
    if(c=='S')
    {
        return 3;
    }
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s[1]!='T'&&s[1]!='J'&&s[1]!='Q'&&s[1]!='K'&&s[1]!='A')
        {
            have[change(s[0])][s[1]-'0'-1]=1;
        }
        else
        {
            switch(s[1])
            {
                case 'T':{
                    have[change(s[0])][9]=1;
                    break;
                }
                case 'J':{
                    have[change(s[0])][10]=1;
                    break;
                }
                case 'Q':{
                    have[change(s[0])][11]=1;
                    break;
                }
                case 'K':{
                    have[change(s[0])][12]=1;
                    break;
                }
                case 'A':{
                    have[change(s[0])][0]=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(!have[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
