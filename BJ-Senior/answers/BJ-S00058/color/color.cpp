#include<bits/stdc++.h>
using namespace std;
void solve1(int n){
	int a[200001];
	bool h[200001]={0};
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	__int128 k=(1<<n);
	while((--k)>=0){
		int cnt=0;
		__int128 l=k;
		for(int i=0;i<=n-1;i++){
			h[i+1]=(l>>i)&1?1:0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>0;j--){
				if(h[i]==h[j]){
					//cout<<i<<' '<<j<<endl;
					if(a[i]==a[j]){
						cnt+=a[i];
						//cout<<1<<' '<<i<<' '<<j<<endl;
					}
					break;
				}
			}
		}
		//cout<<endl<<k<<endl;
		//for(int i=1;i<=n;i++)
		//	cout<<(h[i]==1?1:0)<<' ';
		//cout<<endl<<cnt<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve1(n);
		
	}
	return 0;
}
