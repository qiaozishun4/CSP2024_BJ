#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=1,tmp=0;
	for(int i=1; i<=n; i++){
		if(a[i]==a[i+1]){
			sum++;
		} else{
			tmp=max(0,tmp-sum)+sum;
			sum=1;
		}
	}
	cout<<tmp;
	return 0;
}
