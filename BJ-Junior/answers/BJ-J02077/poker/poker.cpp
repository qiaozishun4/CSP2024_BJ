#include<bits/stdc++.h>
using namespace std;
int a[5][15];
char p[3];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    int hua=0,shu=0;
    for(int i=1;i<=n;i++)
    {
        hua=0;
        shu=0;
        cin>>p[1]>>p[2];
        if(p[1]=='D')
        {
            hua=1;
        }
        else if(p[1]=='C')
        {
            hua=2;
        }
        else if(p[1]=='H')
        {
            hua=3;
        }
        else
        {
            hua=4;
        }
        if(p[2]=='A')
        {
            shu=1;
        }
        else if(p[2]=='T')
        {
            shu=10;
        }
        else if(p[2]=='J')
        {
            shu=11;
        }
        else if(p[2]=='Q')
        {
            shu=12;
        }
        else if(p[2]=='K')
        {
            shu=13;
        }
        else
        {
            shu=p[2]-48;
        }
        a[hua][shu]=1;
    }
    int sum=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==0)
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}

