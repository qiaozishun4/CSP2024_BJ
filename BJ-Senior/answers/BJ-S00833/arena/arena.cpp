#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000005],maxn=-1;
int v[1000005];
bool b[10000005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			v[a[i]]++;
		}
		for(int i=1;i<=1000005;i++){
			if(v[i]>1){
				sum+=a[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

