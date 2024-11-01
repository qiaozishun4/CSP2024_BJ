#include<bits/stdc++.h>
using namespace std;
bool yon[10][20];
int n,ans=0;
string tem;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //da kai wen jian
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int hua,zhi;
        cin>>tem;
        if('9'>=tem[1]&&tem[1]>='2')
        {
            zhi=tem[1]-48;
        }
        else if(tem[1]=='A')
        {
            zhi=1;
        }
        else if(tem[1]=='T')
        {
            zhi=10;
        }
        else if(tem[1]=='J')
        {
            zhi=11;
        }
        else if(tem[1]=='Q')
        {
            zhi=12;
        }
        else if(tem[1]=='K')
        {
            zhi=13;
        }//chu li shu zi
        if(tem[0]=='D')
        {
            hua=1;
        }
        else  if(tem[0]=='C')
        {
            hua=2;
        }
        else  if(tem[0]=='H')
        {
            hua=3;
        }
        else  if(tem[0]=='S')
        {
            hua=4;
        }//chu li hua se
        yon[hua][zhi]=true;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(yon[i][j]==false)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

