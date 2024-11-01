#include <bits/stdc++.h>
#define ll long long
#define dd double
#define N 100005
#define M 1000005
using namespace std;

ll T,n,m,L,V,ans,cnt;
ll d[N],a[N],v[N],c[N],f[M],flag[N];//c测速
ll s[N][5];//超速区域
dd sm,x;


int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=cnt=0;
		for(ll i=0;i<N;i++){
			s[i][0]=s[i][1]=s[i][2]=s[i][3]=s[i][4]=flag[i]=0;
		}
		for(ll i=0;i<M;i++){
			f[i]=0;
		}
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		sm=L;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			if(a[i]<0){
				cnt=1;
			}
		}
		for(ll i=1;i<=m;i++){
			scanf("%lld",&c[i]);
			f[c[i]]=1;
		}
		for(ll i=1;i<=L;i++){
			f[i]=f[i]+f[i-1];
		}
		/*for(ll i=1;i<=L;i++){
			cout<<f[i]<<" ";
		}*/
		for(ll i=1;i<=n;i++){
			if(v[i]>V){
				x=double(double(V*V-v[i]*v[i])/(2*a[i]))+1;
				s[i][1]=d[i];
				if(a[i]>=0){
					s[i][2]=L;
				}else{
					s[i][2]=min(sm+1,d[i]+x);
				}
				if(f[int(s[i][2])]-f[int(s[i][1])]!=0){
					ans++;
					flag[i]=1;
					/*if(T==17&&i==6){
						cout<<flag[i]<<" "<<s[i][1]<<" "<<s[i][2]<<" ";
						cout<<f[int(s[i][2])]-f[int(s[i][1])]<<endl;
					}*/
				}
			}else if(a[i]>0){
				x=double(double(V*V-v[i]*v[i])/(2*a[i]))+1;
				s[i][1]=min(sm+1,d[i]+x);
				s[i][2]=L+1;
				if(f[int(s[i][2])]-f[int(s[i][1])]!=0){
					ans++;
					flag[i]=1;
				}
			}
			/*if(T==17&&flag[i]==1){
				printf("%lld %lld %lld \n",i,s[i][1],s[i][2]);
			}*/
		}
		/*if(T==17){
			//cout<<n<<" "<<m<<" "<<L<<" "<<V<<endl;
			for(int i=1;i<=m;i++){
				cout<<c[i]<<" ";
			}
		}*/
		printf("%lld ",ans);
		if(cnt==0){
			if(ans==0){
				printf("%lld\n",m);
				continue;
			}
			printf("%lld\n",m-1);
			continue;
		}else{
			printf("%lld\n",ans);
		}
	}
	return 0;
}
