#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#define MAXN 100010
using namespace std;
int n,r[MAXN],asw=11451419;
vector<int> bettc[MAXN];
vector<pair<int,int>> vec;
bitset<MAXN> attd;
void pdebug() {
	puts("Here is log:");
	for (auto each:vec) {
		printf("%d attack %d\n",each.first,each.second);
	}
}
void dfs(int p,int lft) {
	//printf("dfs p=%d,lft=%d\n",p,lft);
	if (p>=n) {
		//pdebug();
		asw=min(asw,lft);
		return;
	}
	if (attd[p]) {
		dfs(p+1,lft);
		return;
	}
	for (int tgt:bettc[p]) {
		vec.push_back(make_pair(p,tgt));
		if (r[p]>r[tgt]) { // 击败怪兽
			attd[tgt]=1;
			dfs(p+1,lft-1);
			attd[tgt]=0;
		} else {
			dfs(p+1,lft);
		}
		vec.pop_back();
	}
	return;
}
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",r+i);
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (i!=j) {
				bettc[i].push_back(j);
			}
		}
		sort(bettc[i].begin(),bettc[i].end(),[i](int a,int b)->bool{return r[i]-r[a]>r[i]-r[b];});
	}
	dfs(0,n);
	printf("%d",asw);
	return 0;
}
