#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;
int n,t,clr[MAXN],num[MAXN],asw;
void check() {
	int sum=0;
	for (int i=1;i<=n;i++) {
		for (int j=i-1;j>0;j--) {
			if (clr[i]==clr[j]) {
				if (num[i]==num[j]) {
					sum+=num[i];
				}
				break;
			}
		}
	}
	asw=max(asw,sum);
}
void dfs(int rd) {
	if (rd>=n) {
		check();
		return;
	}
	clr[rd]=1;
	dfs(rd+1);
	clr[rd]=0;
	dfs(rd+1);
	return;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",num+i);
		}
		asw=0;
		dfs(0);
		printf("%d\n",asw);
	}
	return 0;
}
