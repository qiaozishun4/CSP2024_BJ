#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    int a[5][14]={};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int zans=0;
        string c;
        cin>>c;
        if(c[1]=='A')zans=1;
        if(c[1]=='2')zans=2;
        if(c[1]=='3')zans=3;
        if(c[1]=='4')zans=4;
        if(c[1]=='5')zans=5;
        if(c[1]=='6')zans=6;
        if(c[1]=='7')zans=7;
        if(c[1]=='8')zans=8;
        if(c[1]=='9')zans=9;
        if(c[1]=='T')zans=10;
        if(c[1]=='J')zans=11;
        if(c[1]=='Q')zans=12;
        if(c[1]=='K')zans=13;
        if(c[0]=='S')a[4][zans]++;
        if(c[0]=='H')a[3][zans]++;
        if(c[0]=='C')a[2][zans]++;
        if(c[0]=='D')a[1][zans]++;
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==0)
            {
                cnt++;
            }
        }
    }
    if(cnt>0)
    {
        cout<<cnt;
    }
    if(cnt==0)
    {
        cout<<0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
