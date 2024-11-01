#include <bits/stdc++.h>
#define MAXN 100009
using namespace std;

int n;
int r[MAXN];

bool cmp(int a,int b)
{
	return a < b;
}

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	//cout<<"n="<<n<<endl;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1,cmp);
	int now = 1;
	int ans = n;
	for(int i=1;i<=n;i++){
		while(now <= n && (r[now] <= r[i] || i == now)){
			now++;
		}

		if(r[now] > r[i]){
			now++;
			ans--;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;

	
}
