#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
const ll MAXN=1e6+5;
ll T,n,m,L;
ldb V;
ldb d,a,v;
struct node{
	ll l,r;
	bool operator < (const node &oth)const{
		return l!=oth.l?l<oth.l:r<oth.r;
	}
}t[MAXN];
ll cnt;
ll p[MAXN];
ll sum[MAXN],l_pos[MAXN];
ll read(){
	ll x=0;char ch=getchar();
	bool op=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')op^=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return op?x:-x;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		m=read();
		L=read();
		V=read();
		for(int i=1;i<=L;i++)sum[i]=l_pos[i]=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			d=read();
			v=read();
			a=read();
			if(v==V){
				if(a<=0)continue;
				t[++cnt]=(node){(ll)(d)+1,L};
				// cout<<t[cnt].l<<" --- "<<t[cnt].r<<endl;
				continue;
			}
			if(a==0){
				if(v<=V)continue;
				t[++cnt]=(node){(ll)(d),L};
				// cout<<t[cnt].l<<" --- "<<t[cnt].r<<endl;
				continue;
			}
			if(v>V&&a>0){
				t[++cnt]=(node){(ll)(d),L};
				continue;
			}
			ldb now_time=(ldb)(V-v)/a;
			// cout<<now_time<<" <<t\n";
			// cout<<"debug "<<now_time<<endl;
			if(now_time<0)continue;
			ldb now_x=(ldb)(v+V)*now_time/2.00;
			if(v>V){
				if(fabs(now_x-floor(now_x))<1e-10)now_x=floor(now_x)-1;
				else now_x=floor(now_x);
				t[++cnt]=(node){(ll)(d),(ll)(d+now_x)};
			}
			else{
				if(fabs(now_x-floor(now_x))<1e-10)now_x=floor(now_x)+1;
				else now_x=ceil(now_x);
				t[++cnt]=(node){(ll)(now_x),L};
			}
			// cout<<t[cnt].l<<" --- "<<t[cnt].r<<endl;
		}
		// cout<<"now\n";
		for(int i=1;i<=m;i++)cin>>p[i];
		for(int i=1;i<=m;i++)sum[p[i]]++,t[i].r=min(L,t[i].r);
		for(int i=1;i<=L;i++)sum[i]+=sum[i-1],l_pos[i]=(sum[i]==sum[i-1]?l_pos[i-1]:i);
		ll reg=0;
		// cout<<"pre "<<cnt<<endl;
		for(int i=1;i<=cnt;i++){
			if(sum[t[i].r]-sum[t[i].l-1]==0||t[i].l>t[i].r)t[i].l=1e10,reg++;
		}
		sort(t+1,t+1+cnt);
		cnt-=reg;
		cout<<cnt<<' ';
		ll min_r=-1,ans=0;
		for(int i=1;i<=cnt;i++){
			if(min_r==-1||t[i].l>min_r){
				ans++;
				min_r=l_pos[t[i].r];
				continue;
			}
			min_r=min(min_r,l_pos[t[i].r]);
		}
		cout<<m-ans<<endl;
	}
	return 0;
}