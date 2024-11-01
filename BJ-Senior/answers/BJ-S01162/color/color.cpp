#include<bits/extc++.h>
using namespace std;
enum{_n=200005,_A=1000007,_sqn=450};
int A[_n];
int64_t F[_n],W[_n];
int C[_A],D[_A],E[_sqn],d;
int H[_A],nxt[_n];
__gnu_pbds::priority_queue<int64_t> Q[_sqn],q;
decltype(q)::point_iterator ITS[_n];
int main(){
freopen("color.in","r",stdin);
freopen("color.out","w",stdout);

cin.tie(0)->sync_with_stdio(0);
int T,n;
cin>>T;
while(T--){
	cin>>n; int sqn=sqrt(n);
	bzero(C,4*_A),bzero(D,4*_A),d=0,
	bzero(H,4*_A);
	Q[0].clear();
	for(int i=1;i<=n;++i)
		cin>>A[i],nxt[i]=H[A[i]],H[A[i]]=i,++C[A[i]];
	for(int i=1;i<_A;++i)
		if(C[i]>sqn) D[i]=++d,E[d]=i;
	for(int i=1;i<=n;++i)
		W[i]=W[i-1]+A[i]*(A[i]==A[i-1]);
	ITS[1]=Q[0].push(F[1]=0);
	for(int i=1;i<=d;++i)
		Q[i].clear(),Q[i].push(0);
	for(int i=2;i<=n;++i){
		if(D[A[i]])
			F[i]=Q[D[A[i]]].top()+W[i-1];
		else{
			int j=i;
			while(j=nxt[j]) if(j<i-1)
				Q[0].modify(ITS[j+1],F[j+1]-W[j+1]+A[i]);
			F[i]=Q[0].top()+W[i-1];
			j=i;
			while(j=nxt[j]) if(j<i-1) 
				Q[0].modify(ITS[j+1],F[j+1]-W[j+1]);
		}
		ITS[i]=Q[0].push(F[i]-W[i]);
		for(int k=1;k<=d;++k)
			Q[k].push(F[i]-W[i]+A[i-1]*(A[i-1]==E[k]));
	}
	cout<<Q[0].top()+W[n]<<'\n';
}
}