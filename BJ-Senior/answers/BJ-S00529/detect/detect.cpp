#include<bits/stdc++.h>
#define ll long long
#define se second
#define fi first
#define N 100010
#define pb push_back
#define pii pair<int,int>
using namespace std;
void solve(){
	float car[N][2];
	int n,m,lm,vm,tot=1,tot2=1,ans1=0,ans2=0,sa=0,sa2=0,che[N];	
	cin>>n>>m>>lm>>vm;
	bool vis[N],vis3[N],vis2[N];
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	memset(vis3,0,sizeof(vis3));
	for(int i=1;i<=n;i++){
		float d,v0,a;
		float pl;
		cin>>d>>v0>>a;
		if((a==0 && v0<=vm) || (a<0 && v0<=vm)){
			continue;
		}
		if(a>=0 && v0>vm){
			car[tot][0]=d;
			car[tot][1]=lm;
			tot++;
			continue;
		}
		pl=(float)(vm*vm-v0*v0)/(float)(2*a)+d;
		if(a>0){		
			car[tot][0]=pl+0.1;
			car[tot][1]=lm;
		}else{
			car[tot][0]=d;
			car[tot][1]=pl-0.1;
		}
		tot++;
	}
	tot--;
	for(int i=1;i<=m;i++){
		float x;
		cin>>x;
		bool in=0;
		for(int i=1;i<=tot;i++){
			if(car[i][0]<=x && x<=car[i][1]){
				if(vis3[i]==0){
					vis3[i]=1;
					ans1++;
				}					
				vis[i]=1;
				in=1;
			} 
		}
		if(in){
			che[tot2]=x;
			tot2++;
		}else{
			ans2++;
		}
	}
	tot2--;
	cout<<ans1;
	sa2=ans1;
	int ans3=0;
	while(sa2){
		pii count[N];
		memset(count,0,sizeof(count));
		count[0].se=1;
		vector<int> save[N];
		for(int i=1;i<=tot2;i++){
			count[i].se=i;
			if(vis2[i]==0){
				for(int j=1;j<=tot;j++){
					if(vis[j]==1){
						if(car[j][0]<=che[i] && che[i]<=car[j][1]){
							count[i].fi++;
							save[i].pb(j);					
						}
					}
				}
			}			
		}
		sort(count+1,count+1+tot2);
		vis2[count[tot2].se]=1;
		ans3++;
		for(auto i:save[count[tot2].se]){
			sa2--;
			vis[i]=0;
		}
	}
	cout<<" "<<m-ans3<<endl;
}
int main(){
	cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}