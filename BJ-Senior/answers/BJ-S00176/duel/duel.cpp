#include<bits/stdc++.h>
using namespace std;
int n,a[100100],ans,tmp;
bool t[100100];
int get_min(int x) {
	int l=1,r=n,mid;
	while(l<r) {
		mid=(l+r)/2;
		if(a[mid]<=x||t[mid]) {
			l=mid+1;
		}
		else {
			r=mid;
		}
	}
	if(l==n&&(x>=a[l]||t[l])) {
		return -1;
	}
	return l;
}
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		tmp=get_min(a[i]);
		if(tmp!=-1) {
			ans--;
			t[tmp]=true;
		}
	}
	cout<<ans<<endl;
	return 0;
}