#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	int maxs=0;
	for(int i=1;i<=n;i++){
		int r;
		scanf("%d",&r);
		t[r]++;
		maxs=max(maxs,r);
	}
	int ans=n;
	int m=0;
	//printf("%d",maxs);
	for(int i=1;i<=maxs;i++){
		if(t[i]){
			if(m>0){
				ans-=min(m,t[i]);
				m-=min(m,t[i]);
				//printf("%d\n",m);
			}
			m+=t[i];
		}
	}
	printf("%d",ans);
	return 0;
}