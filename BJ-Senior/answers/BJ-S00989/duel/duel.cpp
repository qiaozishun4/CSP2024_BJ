#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int PP=100005;
int n,cnt[PP],ans;
bool vist[PP];
vector< vector<int> > t;
void esc()
{
    vector<int> temp;
    for(int i=0;i<=n;i++) t.push_back(temp);
    return;
}
void dag(int m)
{
    bool flag=0;
    for(int i=0;i<t[m].size();i++)
    {
        int ii=t[m][i];
        if(cnt[ii]==0) dag(ii);
        if(cnt[m]<cnt[ii]+1) cnt[m]=cnt[ii]+1;
        flag=1;
    }
    if(flag==0)
    {
        cnt[m]=1;
        return;
    }
    if(ans<cnt[m]) ans=cnt[m];
    return;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    esc();
    for(int i=1;i<=n;i++) cin>>cnt[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(cnt[i]>cnt[j])
            {
                t[i].push_back(j);
                vist[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) if(vist[i]==0) dag(i);
    cout<<n-ans;
    return 0;
}
