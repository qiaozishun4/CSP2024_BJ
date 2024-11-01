#include <bits/stdc++.h>
#define MAXN 100009
using namespace std;

//16:41 |有点崩溃 天煞的吵闹小屁孩啊啊啊啊啊
//


int T,n;
int A[MAXN];
bool c[MAXN];
int ans = 0;
const int inf = INT_MAX;

void Check()
{
	int tot = 0;
	int Z[MAXN],O[MAXN];
	Z[1] = inf;
	O[1] = inf;
	for(int i=2;i<=n;i++)
	{
		if(c[i-1] == 0)
		{
			Z[i] = i-1;
			O[i] = O[i-1];
		}
		else
		{
			Z[i] = Z[i-1];
			O[i] = i-1;
		}
		if(c[i] == 1)
		{
			if(O[i] == inf)
				continue;
			if(A[O[i]] == A[i])
				tot += A[i];
		}
		else
		{
			if(Z[i] == inf)
				continue;
			if(A[Z[i]] == A[i])
				tot += A[i];
		}
	}
	ans = max(ans,tot);
}


int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int turn = 1;turn <= T;turn++)
	{
		ans = 0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>A[i];
		}
		for(int i=0;i<pow(2,n);i++)
		{
			//cout<<"Debug:"<<i<<" of "<<pow(2,n)<<endl;
			int now = 1;
			int I = i;
			while(I > 0)
			{
				c[now] = i%2;
				I /= 2;
				now++;
			}
			Check();
		}
		cout<<ans<<endl;
	}
	return 0;
}