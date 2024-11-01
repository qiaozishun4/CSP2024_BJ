#include<bits/stdc++.h>
using namespace std;
long long d[100005],v[100005],a[100005],p[100005],l[100005],r[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	long long t;
	cin>>t;
	while(t--){
		long long n,m,le,vm,u=1;
		cin>>n>>m>>le>>vm;
		for(long long i=1; i<=n; i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]<0) u=0;
		}
		for(long long i=1; i<=m; i++){
			cin>>p[i];
			p[i]=p[i];
		}
		if(u==1){
			long long sum=0;
			for(long long i=1; i<=n; i++){
				if(v[i]>vm&&d[i]<=p[m]){
					sum++;
				}
			}
			if(sum!=0){
				cout<<sum<<" "<<m-1<<endl;
			} else{
				cout<<sum<<" "<<m<<endl;
			}
			continue;
		} 
		for(long long i=1; i<=n; i++){
			if(a[i]>=0){
				l[i]=m+1;
				r[i]=m;
				for(long long j=1; j<=m; j++){
					if(p[j]>=d[i]&&v[i]*v[i]+2*a[i]*(p[j]-d[i])>vm*vm){
						l[i]=j;
						break;
					}
				}
			} else{
				l[i]=d[i];
				r[i]=m+1;
				for(long long j=1; j<=m; j++){
					if(p[j]>=d[i]&&v[i]*v[i]+2*a[i]*(p[j]-d[i])<vm*vm){
						r[i]=j-1;
						break;
					}
				}
			}
		}
		if(u==1){
			long long sum=0;
			for(long long i=1; i<=n; i++){
				if(l[i]<m+1&&d[i]<=p[m]){
					sum++;
				}
			}
			if(sum!=0){
				cout<<sum<<" "<<m-1<<endl;
			} else{
				cout<<sum<<" "<<m<<endl;
			}
			continue;
		} else{
			
		}
	}
	return 0;
}
/*
1
5 5 10 5
1 1 0  
1 1 0
2 1 0
2 1 0
3 1 0
1 3 5 7 9
*/