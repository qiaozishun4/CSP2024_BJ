#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,i,a[100005],cnt[100005]={},ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    for(i=1;i<=n;i++)
    {
        //cout<<a[i]<<endl;
        int j=i-1;
        while(j>0&&cnt[a[j]]==0)
        {
            j--;
        }
        if(j)
        {
            if(cnt[a[i]]>=cnt[a[j]])
            {
                cnt[a[j]]=0;
            }
            else
            {
                cnt[a[i]]=0;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        //cout<<cnt[a[i]]<<endl;
        ans+=cnt[a[i]];
    }
    cout<<ans<<endl;
	return 0;
}
