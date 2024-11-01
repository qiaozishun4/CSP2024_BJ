#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,l,V,d[100001],v[100001],a[100001],maxp=INT_MIN;
		cin>>n>>m>>l>>V;
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=0;i<m;i++){
			int p;
			cin>>p;
			maxp=max(maxp,p);
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(v[i]>V&&d[i]<=maxp){
				ans++;
			}
		}
		if(ans==0)	cout<<ans<<' '<<m<<endl;
		else 		cout<<ans<<' '<<m-1<<endl;
	}
}
