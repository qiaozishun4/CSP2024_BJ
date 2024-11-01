#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=25,K=1e6+10;
int T,n,m,L,V,ans1,ans2;
int d[N],v[N],a[N],p[N];
int s[K],ns[K],k[K],Lp[N];
int st[K][M],ck[K],vis[K];
vector<int>add[K],mie[K];
void init(){
	ans1=ans2=n=m=V=L=0;
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	memset(s,0,sizeof(s));
	memset(k,0,sizeof(k));
	memset(ns,0,sizeof(ns));
	memset(Lp,0,sizeof(Lp));
	memset(st,0,sizeof(st));
	memset(ck,0,sizeof(ck));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)add[i].clear();
	for(int i=1;i<=n;i++)mie[i].clear();
}
int find(int i){
	if(a[i]==0 && v[i]>V)return 1;
	if(a[i]<0 && v[i]<=V)return -1;
	if(a[i]==0)return -1;
	int x1=V*V-v[i]*v[i];
	int x2=2*a[i];
	int c=x1/x2;
	//cout<<i<<' '<<x1<<' '<<x2<<' '<<c<<endl;
	if(x2*c==x1){
		if(a[i]>0)return c+1;
		else return c-1;
	}
	else{
		if(a[i]>0)return c+1;
		return c;
	}
}
int slove_st(int k){
	for(int i=20;i>=0;i--){
		if(st[k][i]==0)k=k+(1<<i)-1;
		if(k>=L)return L;
		//cout<<k<<' '<<i<<endl;
	}
	return k;
}
void slove1(){
	for(int i=1;i<=n;i++){
		k[i]=d[i]+find(i);
		if(k[i]==d[i]-1)continue;
		//cout<<"www"<<k[i]<<' ';
		if(a[i]>0){
			s[k[i]]++;
			add[k[i]].push_back(i);
		}
		else if(a[i]==0){
			s[d[i]]++;
			add[d[i]].push_back(i);
		}
		else {
			s[d[i]]++;
			ns[k[i]+1]++;
			add[d[i]].push_back(i);
			mie[k[i]+1].push_back(i);
		}
	}
	//cout<<endl;
	set<int>q;
	for(int i=0;i<=L;i++){
		//增加
		if(s[i]){
			for(int j=0;j<add[i].size();j++){
				q.insert(add[i][j]);
				//cout<<"push"<<' '<<i<<' '<<add[i][j]<<endl;
			}
		}
		//check
		if(Lp[i]==1){
			for(set<int> :: iterator it=q.begin();it!=q.end();it++ ){
				//cout<<*it<<endl;
				if(*it==0)break;;
				//cout<<i<<' '<<"is ok"<<' '<<*it<<endl;
				ans1++;
				q.erase(it);
				vis[*it]=1;
				//cout<<'f'<<endl;
			}
		}
		//减少
		//cout<<'s'<<' '<<ns[i]<<endl;
		if(ns[i]){
			for(int j=0;j<mie[i].size();j++){
				if(vis[mie[i][j]]!=1){
					//cout<<i<<" is No "<<mie[i][j]<<endl;
					ns[i]--;
					q.erase(mie[i][j]);
				}
			}
		}
	}
	for(int i=1;i<=L;i++)s[i]+=s[i-1]+ns[i-1];
}
void slove2(){
	for(int i=1;i<=L;i++)st[i][0]=ns[i];
	for(int i=1;i<=L;i++)ck[i]=Lp[i]+ck[i-1];
	//for(int i=1;i<=L;i++)cout<<st[i][0]<<' ';
	//cout<<endl;
	for(int j=1;j<=20;j++)for(int i=0;i<=L;i++)st[i][j]=st[i][j-1]+st[i+(1<<(j-1))][j-1];
	/*for(int j=1;j<=20;j++){
		for(int i=0;i<=L;i++)cout<<st[i][j]<<' ';
		cout<<endl;
	}*/
	int w=1000000,tid=0;
	for(int i=1;i<=n;i++){
	//cout<<p[i]<<endl;;
		int down_id=slove_st(p[i]);
		//cout<<"aaaaaaaaaaaaaaaaaaa"<<' '<<down_id<<' '<<ck[p[i]]<<' '<<ck[down_id]<<endl;
		//cout<<w<<' '<<s[i]<<endl;
		if(ck[down_id]-ck[p[i]]>0 || (w==s[i] || slove_st(tid)>=i+1)){
			ans2++;
		}
		else{
		 w=s[i];
		 tid=i;
		 }
	}
}
int main(){	
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&p[i]);
		for(int i=1;i<=m;i++)Lp[p[i]]=1;
		slove1();//cout<<ans1<<endl;
		slove2();
		printf("%d %d\n",ans1,ans2);
		init();
	}
fclose(stdin);
fclose(stdout);
	return 0;
}