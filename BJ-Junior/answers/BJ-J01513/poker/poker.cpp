#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,a[14][5]={};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char c,t;
        cin>>c>>t;
        int k,p;
        if(c=='D')
        {
            k=1;

        }
        if(c=='C')
        {
            k=2;

        }
        if(c=='H')
        {
            k=3;

        }
        if(c=='S')
        {
            k=4;

        }
        if(t=='A')
        {
            p=1;

        }
        if(t=='2')
        {
            p=2;

        }
        if(t=='3')
        {
            p=3;

        }
        if(t=='4')
        {
            p=4;

        }
        if(t=='5')
        {
            p=5;

        }
        if(t=='6')
        {
            p=6;

        }
        if(t=='7')
        {
            p=7;

        }
        if(t=='8')
        {
            p=8;

        }
        if(t=='9')
        {
            p=9;

        }
        if(t=='T')
        {
            p=10;

        }
        if(t=='J')
        {
            p=11;

        }
        if(t=='Q')
        {
            p=12;

        }
        if(t=='K')
        {
            p=13;
        }
        a[p][k]=1;
    }
    int ans=0;
    for(int i=1;i<=13;i++)
    {
        for(int j=1;j<=4;j++)
        {
            ans=ans+1-a[i][j];
        }
    }
    cout<<ans;
    return 0;
}
