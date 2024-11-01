#include<iostream>
using namespace std;
int n,ans;
string s;
int a[10][110];
int c1(char c)
{
    if(c=='D')
        return 1;
    if(c=='C')
        return 2;
    if(c=='H')
        return 3;
    if(c=='S')
        return 4;
}
int c2(char c)
{
    if('2'<=c&&c<='9')
        return c-'0';
    if(c=='A')
        return 1;
    if(c=='T')
        return 10;
    if(c=='J')
        return 11;
    if(c=='Q')
        return 12;
    if(c=='K')
        return 13;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        a[c1(s[0])][c2(s[1])]=1;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(!a[i][j])
                ans++;
    cout<<ans;
    return 0;
}

