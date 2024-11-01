#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
char a[105][15],b[105]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int u[150][150];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        u[a[i][0]][a[i][1]]=1;
    }
    //
    //for(int i=1;i<=n;i++) cout<<a[i]<<endl;
    char tmp;
    for(int i=1;i<=4;i++)
    {
        if(i==1) tmp='D';
        if(i==2) tmp='C';
        if(i==3) tmp='H';
        if(i==4) tmp='S';
        for(int j=1;j<=13;j++)
        {
            if(u[tmp][b[j]]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
