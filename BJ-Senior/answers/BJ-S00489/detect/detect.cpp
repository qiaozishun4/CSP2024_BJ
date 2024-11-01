#include<bits/stdc++.h>
using namespace std;
struct kk{
	int d,v,a;
}a[1000005];
int l[1000005]={},ji[1000005],p[1000005];
int n,m,L,V,num=0;
int chaosu(int d,int v,int a,int i1){
	bool n=0;
	if(a==0){
		for(int i=d;i<=L;i++){
			p[i]++;
			if(l[i]!=0&&v>V){
				n=1;
			}if(l[i]!=0&&p[i]==1){
				num++;
			}
		}
//		if(!jian){
	//		num--;
//		}
		if(n==0)
			return 0;
		return 1;
	}
	if(v<=V&&a<0)
		return 0;
	double q=(V*(V*1.0)-v*(v*1.0))/(2.0*a);
	if(a>0){
		for(int i=d+ceil(q);i<=L;i++){
			p[i]++;
			if(l[i]!=0){
				n=0;
			}if(l[i]!=0&&p[i]==1){
				num++;
			}
		}
//		if(!jian){
//			num--;
//		}
	}else{
		for(int i=d;i<q+d&&i<=L;i++){
			p[i]++;
			if(l[i]!=0){
				n=1;
			}if(l[i]!=0&&p[i]==1){
				num++;
			}
		}
//		if(!jian){
//			num--;
//		}
	}
	if(n==0)
		return 0;
	return 1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int sum=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>a[i].d>>a[i].v>>a[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>ji[i];
			l[ji[i]]++;
		}
		for(int i=1;i<=n;i++){
			sum+=chaosu(a[i].d,a[i].v,a[i].a,i);
		}
		memset(l,0,sizeof(l));
		memset(p,0,sizeof(p));
		cout<<sum<<' '<<num-1<<endl;
		num=0;
	}
	return 0;
}

