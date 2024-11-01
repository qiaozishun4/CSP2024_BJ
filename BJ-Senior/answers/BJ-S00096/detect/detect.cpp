#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
int T,n,m;
double L,V;
double start[100010],v[100010],a[100010],Lborder[100010],Rborder[100010];
bool flag[100010];
int cnt;
double pos[100010];
vector<int> edg[100010],w[100010];
int dis[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=0;i<=m;i++){
			edg[i].clear();
			w[i].clear();
		}
		for(int i=1;i<=n;i++){
			flag[i]=1;
			cin>>start[i]>>v[i]>>a[i];
			if(a[i]<eps&&a[i]>-eps){//a=0
				if(v[i]>V+eps){//overspeed
					Lborder[i]=start[i]-eps;
					Rborder[i]=L+eps;
				}else{//not overspeed
					Lborder[i]=-1;
					Rborder[i]=-1;
					flag[i]=0;
				}
			}
			double t=(V-v[i])/a[i];//time until reaching speed limit
			double cur=start[i]+(v[i]*t+a[i]*t*t/2);//position when reaching speed limit
			if(cur<start[i]-eps)cur=start[i];
			if(a[i]>eps){
				if(cur>L+eps){
					flag[i]=0;
					Lborder[i]=Rborder[i]=-1;
				}else if(v[i]>V+eps){
					Lborder[i]=start[i]-eps;
					Rborder[i]=L+eps;
				}else{
					Lborder[i]=cur+eps;
					Rborder[i]=L+eps;
				}
			}else if(v[i]>V+eps){
				Lborder[i]=start[i]-eps;
				Rborder[i]=cur-eps;
			}else{
				Lborder[i]=Rborder[i]=-1;
				flag[i]=0;
			}
			if(Lborder[i]<start[i]-eps)Lborder[i]=start[i];
			if(Rborder[i]>L+eps)Rborder[i]=L;
		}
		for(int i=1;i<=m;i++)cin>>pos[i];
		sort(pos+1,pos+m+1);
		cnt=0;
		for(int i=1;i<=n;i++){
			int st=upper_bound(pos+1,pos+m+1,Lborder[i]-eps/2)-pos;
			int en=upper_bound(pos+1,pos+m+1,Rborder[i]+eps/2)-pos-1;
			if(flag[i]&&st<=en){
				cnt++;
				//[st,en] must contain at least one detector
				//pref[en]>=pref[st-1]+1
				edg[en].push_back(st-1);
				w[en].push_back(1);
			}
		}
		for(int i=1;i<=m;i++){
			//pref[i]>=pref[i-1](+0)
			edg[i].push_back(i-1);
			w[i].push_back(0);
		}
		dis[0]=0;
		for(int i=1;i<=m;i++){
			dis[i]=-0x3fffffff;
			for(int j=0;j<edg[i].size();j++){
				int from=edg[i][j];
				int W=w[i][j];
				dis[i]=max(dis[i],dis[from]+W);
			}
		}
		cout<<cnt<<" "<<m-dis[m]<<endl;
	}
}