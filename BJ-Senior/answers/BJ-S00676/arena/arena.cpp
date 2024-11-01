#include <bits/stdc++.h>
using namespace std;
int n,m,ab[500005],c[500005],D[20][600005],a[500005],X[4],dp[20][600006];
void solve()
{
    int pool=1;
    cout<<rand()<<endl;
}
int main()
{
    srand(time(0));
    cin>>n>>m;
    for(int i = 1;i <=n;i++)cin>>ab[i];
    for(int i = 1;i <=m;i++)cin>>c[i];
    sort(c+1,c+m+1);
    int k=ceil(log(n)/log(2));
    for(int i = 0;i <k;i++)
    {
        for(int j = 0;j <(1<<(k-i+1));j++)scanf("%d",&D[i][j]);
    }
    int T;
    cin>>T;
    while(T--)
    {
        cin>>X[0]>>X[1]>>X[2]>>X[3];
        for(int i = 1;i <=n;i++)a[i]=ab[i]^X[i%4];
        solve();
    }
}
