#include<bits/stdc++.h>
//wrong answer
using namespace std;
int main(){
	freopen("detect2.in","r",stdin);
	freopen("detect2.out","w",stdout);
	int T;cin>>T;
	int tong[100007];
	//需要的限速器
	while(T){
		T--;
		int n,m,L,V;
		double d[100007],v[100007],a[100007];
		int p[100007];bool flag[100007];
		cin>>n>>m>>L>>V;//车辆个数，限速器个数，道路长度，限速
		for(int i=1;i<=n;i++){
			scanf("%lf %lf %lf",&d[i],&v[i],&a[i]);
		}//初始位置，初始速度，加速度
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}//限速器位置
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V){
					for(int j=1;j<=m;j++){
						if(p[j]<=L&&p[j]>=d[i])flag[i]=1;
					}
				}
			}
			else{
				double s=double((V*V)*1.0-(v[i]*v[i])*1.0)/(2.0*double(a[i]));//行驶多少后当时速度正常
				//不包含s
				double l,r;
				if(a[i]>0) l=d[i]+s,r=L;
				else l=d[i],r=d[i]+s;
				//cout<<"i="<<i<<" "<<l<<" "<<r<<endl;
				for(int j=1;j<=m;j++){
					if(double(p[j])>=l&&double(p[j])<=r){
						flag[i]=1;
						tong[p[j]]++;
						//cout<<" |"<<p[j]<<endl;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(flag[i])ans++;
		}cout<<ans<<" ";
		ans=0;
		//cout<<endl;
		for(int i=1;i<=L;i++){
			if(tong[i]>1){
				ans++;//cout<<" ="<<i<<" "<<tong[i]<<"\n";
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
