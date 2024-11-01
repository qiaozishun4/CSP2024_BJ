#include<iostream>
#include<cmath>
using namespace std;
long double l,v0,d[10000005],v[10000005],a[10000005],p[10000005],s2,v3,v4;
long long ans=0,t,n,m;
long double s1(long double v0,long double a,long double t){
	return s2=v0*t+0.5*a*t*t;
}long double v1(long double v0,long double a,long double t){
	return v3=v0+a*t;
}long double v2(long double v0,long double a,long double s){
	return v4=sqrt(v0*v0+2*a*s);
}int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		ans=0;
		cin>>n>>m>>l>>v0;
		for(long long j=1;j<=n;j++){
			cin>>d[j]>>v[j]>>a[j];
		}for(long long j=1;j<=m;j++){
			cin>>p[j];
		}for(long long k=1;k<=m;k++){
			for(long long j=1;j<=n;j++){
				if(d[j]<p[m]){
					if(a[j]==0&&v[j]>v0)ans++;
					else if(d[j]<p[k]){
						v2(v[j],a[j],p[k]);
						if(v4>v0){
							ans++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<" "<<ans<<endl;
	}
	return 0;
}
