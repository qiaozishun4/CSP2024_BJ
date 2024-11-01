#include<bits/stdc++.h>
using namespace std;
int a[6][22];
char b[14]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char hs,ds;//huase dianshu
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>hs>>ds;
        for(int j=1;j<=13;j++)
        {
            if(b[j]==ds)
            {
                if(hs=='D')
                {
                    a[1][j]=1;
                }
                else if(hs=='C')
                {
                    a[2][j]=1;
                }
                else if(hs=='H')
                {
                    a[3][j]=1;
                }
                else if(hs=='S')
                {
                    a[4][j]=1;
                }
                break;
            }
        }
    }
    int ans=52;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==1)
            {
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}
