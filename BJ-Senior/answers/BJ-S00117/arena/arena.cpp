#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e5+5;
ll n,m,a_[N],a[N];
int d[32][N];
struct qu{
	ll c,id;
}q[M];
bool operator<(qu a,qu b){return a.c<b.c;}
struct K_1{
	
}T1;
struct Sakuya{
	ll A[32],B,C;
	void init(){memset(A,0,sizeof(A));B=C=0;}
};
ll cnt[32];
Sakuya divide(ll l,ll r,ll dep,ll lim){
	//这里有一个显然的优化，容易发现vector不是都有必要的，有一些数字太大了（>31)，他们可以直接归类为
	//所以开一个31的数字就够了
	if(l==r){
		Sakuya tmp;tmp.init();
		if(l>lim){tmp.C=l;}
		else if(a[l]<=31){tmp.A[a[l]]=l;}
		else{tmp.B=l;}
		return tmp;
	}
	//first指的是正常的编号和。
	//second指的是有可能的编号和（因为他的值是你自己定义的）
	ll mid=l+r>>1;
	Sakuya tl=divide(l,mid,dep-1,lim);
	Sakuya tr=divide(mid+1,r,dep-1,lim);
	ll now=d[dep][++cnt[dep]];
	//cout<<"NOW"<<l<<' '<<mid<<' '<<mid+1<<' '<<r<<' '<<now<<' '<<dep<<' '<<cnt[dep]<<endl;
	Sakuya tmp;tmp.init();
	if(now==0){//看看左边和dep的大小关系
		bool flag=tl.C;
		tmp.B+=tl.B;tmp.C+=tl.C;
		for(int i=0;i<32;i++){
			if(tl.A[i]==0)continue;
			if(i>=dep){//able to zhan sheng
				tmp.A[i]+=tl.A[i];
			}
			else flag=1;
		}
		if(flag){
			for(int i=0;i<32;i++){
				tmp.A[i]+=tr.A[i];
			}
			tmp.B+=tr.B;
			tmp.C+=tr.C;
		}
	}
	else{//看看右边
		bool flag=tr.C;
		tmp.B+=tr.B;tmp.C+=tr.C;
		for(int i=0;i<32;i++){
			if(tr.A[i]==0)continue;
			if(i>=dep){//able to zhan sheng
				tmp.A[i]+=tr.A[i];
			}
			else flag=1;
		}
		if(flag){
			for(int i=0;i<32;i++){
				tmp.A[i]+=tl.A[i];
			}
			tmp.B+=tl.B;
			tmp.C+=tl.C;
		}
		//else if(tr.second){tmp2+=tl.second;}
	}//cout<<"TMP1 "<<endl;
	//for(int i=0;i<tmp1.size();i++){
		//cout<<tmp1[i].first<<' '<<tmp1[i].second<<endl;
	//}
	//cout<<"TMP2 "<<tmp2<<endl;
	return tmp;
}
ll work(ll c){
	//if(c<=5000){
		ll tmp1=1,tmp2=0;memset(cnt,0,sizeof(cnt));
		while(tmp1<c)tmp1<<=1,tmp2++;
		Sakuya ans=divide(1,tmp1,tmp2,c);
		ll genshin=ans.B+ans.C;
		for(int i=0;i<32;i++){
			genshin+=ans.A[i];
		}return genshin;
	//}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a_[i];
	for(int i=1;i<=m;i++){cin>>q[i].c;q[i].id=i;}
	//cout<<a_[n]<<' '<<q[m].c<<endl;
	//sort(q+1,q+m+1);
	string s;ll cnt=0;
	while(cin>>s){
		ll len=s.length();cnt++;
		for(int i=0;i<len;i++)d[cnt][i+1]=s[i]-'0';
		if(s.length()==1)break;
	}
	int T;cin>>T;//cout<<"T"<<T<<endl;system("pause");
	while(T--){
		ll x[4];cin>>x[0]>>x[1]>>x[2]>>x[3];//cout<<"A:";
		for(int i=1;i<=n;i++)a[i]=a_[i]^x[i%4];//,cout<<a[i]<<' ';cout<<endl;
		ll genshin=0;
		for(int i=1;i<=m;i++){
			int tmp=work(q[i].c);//cout<<tmp<<endl;//cin>>tmp;//exit(0);
			genshin^=q[i].id*tmp;
		}cout<<genshin<<'\n';
	}
	return 0;
}
/*
5 1
0 0 0 0 0
5
1001
10
1
1
2 1 0 0

 * */
