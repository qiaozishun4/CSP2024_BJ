#include<bits/stdc++.h>
using namespace std;
int a[100005],t[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	sort(a+1,a+1+n);
	int len=unique(a+1,a+1+n)-a-1;
	int lar=t[a[len]];
	for(int i=len-1;i>=1;i--){
		if(lar>=t[a[i]]) ans-=t[a[i]];
		else ans-=lar,lar=t[a[i]];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}

