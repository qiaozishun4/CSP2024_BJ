#include<bits/stdc++.h>
using namespace std;
string a;
bool b[10][100];
long long n,tmp1,tmp2,ans=0;
void change(string c)
{
    if(c[0]=='D')
        tmp1=1;
     if(c[0]=='C')
        tmp1=2;
    if(c[0]=='H')
        tmp1=3;
    if(c[0]=='S')
        tmp1=4;
    if(c[1]=='A')
        tmp2=1;
    if(c[1]=='2')
        tmp2=2;
    if(c[1]=='3')
        tmp2=3;
    if(c[1]=='4')
        tmp2=4;
    if(c[1]=='5')
        tmp2=5;
    if(c[1]=='6')
        tmp2=6;
    if(c[1]=='7')
        tmp2=7;
    if(c[1]=='8')
        tmp2=8;
    if(c[1]=='9')
        tmp2=9;
    if(c[1]=='T')
        tmp2=10;
    if(c[1]=='J')
        tmp2=11;
    if(c[1]=='Q')
        tmp2=12;
    if(c[1]=='K')
        tmp2=13;
    return;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        change(a);
        b[tmp1][tmp2]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(b[i][j]==0)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
