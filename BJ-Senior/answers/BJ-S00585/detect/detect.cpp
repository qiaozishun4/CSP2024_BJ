#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int N=3e3+5;
long long t,n,m,l,V,r[N],v[N],a[N],q[N],cv[N],dp[N][N];
long long s[N],c[N];
long long ans,ans2;
bool vi[N];
vector<int> ad[N];
struct node{
	int id,gs;
}co[N];
bool cmp(node x,node y){
	return x.gs>=y.gs;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.ans","w",stdout);
	cin>>t;
	while (t--){
		memset(vi,0,sizeof(vi));
		ans=0,ans2=0;
		cin>>n>>m>>l>>V;
		if (n>3000 || m>3000){
			cout<<0<<" "<<0<<'\n';
			continue;
		}
		for (int i=1;i<=n;i++){
			cin>>r[i]>>v[i]>>a[i];
			if (a[i]<0 && v[i]<V){
				vi[i]=1;
				continue;
			}
			if (a[i]>0)
				s[i]=(int)ceil((double)(V*V-v[i]*v[i])/(double)2*a[i])+r[i],c[i]=l;
			else
				s[i]=(int)floor((double)(V*V-v[i]*v[i])/(double)2*a[i])+r[i],c[i]=(int)floor((double)r[i]+(double)(0.0 -v[i]*v[i])/(double)2*a[i]);
		}
		for (int i=1;i<=m;i++){
			cin>>q[i];
			co[i].id=i;
			for (int j=1;j<=n;j++){
				//if (i==10 && j==10)
					//cout<<(s[j]<=q[i])<<'\n';
				if (a[j]<0 && r[j]<=q[i] && c[j]>=q[i] && (int)floor(sqrt(v[j]*v[j]+2*a[j]*(q[i]-r[j])))>=V){
					if (!vi[j])
						ans++,ad[i].push_back(j),co[i].gs++;
					vi[j]=1;
					//cout<<j<<" ";
				}
				else if (a[j]>0 && r[j]<=q[i] && l>=q[i] && (int)floor(sqrt(v[j]*v[j]+2*a[j]*(q[i]-r[j])))>=V){
					if (!vi[j])
						ans++,ad[i].push_back(j),co[i].gs++;
					vi[j]=1;
					//cout<<j<<" ";
				}
			}
		}
		//int i=10,j=10;
		//cout<<(int)floor(sqrt(v[j]*v[j]+2*a[j]*(q[i]-r[j])))<<'\n';
		memset(vi,0,sizeof(vi));
		sort(co+1,co+n+1,cmp);
		for (int i=1;i<=n;i++){
			bool f=0;
			for (int j=1;j<=n;j++){
				if (!vi[j])
					f=1;
			}
			if (!f)
				break;
			ans2++;
			for (auto p:ad[co[i].id]){
				vi[p]=1;
			}
		}
		cout<<ans<<" "<<ans2<<'\n';
	}
	return 0;
}
