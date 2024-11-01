#include <iostream>
#include <cstdio>
using namespace std;
const int N=2007;
int n, ans=0;
int a[N];
bool b[N];
int cnt(){
	int sum=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(b[j]==b[i]){
				if(a[j]==a[i])
					sum+=a[i];
				break;
			}
		}
	}
	return sum;
}
void dfs(int x){
	if(x==n+1){
		ans=max(ans, cnt());
		return;
	}
	b[x]=0;
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n<=15){
			dfs(1);
		}
		cout<<ans<<endl;
	}
	return 0;
}