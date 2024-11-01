#include<iostream>
#include<cstring>
using namespace std;
char a[55][5];
bool b[5][15];
int y;
void f(int x)
{
    if(a[x][1]>='0'&&a[x][1]<='9')
    {
        y=a[x][1]-'0';
    }
    else if(a[x][1]=='T')
    {
        y=10;
    }
     else if(a[x][1]=='J')
    {
        y=11;
    }
    else if(a[x][1]=='Q')
    {
        y=12;
    }
    else if(a[x][1]=='K')
    {
        y=13;
    }
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i][1]=='A')
        {
           a[i][1]='1';
        }
        if(a[i][0]=='D')
        {
            f(i);
            b[0][y]=1;
        }
        else if(a[i][0]=='C')
        {
            f(i);
            b[1][y]=1;
        }
        else if(a[i][0]=='H')
        {
            f(i);
            b[2][y]=1;
        }
        else if(a[i][0]=='S')
        {
            f(i);
            b[3][y]=1;
        }
    }
    int ans=0;
    for(int i=0;i<=3;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(b[i][j]==0)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}