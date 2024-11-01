#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
struct node{
	int d,v,a;
};
node cl[100005];
int csy[100005];
int wz[1000005];
int sum[100005];
int cnt=0;
int ans1=0;
int ans2=0;
int minn=1e9;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>cl[i].d>>cl[i].v>>cl[i].a;
			if(cl[i].v>V){
				if(cl[i].d>minn){
					minn=cl[i].d;
				}
				wz[cl[i].d]++;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>csy[i];
		}
		for(int i=0;i<=L;i++){
			wz[i]=wz[i-1]+wz[i];
		}
		sort(csy+1,csy+m+1);
		for(int i=m;i>=1;i--){
			if(i==m){
				ans1=wz[csy[i]];
				ans2=wz[csy[i]];
				cnt=0;
			}else{
				if(ans2!=wz[csy[i]]){
					break;
				}else{
					cnt++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(csy[i]<minn){
				cnt++;
			}
		}
		cout<<ans1<<" "<<cnt<<endl;
		for(int i=0;i<=L;i++){
			wz[i]=0;
		}
		ans1=0;
		ans2=0;
		cnt=0;
		minn=1e9;
	}
	return 0;
}
