#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;
int t,n,m,k;
int pre[MAXN],a[MAXN],c[MAXN],d[10000][10000],x[4],asw;
char buff[MAXN];
int leitasai(int lr,int p,int g) {
	if (lr==0) {
		return a[p];
	}
	int l=leitasai(lr-1,p,1),r=leitasai(lr-1,p+(1<<(lr-1)),2);
	if (d[lr][g]) {
		if (a[r]>lr) {
			return r;
		} else {
			return l;
		}
	}
	if (a[l]>lr) {
		return l;
	}
	return r;
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%d",pre+i);
	}
	for (int i=1;i<=m;i++) {
		scanf("%d",c+i);
	}
	while ((1<<k)<n) {
		k++;
	}
	for (int i=0;i<k;i++) {
		scanf("%s",buff);
		for (int j=0;j<(1<<(k-i+1));j++) {
			d[i][j]=buff[j]-'0';
		}
	}
	scanf("%d",&t);
	while (t--) {
		for (int i=0;i<4;i++) {
			scanf("%d",x+i);
		}
		for (int i=0;i<n;i++) {
			a[i]=pre[i]^(x[(i+1)%4]);
		}
		sort(c+1,c+1+m);
		asw=0;
		for (int i=1;i<=m;i++) {
			int num=c[i],zr=0;
			while ((1<<zr)<num) zr++;
			asw^=i*leitasai(zr,0,1);
		}
		printf("%d\n",asw);
	}
	return 0;
}			
