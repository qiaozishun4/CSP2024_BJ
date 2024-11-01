#include<bits/stdc++.h>
using namespace std;
char a[55][4];
int c[85][84];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,t;
    cin>>n;
    t=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {
            cin>>a[i][j];
        }
        if(c[a[i][1]][a[i][2]] == 1)
        {
            t--;
        }
        else
        {
            c[a[i][1]][a[i][2]]=1;
        }
    }
    cout<<52-t;
    return 0;
}