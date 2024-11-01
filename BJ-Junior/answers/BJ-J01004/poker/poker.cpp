#include<iostream>
#include<string>
using namespace std;
bool a[11][20];
int ans=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=18;j++)
            a[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int x,y;
        if(s[0]=='D')x=1;
        if(s[0]=='C')x=2;
        if(s[0]=='H')x=3;
        if(s[0]=='S')x=4;
        if(s[1]>='1' && s[1]<='9')y=s[1]-'0';
        else
        {
            if(s[1]=='A')y=1;
            if(s[1]=='T')y=10;
            if(s[1]=='J')y=11;
            if(s[1]=='Q')y=12;
            if(s[1]=='K')y=13;
        }
        a[x][y]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!a[i][j])ans++;
        }
    }
    cout<<ans;
    return 0;
}
