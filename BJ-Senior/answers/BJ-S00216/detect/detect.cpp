#include<bits/stdc++.h>
using namespace std;
int T,n,mz,L,V,maxp=0,max1=0,t2=0,nu[100005],max11=0;
int d[100005];
double a[100005],v[100005],u[100005];
int p[100005],h[100005],s[100005];
int k[100005],op[100005],pp[100005],oo=0;
int flag=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		oo=0;
		cin>>n>>mz>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=mz;i++){
			cin>>p[i];
			h[p[i]]=1;
			maxp=max(maxp,p[i]);
		}
		for(int i=1;i<=n;i++){
			flag=0;
				int s=maxp-d[i];
				if(v[i]>V){
					++oo;
			        }
		}
		cout<<oo<<" "<<mz-1<<endl;
	}
	return 0;
}