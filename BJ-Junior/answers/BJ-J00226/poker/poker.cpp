#include <bits/stdc++.h>
using namespace std;
int n;
int a[500][500];
int cnt;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        int p,q;
        if(x[0]=='D')
            p=1;
        else if(x[0]=='C')
            p=2;
        else if(x[0]=='H')
            p=3;
        else if(x[0]=='S')
            p=4;
        else
            p=int(x[0])-'0';
        if(x[1]=='A')
            q=1;
        else if(x[1]=='T')
            q=10;
        else if(x[1]=='J')
            q=11;
        else if(x[1]=='Q')
            q=12;
        else if(x[1]=='K')
            q=13;
        else
            q=int(x[1])-'0';
        a[p][q]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==0)
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
