#include<bits/stdc++.h>
using namespace std;
struct aaa{
	double d,v,a,k;
};
bool cmp(aaa x,aaa y){
	return x.d<y.d;
}
int t;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		int m;
		double n,L,V,maxn=-10086,cnt=0,cnt1,flg1=1,flg2=1,flg3=0;;
		double p[100005],now[100005];
		aaa a[100005];
		bool vis[100005],vist[100005];
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>a[i].d>>a[i].v>>a[i].a;
			if(a[i].a>0&&flg2==1){
				a[i].k= ((V*V)-(a[i].v*a[i].v))/(2*a[i].a);
				flg1=0;
				flg2=3;
			}else if(flg1==1&&a[i].a==0){
				flg1=3;
				flg2=0;
			}else if(a[i].a<0){
				flg2=0;
				a[i].k= ((V*V)-(a[i].v*a[i].v))/(2*a[i].a);
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(flg1==3){
			cnt1=0;
			for(int i=1;i<=n;i++){
				if(a[i].d<=p[m]&&a[i].v>V){
					cnt1++;
				}
			}
			cout<<cnt1<<" "<<m-1<<endl;
		}else if(flg2==3){
			cnt1=0;
			for(int i=1;i<=n;i++){
				if((a[i].k<=p[m]&&a[i].d<=p[m])||(a[i].d<=p[m]&&a[i].v>V)){
					cnt1++;
				}
			}
			cout<<cnt1<<" "<<m-1<<endl;			
		}
	}
	return 0;
}
