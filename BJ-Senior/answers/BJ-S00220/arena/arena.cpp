#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{int l,r,cnt,a[40];};
LL n,m,ans;
LL a[100010],aa[100010];
LL q[100010],X[5];
bool b[22][500010];
int c[22][500010];
void out(A tmp){
			cout<<tmp.cnt<<" "<<tmp.a[1]<<" "<<tmp.l<<" "<<tmp.r<<"\n";
}
A query(int k,int now,int l,int r,int p){
	if(p==r){A noww;noww.l=noww.r=0,noww.cnt=1,noww.a[1]=c[k][now];return noww;}
	int mid=(l+r)>>1;A tmp;
	if(p<=mid){
		tmp=query(k-1,now*2-1,l,mid,p);
		A kkk;kkk.l=kkk.r=kkk.cnt=0;int kkk2=0;
		if(!b[k][now]){
			for(int i=1;i<=tmp.cnt;i++)
				if(a[tmp.a[i]]>=k) kkk.cnt++,kkk.a[kkk.cnt]=tmp.a[i];
				else kkk2=1;
			if(tmp.l) kkk2=1;
			if(kkk2) kkk.l=tmp.l,kkk.r=r;
			if(kkk2&&!tmp.l) kkk.l=mid+1;
		}else{
			kkk.l=tmp.l,kkk.r=r;if(!kkk.l) kkk.l=mid+1;
			for(int i=1;i<=tmp.cnt;i++) kkk.cnt++,kkk.a[kkk.cnt]=tmp.a[i];
		}return kkk;
	}else{
		tmp=query(k-1,now*2,mid+1,r,p);
		A kkk;kkk.l=kkk.r=kkk.cnt=0;
		int cnt=c[k-1][now*2-1];
		if(!b[k][now]){
			if(cnt>=k) kkk.cnt=1,kkk.a[1]=cnt;
			else return tmp;
		}else{
			int kkk2=0;
			for(int i=1;i<=tmp.cnt;i++)
				if(a[tmp.a[i]]>=k) kkk.cnt++,kkk.a[kkk.cnt]=tmp.a[i];
				else kkk2=1;
			if(tmp.l) kkk2=1;
			if(kkk2) kkk.cnt++,kkk.a[kkk.cnt]=cnt;
			kkk.l=tmp.l,kkk.r=tmp.r;
		}return kkk;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>aa[i];
	for(int i=1;i<=m;i++) cin>>q[i];
	int k=0;while((1<<k)<n) k++;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=(1<<k-i);j++){
			char cc;cin>>cc;b[i][j]=cc-'0';
		}
	}
	int T;cin>>T;
	while(T--){
		cin>>X[0]>>X[1]>>X[2]>>X[3];ans=0;
		for(int i=1;i<=n;i++) a[i]=aa[i]^X[i%4];
		for(int i=1;i<=n;i++) c[0][i]=i;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=(1<<k-i);j++){
				if(!b[i][j]&&a[c[i-1][j*2-1]]>=i) c[i][j]=c[i-1][j*2-1];
				if(!b[i][j]&&a[c[i-1][j*2-1]]<i) c[i][j]=c[i-1][j*2];
				if(b[i][j]&&a[c[i-1][j*2]]>=i) c[i][j]=c[i-1][j*2];
				if(b[i][j]&&a[c[i-1][j*2]]<i) c[i][j]=c[i-1][j*2-1];
			}
		}
		for(int i=1;i<=m;i++){
			int kkkk=0;while((1<<kkkk)<q[i]) kkkk++;
			A tmp=query(kkkk,1,1,(1<<kkkk),q[i]);
			LL cnt=0;
			if(tmp.l) cnt=(tmp.l+tmp.r)*(tmp.r-tmp.l+1)/2;
			for(int j=1;j<=tmp.cnt;j++)
				if(tmp.a[j]<tmp.l||tmp.a[j]>tmp.r) cnt+=tmp.a[j];
			ans=ans^(i*(cnt));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
