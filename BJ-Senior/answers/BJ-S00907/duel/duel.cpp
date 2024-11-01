#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int n,a[N];
bool vis[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int r=1,cnt=0;
	for(i=1;i<=n;i++){
		while(r<=n&&(a[r]<=a[i]||vis[r])){
			r++;
		}
		if(r<=n&&a[r]>a[i]) {
			cnt++;
			vis[r]=1;
		}
	}
	printf("%d\n",n-cnt);
	return 0;
}
