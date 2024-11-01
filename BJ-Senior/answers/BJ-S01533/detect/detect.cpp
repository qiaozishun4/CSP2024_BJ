#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
//type加速、减速、匀速？
//to最早在什么时候脱离超速，最晚在什么时候(位置)进入超速
//匀速行驶时有没有超速
struct node{
	int l,r,val,pls;
}tree[N<<4];
bool chaosu[N];//tg dx qzh cf
int T,n,m,L,V,ans,d[N],type[N],to[N],pzd[N],tg[N],dx[N],qzh[1000005],cf[1000005];
void push_up(int x){
	if(tree[x<<1].val>=tree[x<<1|1].val){
		tree[x].val=tree[x<<1].val;
		tree[x].pls=tree[x<<1].pls;
	}else{
		tree[x].val=tree[x<<1|1].val;
		tree[x].pls=tree[x<<1|1].pls;
	}
	return;
}
void build(int x,int l,int r){
	tree[x].l=l;
	tree[x].r=r;
	if(l==r){
		tree[x].val=dx[l];
		tree[x].pls=l;
		//cout<<"build to"<<x<<' '<<l<<' '<<r<<' '<<tree[x].pls<<' '<<tree[x].val<<endl;
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	push_up(x);
	//cout<<"build to"<<x<<' '<<l<<' '<<r<<' '<<tree[x].pls<<' '<<tree[x].val<<endl;
	return;
}
//我该加到哪 最大是多少
pair<int,int> query(int x,int l,int r){
	if(tree[x].r<l||r<tree[x].l)return {0,0};
	if(tree[x].l==tree[x].r)return {tree[x].pls,tree[x].val};
	pair<int,int>L=query(x<<1,l,r);
	pair<int,int>R=query(x<<1|1,l,r);
	if(L.second>=R.second)return L;
	return R;
}
void upd(int x,int nd){//将nd++
	if(tree[x].r<nd||nd<tree[x].l)return;
	if(tree[x].l==tree[x].r){
		tree[x].val++;
		return;
	}
	upd(x<<1,nd);
	upd(x<<1|1,nd);
	push_up(x);
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		//tg dx qzh cf
		memset(tg,0,sizeof(tg));
		memset(dx,0,sizeof(dx));
		memset(cf,0,sizeof(cf));
		memset(qzh,0,sizeof(qzh));
		memset(tree,0,sizeof(tree));
		ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			int v,a;
			cin>>d[i]>>v>>a;
			if(a==0){
				type[i]=3;
				//匀速行驶时有没有超速
				to[i]=(v>V);
			}else if(a>0){//加速，二分进入超速位置点
				type[i]=2;
				int l=0,r=L-d[i];
				to[i]=-1;//-1为没有超速
				//最晚在什么时候(位置)进入超速
				while(l<=r){
					int mid=(l+r)>>1;
					if(v*v+2*a*mid>V*V){
						to[i]=mid;//往后仍然超速
						r=mid-1;
					}else l=mid+1;//不超速，向右找
				}
			}else{
				type[i]=1;
				int l=0,r=L-d[i];
				to[i]=-1;//-1为没有超速
				//最晚在什么时候还在超速
				while(l<=r){
					int mid=(l+r)>>1;
					if(v*v+2*a*mid>V*V){
						to[i]=mid;//往前仍然超速
						l=mid+1;
					}else r=mid-1;//不超速，向左找
				}
			}
		}
		for(int i=1;i<=m;i++){
			cin>>pzd[i];
			qzh[pzd[i]]++;
		}
		sort(pzd+1,pzd+m+1);
		for(int i=0;i<=L;i++)qzh[i]+=qzh[i-1];
		for(int i=1;i<=n;i++){
			if(type[i]==3){
				ans+=to[i];
				if(to[i]){
					chaosu[i]=1;
					cf[d[i]]++;
					cf[L+1]--;
				}
			}
			if(type[i]==2&&~to[i]){
				ans+=(bool)(qzh[L]-qzh[d[i]+to[i]-1]);
				if(qzh[L]-qzh[d[i]+to[i]-1])chaosu[i]=1;
				cf[d[i]+to[i]]++;
				cf[L+1]--;
			}
			if(type[i]==1&&~to[i]){
				ans+=(bool)(qzh[d[i]+to[i]]-qzh[d[i]-1]);
				if(qzh[d[i]+to[i]]-qzh[d[i]-1])chaosu[i]=1;
				cf[d[i]]++;
				cf[d[i]+to[i]+1]--;
			}
		}
		cout<<ans<<' ';
		//处理每个摄像头拍到的东西数量
		for(int i=0;i<=L;i++)cf[i]+=cf[i-1];
		for(int i=1;i<=m;i++)dx[i]=cf[pzd[i]];//差分
		//每次寻找最大的dx[i]+tg[i] -> 线段树，区间查询单点修改
		build(1,1,m);
		for(int i=1;i<=n;i++){
			//每辆车
			if(chaosu[i]==0)continue;
			//cout<<"to"<<i<<endl;
			//cout<<d[i]<<' '<<to[i]<<endl;
			if(type[i]==3){//匀速 di - L
				//找在区间内的最小拍照点
				int l=1,r=m;
				int LL,RR;
				LL=RR=-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(pzd[mid]<d[i])l=mid+1;
					else{
						LL=mid;
						r=mid-1;
					}
				}
				pair<int,int>np=query(1,LL,m);
				int pls=np.first;
				//加！
				tg[pls]++;
				//cout<<"plus on"<<pls<<endl;
				upd(1,pls);
			}
			if(type[i]==2){//加速 d[i]+to[i] - L
				int l=1,r=m;
				int LL,RR;
				LL=RR=-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(pzd[mid]<d[i]+to[i])l=mid+1;
					else{
						LL=mid;
						r=mid-1;
					}
				}
				pair<int,int>np=query(1,LL,m);
				int pls=np.first;
				//加！
				tg[pls]++;
				//cout<<"plus on"<<pls<<endl;
				upd(1,pls);
			}
			if(type[i]==1){//减速 d[i] - d[i]+to[i]
				int l=1,r=m;
				int LL,RR;
				LL=RR=-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(pzd[mid]<d[i])l=mid+1;
					else{
						LL=mid;
						r=mid-1;
					}
				}
				l=1,r=m;
				while(l<=r){
					int mid=(l+r)/2;
					if(pzd[mid]>d[i]+to[i])r=mid-1;
					else{
						if(pzd[mid]>=d[i])RR=mid;
						l=mid+1;
					}
				}
				pair<int,int>np=query(1,LL,RR);
				int pls=np.first;
				//加！
				//cout<<"plus on"<<pls<<' '<<"query is"<<LL<<'-'<<RR<<endl;
				tg[pls]++;
				upd(1,pls);
			}
		}
		int del=m;
		for(int i=1;i<=m;i++){
			//cout<<tg[i]<<' '<<dx[i]<<endl;
			if(tg[i])del--;
		}
		memset(tg,0,sizeof(tg));
		memset(tree,0,sizeof(tree));
		build(1,1,m);
		for(int i=n;i;i--){
			//每辆车
			if(chaosu[i]==0)continue;
			//cout<<"to"<<i<<endl;
			//cout<<d[i]<<' '<<to[i]<<endl;
			if(type[i]==3){//匀速 di - L
				//找在区间内的最小拍照点
				int l=1,r=m;
				int LL,RR;
				LL=RR=-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(pzd[mid]<d[i])l=mid+1;
					else{
						LL=mid;
						r=mid-1;
					}
				}
				pair<int,int>np=query(1,LL,m);
				int pls=np.first;
				//加！
				tg[pls]++;
				//cout<<"plus on"<<pls<<endl;
				upd(1,pls);
			}
			if(type[i]==2){//加速 d[i]+to[i] - L
				int l=1,r=m;
				int LL,RR;
				LL=RR=-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(pzd[mid]<d[i]+to[i])l=mid+1;
					else{
						LL=mid;
						r=mid-1;
					}
				}
				pair<int,int>np=query(1,LL,m);
				int pls=np.first;
				//加！
				tg[pls]++;
				//cout<<"plus on"<<pls<<endl;
				upd(1,pls);
			}
			if(type[i]==1){//减速 d[i] - d[i]+to[i]
				int l=1,r=m;
				int LL,RR;
				LL=RR=-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(pzd[mid]<d[i])l=mid+1;
					else{
						LL=mid;
						r=mid-1;
					}
				}
				l=1,r=m;
				while(l<=r){
					int mid=(l+r)/2;
					if(pzd[mid]>d[i]+to[i])r=mid-1;
					else{
						if(pzd[mid]>=d[i])RR=mid;
						l=mid+1;
					}
				}
				pair<int,int>np=query(1,LL,RR);
				int pls=np.first;
				//加！
				//cout<<"plus on"<<pls<<' '<<"query is"<<LL<<'-'<<RR<<endl;
				tg[pls]++;
				upd(1,pls);
			}
		}
		int del2=m;
		for(int i=1;i<=m;i++){
			//cout<<tg[i]<<' '<<dx[i]<<endl;
			if(tg[i])del2--;
		}
		//cout<<tg[i]<<'+'<<dx[i]<<' ';
		//cout<<endl;
		cout<<max(del,del2)<<endl;
	}
	return 0;
}
