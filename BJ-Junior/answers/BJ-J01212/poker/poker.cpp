#include<bits/stdc++.h>
using namespace std;
bool poker[100][100];
int main()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            poker[i][j]=0;
        }
    }
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        poker[(int)a][(int)b]=1;
    }
    int ans=0;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(poker[i][j]==1)
            {
                ans++;
            }
        }
    }
    cout<<52-ans;
    return 0;
}
