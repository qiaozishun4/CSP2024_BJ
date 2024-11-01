#include<bits/stdc++.h>
using namespace std;
double a[100100],d[100100],s[100100],p[100100];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,l,v,ans1=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++) cin>>d[i]>>s[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			if(a[i]==0)
				if(d[i]<=p[m]&&s[i]>v) ans1++;
			if(a[i]>0)
				if(d[i]+((v*v-s[i]*s[i])+2*a[i]-1)/(2*a[i])*1.0<p[m]&&p[m]>=d[i]) ans1++;
		}
		if(ans1==0) cout<<ans1<<" "<<m<<endl;
		else cout<<ans1<<" "<<m-1<<endl;
	}
	return 0;
}