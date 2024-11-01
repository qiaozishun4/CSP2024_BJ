#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,m,L,V,num,ans,ans2;
double d[1000005],v[1000005],a[1000005],p[1000005],book[1000005];
double s[1000005],e[1000005];

ll f(){
	for(ll i=1;i<=n;i++){
		book[i]=0;
	}
	num=0;
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(s[i]<=p[j]&&e[i]>=p[j]&&book[i]==0&&p[j]<=L){
				book[i]=j;
				num++;
			}
		}
	}
	return num;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	cin>>T;
	while(T--){
		ans=ans2=0;
		cin>>n>>m>>L>>V;
		for(ll i=1;i<=n;i++){
			scanf("%lf%lf%lf",&d[i],&v[i],&a[i]);
		}
		for(ll i=1;i<=m;i++){
			scanf("%lf",&p[i]);
		}
		
		for(ll i=1;i<=n;i++){		//计算车辆超速区间si~ei
			if(a[i]==0){
				if(v[i]>V){
					s[i]=d[i];
					e[i]=L;
				}
			}
			else if(a[i]>0){
				if(v[i]>V){
					s[i]=d[i];
					e[i]=L;
				}else{
					s[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i])+0.0001;
					if(s[i]>L){
						s[i]=e[i]=0;
					}else{
						e[i]=L;
					}
				}
			}
			else if(a[i]<0){
				a[i]*=-1;
				if(v[i]>V){
					s[i]=d[i];
					e[i]=d[i]+(v[i]*v[i]-V*V)/(2*a[i]);
				}
			}
		}		
		
		ans=f();		
		for(ll i=1;i<=m;i++){
			ll tmp=p[i];
			p[i]=1e9;
			if(f()==ans){
				ans2++;
//				cout<<i<<" ";
			}else{
				p[i]=tmp;
			}
		}
		
//		for(ll i=1;i<=n;i++){
//			cout<<i<<":"<<s[i]<<"  "<<e[i]<<endl;
//		}
		
		printf("%lld %lld\n",ans,ans2);
	}	
	return 0;
}
