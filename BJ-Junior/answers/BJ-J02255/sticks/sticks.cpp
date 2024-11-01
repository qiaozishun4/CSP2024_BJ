#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#define endl "\n"
using namespace std;
int s[]={6,2,5,5,4,5,6,3,7,6};
int m[]={-1,-1,1,7,4,2,0,8,-1,-1,-1};
unordered_map<int,unordered_map<int,unordered_map<int,int> > > sum;
const int maxn=7;
void init()
{
    for(int k=0;k<=10;k++)
    {
        for(int i=0;i<=k;i++)
        {
            sum[i][i][k]=i;
            for(int j=i+1;j<=k;j++)
            {
                if(m[j]<sum[i][j-1][k])sum[i][j][k]=j;
                else sum[i][j][k]=sum[i][j-1][k];
            }
        }
    }
}
void solve()
{
    int n;
    string ans="";
    cin>>n;
    if(n<2)
    {
        cout<<-1<<endl;
        return;
    }
    int w=n/maxn;
    if(maxn*w!=n)w++;
    m[6]=6;
    for(int i=1;i<=w;i++)
    {
        if(i==2)m[6]=0;
        if(i==1||i==2)init();
        int l=max(2,n-(w-i)*7),r=min(7,n-(w-i)*2);
        int no=sum[l][r][min(n,10)];
        if(m[no]==-1)return;
        ans+=(m[no]+'0');
        n-=no;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
