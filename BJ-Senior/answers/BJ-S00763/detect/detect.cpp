#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int main(){
	freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		int ans1=0,ans2=0;
		int d[100005],v[100005],a[100005],p[100005];
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		bool mu[100005];
		for(int i=1;i<=n;i++){
			int now=d[i],nowv=v[i];
			bool u=0;
			for(int j=1;j<=m;j++){
				while(p[j]<now) j++;
				nowv+=(p[j]-now)*a[i];
				//cout<<i<<" "<<p[j]<<" "<<nowv<<"\n";
				int temp=-1;
				int tempno=-1;
				if(nowv<0) break;
				if(nowv>V&&(!u)){
					ans1++;
					//cout<<j<<"\n";
					if(mu[j]==0){
						ans2++;
						temp=i;
						tempno=j;
						mu[j]=1;
					}
					if(temp==i&&(tempno!=j)&&mu[j]==1){
						ans2--;
						temp=0;
						tempno=0;
						break;
					}
					u=1;
				}
				//if(nowv<0){
					//break;
				//}
				temp=-1;
				tempno=-1;
			}
		}
		cout<<ans1<<" "<<ans2<<"\n";
	}
	return 0;
}
