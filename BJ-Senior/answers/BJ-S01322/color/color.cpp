#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,n,sum=0,a[20010],c[20010]={0};
	cin>>t;
	while(t--){
		memset(c,0,sizeof c);
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1]&&c[i]!=-1) sum+=a[i],c[i+1]=-1;
		}cout<<sum<<endl;
	}
	return 0;
}
