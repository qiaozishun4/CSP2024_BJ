#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef long long ll;
const ll MAXN=1e6+5;
ll T,n;
ll a[MAXN];
struct node{
	ll l,r;
	bool operator < (const node &oth)const{
		return r<oth.r;
	}
}t[MAXN];
ll cnt;
ll lst[MAXN];
ll tree[MAXN<<2],tag[MAXN<<2];
void push_up(ll id){
	if(tree[id<<1]>=tree[id<<1|1]){
		tree[id]=tree[id<<1];
		tag[id]=tag[id<<1];
	}
	else{
		tree[id]=tree[id<<1|1];
		tag[id]=tag[id<<1|1];
	}
	return;
}
void update(ll id,ll L,ll R,ll k,ll num,ll _id){
	if(L>R)return;
	if(L==R){
		tree[id]=num;
		tag[id]=_id;
		return;
	}
	ll mid=(L+R)>>1;
	if(k<=mid)update(id<<1,L,mid,k,num,_id);
	else update(id<<1|1,mid+1,R,k,num,_id);
	push_up(id);
	return;
}
pair<ll,ll> query(ll id,ll L,ll R,ll QL,ll QR){
	if(L>R||R<QL||L>QR)return make_pair(0,0);
	if(QL<=L&&R<=QR)return make_pair(tree[id],tag[id]);
	ll mid=(L+R)>>1;
	pair<ll,ll> p_l=query(id<<1,L,mid,QL,QR),p_r=query(id<<1|1,mid+1,R,QL,QR);
	if(p_l.first>=p_r.first)return p_l;
	return p_r;
}
struct edge{
	ll u,v,nxt;
}e[MAXN<<2];
ll head[MAXN],edge_num=0;
void add_edge(ll From,ll To){
	e[++edge_num]=(edge){From,To,head[From]};
	head[From]=edge_num;
	return;
}
bool vis[MAXN];
ll solve(ll now,ll father){
	ll reg=0;
	vis[now]=1;
	for(int i=head[now];i;i=e[i].nxt){
		if(e[i].v==father)continue;
		reg=max(reg,solve(e[i].v,now));
	}
	return reg+a[t[now].l];
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(lst,0,sizeof(lst));
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		memset(e,0,sizeof(e));
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		edge_num=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(lst[a[i]]){
				t[++cnt]=(node){lst[a[i]],i};
			}
			lst[a[i]]=i;
		}
		if(n<=15){
			ll ans=0;
			for(int i=0;i<(1<<n);i++){
				ll sum=0;
				ll lst0=0,lst1=0;
				for(int j=0;j<n;j++){
					if(i&(1<<j)){
						sum+=(a[j+1]==a[lst1]?a[j+1]:0);
						lst1=j+1;
					}
					else{
						sum+=(a[j+1]==a[lst0]?a[j+1]:0);
						lst0=j+1;
					}
				}
				ans=max(ans,sum);
			}
			cout<<ans<<endl;
		}
		else{
			sort(t+1,t+1+cnt);
			for(int i=1;i<=cnt;i++){
				pair<ll,ll> now=query(1,1,n,1,t[i].l);
				now.first+=a[t[i].l];
				update(1,1,n,t[i].r,now.first,i);
				add_edge(now.second,i);
				add_edge(i,now.second);
			}
			ll fir=0,sec=0;
			for(int i=1;i<=cnt;i++)if(!vis[i]){
				ll qwq=solve(i,0);
				if(qwq>fir)sec=fir,fir=qwq;
				else sec=max(sec,qwq);
			}
			cout<<fir+sec<<endl;
		}
	}
	return 0;
}