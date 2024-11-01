#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5;
int n,m,r[N+1],ans;
struct node
{
	int att,rem,ocp;
}mon[N+1];
int main()
{
	ios::sync_with_stdio(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int i,j=1;
	cin>>n;
	ans=n;
	for(i=1;i<=n;i++)
		cin>>r[i];
	sort(r+1,r+n+1);
	for(i=1;i<=n;i++)
	{
		if(mon[m].att<r[i])
			mon[++m].att=r[i];
		mon[m].rem++;
	}
	for(i=1;i<m;i++)
	{
		if(mon[i].att>=mon[j].att)
			j++;
		for(j;j<=m;j++)
		{
			if(mon[j].rem-mon[j].ocp>=mon[i].rem)
			{
				mon[j].ocp+=mon[i].rem;
				ans-=mon[i].rem;
				mon[i].rem=0;
				break;
			}
			else
			{
				mon[i].rem-=mon[j].rem-mon[j].ocp;
				ans-=mon[j].rem-mon[j].ocp;
				mon[j].ocp=mon[j].rem;
			}
		}
	}
	cout<<ans;
	return 0;
}