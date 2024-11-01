#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
float T,n,m,L,V,d[N],v[N],a[N];
float p[N];
float ansv[N];
bool fl[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		float dr=0,cnt1=0,cnt2=0;
		float tmp=0;
		memset(ansv,0,sizeof(ansv));
		memset(fl,0,sizeof(fl));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dr=p[i]-d[j];
				if(dr>=L) fl[j]=1;
				tmp=-(v[j]*v[j])/(2*a[j]);
				if(tmp<=p[i]) fl[j]=1;
				ansv[j]=sqrt(v[j]*v[j]+2*a[j]*dr);
				if(ansv[j]>V&&fl[j]!=1){
					fl[j]=1;
					cnt1++;
				}
			}
		}
		cout<<cnt1<<" "<<cnt2<<endl;
	}
	return 0;
}
