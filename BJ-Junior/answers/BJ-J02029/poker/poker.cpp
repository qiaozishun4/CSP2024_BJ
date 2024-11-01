#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,ans;
int z[14][5];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ans=0;
    cin >>n;
    for(int i=1;i<=13;i++)
    {
        for(int j=1;j<=4;j++)
            z[i][j]=0;
    }
    while(n--)
    {
        char a,b;
        cin >>a >>b;
        int k;
        if(b>='2' &&b<='9')
            k=b-'0';
        if(b=='T')
            k=10;
        else if(b=='A')
            k=1;
        else if(b=='J')
            k=11;
        else if(b=='Q')
            k=12;
        else if(b=='K')
            k=13;
        if(a=='D')
            z[k][1]++;
        else if(a=='C')
            z[k][2]++;
        else if(a=='H')
            z[k][3]++;
        else if(a=='S')
            z[k][4]++;
    }
    for(int i=1;i<=13;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(z[i][j]==0)
                ans++;
        }
    }
    cout <<ans;
}
