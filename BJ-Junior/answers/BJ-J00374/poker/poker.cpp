#include<bits/stdc++.h>
using namespace std;
bool check[4][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op1,op2;
        char c1,c2;
        cin>>c1>>c2;
        if(c1=='D')op1=0;
        if(c1=='C')op1=1;
        if(c1=='H')op1=2;
        if(c1=='S')op1=3;
        if(c2=='A')op2=1;
        if(isdigit(c2))op2=c2-'0';
        if(c2=='T')op2=10;
        if(c2=='J')op2=11;
        if(c2=='Q')op2=12;
        if(c2=='K')op2=13;
        check[op1][op2]=1;
    }
    for(int i=0;i<4;i++)
        for(int j=1;j<=13;j++)
        {
            if(!check[i][j])ans++;
        }
    cout<<ans;
    return 0;
}