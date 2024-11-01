#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long d[100005];
	long long c[100005];
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	char c1[40][100005];
	int k=1;
	while(cin>>c1[k]){
		if(strlen(c1[k])==1){
			break;
		}
		k++;
		
	}
	int t;
	cin>>t;
	while(t--){
		long long x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		int a[100005];
		for(int i=1;i<=n;i++){
			a[i]=d[i]^(x[i%4]);
		}
		long long cnt=0;
		for(int z=1;z<=m;z++){
			int l=1;
			int r;
			for(int i=1;i<=30;i++){
				if((l<<i)>=c[z]){
					l=l<<i;
					r=i;
					break;
				}
			}
			int h[100005];
			for(int i=1;i<=l;i++){
				h[i]=i;
			}
			int gg=1;
			for(int i=r;i>=1;i--){
				if(c1[i][gg-1]=='1'){
					gg*=2;gg+=1;
				}else{
					gg*=2;
				}
			}
			cnt^=(1ll*gg*z);
		}
		cout<<cnt<<endl;
	}
	return 0;
}
