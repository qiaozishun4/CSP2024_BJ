#include<iostream>
using namespace std;
int n,a[6][15]={};
long long ans=0;
int type=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    char x,y;
    int i,j;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        if(x=='D')
            type=1;
        if(x=='C')
            type=2;
        if(x=='H')
            type=3;
        if(x=='S')
            type=4;

        if(y>='2'&&y<='9')
            a[type][y-'0']=1;
        else
        {
            if(y=='A')
                a[type][1]=1;
            if(y=='T')
                a[type][10]=1;
            if(y=='J')
                a[type][11]=1;
            if(y=='Q')
                a[type][12]=1;
            if(y=='K')
                a[type][13]=1;
        }

    }
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=13;j++)
        {
            if(a[i][j]==0)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
