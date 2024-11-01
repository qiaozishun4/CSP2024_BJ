#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int i,j;
	int n;
	cin>>n;
	int ans=n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(a[i]!=a[j]){
			cout<<1;
		}
		else{
			cout<<2;
		}
		return 0;
	}
	i=1,j=2;
	while(j<=n){
		if(a[j]>a[i]){
			ans--;
			i++;j++;
		}else{
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
