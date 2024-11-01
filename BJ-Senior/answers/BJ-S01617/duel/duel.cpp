#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	int n,cc=0;
	
	cin>>n;
	
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	
	vector<int>a(n+1,0);
	vector<int>vis(n+1,false);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a.begin()+1,a.end());

	int j=1;

	for(int i=2;i<=n;i++){
		while(j<=n&&vis[j]){
			j++;
		}
		
		while((i<=n&&a[i]<=a[j])||(i<=n&&vis[i])){
			i++;
		}
		
		if(i<=n&&j<=n&&a[i]>a[j]&&!vis[i]&&!vis[j]){
			vis[j]=true;
		}else{
			break;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cc++;
		}
	}
	
	cout<<cc<<endl;
	
	 return 0;
}
