//#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;
int T,n,lstpos[1000006];//,lst[200005];
long long a[200005],dp[200005][2],sum[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            lstpos[a[i]]=0;
            //lst[i]=0;
            if(i!=1&&a[i]==a[i-1])
                sum[i]=sum[i-1]+a[i];
            else
                sum[i]=sum[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i][1]=0;
            if(lstpos[a[i]])
            {
                if(lstpos[a[i]]==i-1)
                {
                    //cout<<"***"<<" "<<dp[lstpos[a[i]]][0]<<endl;
                    dp[i][0]=max(dp[i][0],max(dp[lstpos[a[i]]][0],dp[lstpos[a[i]]][1])+a[i]);//color unchanged
                }
                else//i-1>=lstpos[a[i]]+1
                {
                    dp[i][1]=max(dp[i][1],dp[lstpos[a[i]]+1][1]+a[i]+sum[i-1]-sum[lstpos[a[i]]+1]);//C_lst[a[i]]=?
                }
                //lst[i]=lstpos[a[i]];
            }
            dp[i][0]=max(dp[i][0],max(dp[i-1][0],dp[i-1][1]));
            dp[i][1]=max(dp[i][1],max(dp[i-1][0],dp[i-1][1]));
            //cout<<a[i]<<",";
            lstpos[a[i]]=i;
            //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        cout<<max(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}
