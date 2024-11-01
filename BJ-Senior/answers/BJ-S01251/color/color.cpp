#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
int a[maxn],c[maxn];
int t,n;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<17){
			ll mx=-1;
			for(int i=0;i<=(1<<17);i++){
				int k=i;
				int tot=0;
				for(int j=1;j<=20;j++)c[j]=0;
				while(k){
					c[++tot]=k%2;
					k/=2;
				}
				int nxb=-1,nxr=-1;
				ll ans=0;
				for(int j=1;j<=n;j++){
					if(c[j]==0){
						if(nxb==-1){
							nxb=j;
						}
						else if(a[nxb]==a[j]){
							ans+=a[j];
							nxb=j;
						}
						else{
							nxb=j;
						}
					}
					else{
						if(nxr==-1){
							nxr=j;
						}
						else if(a[nxr]==a[j]){
							ans+=a[j];
							nxr=j;
						}
						else{
							nxr=j;
						}
					}
				}
				mx=max(mx,ans);
			}
			cout<<mx<<endl;
		}
	}
	return 0;
}
