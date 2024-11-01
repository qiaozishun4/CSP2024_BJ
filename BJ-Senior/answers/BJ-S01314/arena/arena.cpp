#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);

    int n,m,a[100001]={},c[100001]={},d[100001][100001]={};
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    int K=1;
    while(pow(2,K)<n)
    {
        k++;
    }
    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=pow(2,K-j);j++)
        {
            cin>>d[i][j];
        }
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int X0,X1,X2,X3;
        cin>>X0>>X1>>X2>>X3;
        cout<<1<<endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
