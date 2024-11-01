#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long LL;
const int N=100010,T=17;
int pa[N],a[N],q[N];
vector<int> v[T];
string s[T];
inline void update(int p){
	int &u=v[p][v[p].size()-1],l=v[p-1][v[p-1].size()-2],r=v[p-1][v[p-1].size()-1];
	if(s[p][v[p].size()]==0)
		if(l>=p)
			u=l;
		else
			u=r;
	else
		if(r>=p)
			u=r;
		else
			u=l;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&pa[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&q[i]);
	sort(q+1,q+1+m);
	int sz,_n;
	for(sz=2,_n=1;_n*2<=n;sz++,_n<<=1)
		cin>>s[sz];
	int T;
	scanf("%d",&T);
	while(T--){
		int x[4];
		for(int i=0;i<4;i++)
			scanf("%d",&x[i]);
		for(int i=1;i<=n;i++)
			a[i]=pa[i]^x[i%4];
		LL res=0;
		for(int i=1,j=1;i<=n;i++){
			v[1].push_back(a[i]);
			for(int p=2;v[p].size()<v[p-1].size()/2;p++){
				v[p].push_back(0);
				update(p);
			}
			if(i==q[j]){
				int p=1;
				while(v[p].size())
					p++;
				p--;
				res^=(LL)j*v[p][0];
				j++;
			}
			/*for(int p=1;v[p].size();p++){
				for(auto u:v[p])
					printf("%d ",u);
				puts("");
			}*/
		}
		printf("%lld\n",res);
	}
	return 0;
}