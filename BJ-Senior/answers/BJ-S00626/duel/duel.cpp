#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cnt[100010];
vector<int>num;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,tmp;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        if(cnt[tmp]==0)
        {
            num.push_back(tmp);
        }
        cnt[tmp]++;
    }
    int ans=0;
    for(int i:num)
    {
        ans=max(ans,cnt[i]);
    }
    cout<<ans;
    return 0;
}