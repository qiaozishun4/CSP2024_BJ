#include<bits/stdc++.h>
using namespace std;
char m[5][60];
int n,sum=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    sum-=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=1;j++)
            cin>>m[j][i];
    }
    for(int i=1;i<=n;i++)
    {
        int flag=0;
        for(int j=i-1;j>=1;j--)
        {
             if(m[0][j]==m[0][i]&&m[1][j]==m[1][i])
             {
                flag=1;
                break;
            }
        }
        if(flag==1) sum++;
    }
    cout<<sum;
    return 0;
}
