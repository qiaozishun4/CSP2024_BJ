#include<bits/stdc++.h>
using namespace std;

int n,ans=52;
char fa[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'},fb[4]={'D','C','H','S'};
int a[20][10]={0};

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<=12;j++)
        {
            for(int k=0;k<=3;k++)
            {
                if(s[1]==fa[j]&&s[0]==fb[k])
                {
                    a[j][k]=1;
                }
            }
        }
    }
    for(int i=0;i<=12;i++)
    {
        for(int j=0;j<=3;j++)
        {
            if(a[i][j])
            {
                ans--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
