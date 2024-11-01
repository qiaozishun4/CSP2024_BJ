#include <bits/stdc++.h>
using namespace std;
int n,a[100005],ans,t,l,r;
int q[200005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=n;
	sort(a+1,a+1+n);
	l=1;r=1;
	q[r]=a[1];
	for(int i=2;i<=n;i++){
		t=q[l];
		if(t<a[i]){
			l++;
			ans--;
		}
		q[++r]=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
