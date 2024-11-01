#include <bits/stdc++.h>
using namespace std;
int a[100005],has[100005],maxhas=-1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	memset(has,0,sizeof has);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		has[a[i]]++;
	}
	for(int i=1;i<=100000;i++){
		maxhas=max(maxhas,has[i]);
	}
	cout<<maxhas;
	return 0;
}
