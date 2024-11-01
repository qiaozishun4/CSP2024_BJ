#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int d[100005],v[100005],a[100005],p[100005],minin=0x3f,lastp=-1,nott[100005],ncnt,overspeed,ans2;
void mem(){
	for(int i=0;i<=100003;i++){
		d[i]=v[i]=a[i]=p[i]=nott[i]=0;
		minin=0x3f;
		lastp=-1;
		ncnt=overspeed=ans2=0;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		mem();
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			minin=min(minin,d[i]);
			if(v[i]>V)
				overspeed++;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			lastp=max(lastp,p[i]);
		}
		for(int i=1;i<=n;i++){
			if(d[i]>lastp){
				ncnt++;
				nott[ncnt]=i;
				continue;
			}
		}
		ans2=m-1;
		cout<<overspeed<<" "<<ans2<<endl;
	}
	return 0;
}