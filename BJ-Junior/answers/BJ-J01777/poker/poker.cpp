#include <bits/stdc++.h>
using namespace std;
int n,a[10][100],ans=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int m=0;m<n;m++)
    {
        char x,y;
        int i,j;
        cin>>x>>y;
        if(x=='D')
            i=0;
        if(x=='C')
            i=1;
        if(x=='H')
            i=2;
        if(x=='S')
            i=3;
        if(y=='A')
            j=1;
        if(y>='2'&&y<='9')
            j=y-'0';
        if(y=='T')
            j=10;
        if(y=='J')
            j=11;
        if(y=='Q')
            j=12;
        if(y=='K')
            j=13;
        a[i][j]++;
    }
    for(int i=0;i<4;i++)
        for(int j=1;j<=13;j++)
            if(a[i][j]==0)
                ans++;
    cout<<ans;
    return 0;
}
