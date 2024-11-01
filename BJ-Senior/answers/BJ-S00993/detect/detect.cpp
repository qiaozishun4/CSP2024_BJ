#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll L,x;
int p[100005];
int n,m;
pair<int,int>getrange(ll v0,ll a,ll l){
	if(a==0){
		if(v0<=x)return {-1,-1};
		else return {l,L};
	}
	else if(a>0){
		if(v0>x)return {l,L};
		ll p=(x*x-v0*v0)/(2*a)+1;
		//cout<<p<<endl;
		//if(l+p>L)return{-1,-1};
		return {l+p,L};
	}
	else{
		ll p=ceil((x*x-v0*v0)/(2.0*a))-1;
		return {l,min(l+p,L)};
	}
}
double getv1(ll v0,ll a,ll s){
	return sqrtl(v0*v0+2*a*s);
}
int b[1000005];
bool cmp(pair<int,int>x,pair<int,int>y){
	if(x.second!=y.second)return x.second<y.second;
	return x.first<y.first;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		int ans1=0,ans2=0;
		cin>>n>>m>>L>>x;
		vector<pair<int,int>>pos,tot;
		for(int i=1;i<=n;i++){
			int d,v,a;cin>>d>>v>>a;
			pair<int,int>tmp=getrange(v,a,d);
			//bool st=getv1(v,a,tmp.first-d)<=x;
			//if(!st)cout<<d<<" "<<v<<" "<<a<<" "<<tmp.first<<" "<<tmp.second<<endl;
			
			if(tmp.first==-1||tmp.first>tmp.second)continue;
			pos.push_back(tmp);
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			//if(t==19)cout<<p[i]<<endl;
			b[p[i]]=1;
		}
		for(int i=1;i<=L;i++)b[i]+=b[i-1];
		for(auto i:pos){
			int cur=b[i.second];
			if(i.first>0)cur-=b[i.first-1];
			if(cur){
				ans1++;
				tot.push_back(i);
			}
			//else cout<<i.first<<" "<<i.second<<endl;
		}
		sort(tot.begin(),tot.end(),cmp);
		int cnt=0;int last=-1;
		for(auto i:tot){
			if(i.first<=last&&last<=i.second)continue;
			ans2++;
			int pos=upper_bound(p+1,p+m+1,i.second)-p-1;
			last=p[pos];
		}
		cout<<ans1<<" "<<m-ans2<<endl;
	}
	return 0;
}