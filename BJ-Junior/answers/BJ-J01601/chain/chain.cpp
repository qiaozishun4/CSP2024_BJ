#include <cstdio>
#include <vector>
#define MAXN 100010
//#define debug
using namespace std;
int t,n,k,q,cando;
int l[MAXN],r,c;
vector<int> s[MAXN];
vector<vector<int> > pool;
vector<int> jlp;
void pdebug() {
	#ifdef debug
	/*puts("Here is queue:");
	for (int i=0;i<(int)pool.size();i++) {
		printf("person num %d:",jlp[i]);
		for (int j=0;j<(int)pool[i].size();j++) {
			printf("%d ",pool[i][j]);
		}
		puts("");
	}
	printf("cando=%d\n",cando);*/
	#endif
}
void dfs(int las,int lasp,int cnt) {
	if (cando) return;
	#ifdef debug
	printf("dfs at las=%d,lasp=%d,cnt=%d\n",las,lasp,cnt);
	#endif
	pdebug();
	if (cnt>=r) {
		if (las==c) {
			cando=1;
		}
		return;
	}
	#ifdef debug
	int isc=0;
	#endif
	for (int i=0;i<n;i++) { // 选择第i个人
		if (i!=lasp) { // 上一次接龙的禁止接龙
			for (int j=0;j<l[i];j++) { // 选择接龙序列
				if (s[i][j]==las) { // 首字母匹配
					#ifdef debug
					isc=1;
					#endif
					for (int p=2;p<=k&&j+p<=l[i];p++) {
						#ifdef debug 
						vector<int> tmp;
						for (int w=j;w<j+p;w++) {
							tmp.push_back(s[i][w]);
						}
						jlp.push_back(i);
						pool.push_back(tmp);
						#endif
						dfs(s[i][j+p-1],i,cnt+1); // 下个人接龙
						#ifdef debug
						tmp.pop_back();
						jlp.pop_back();
						#endif
						if (cando) break;
					}
				}
				if (cando) break;
			}		
		}
	}
	#ifdef debug
	if (isc==0) {
		puts("can't find any thing!\n");
	}
	#endif
}
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d %d",&n,&k,&q);
		for (int i=0;i<n;i++) {
			s[i].clear();
			scanf("%d",l+i);
			int tmp;
			for (int j=0;j<l[i];j++) {
				scanf("%d",&tmp);
				s[i].push_back(tmp);
			}
			
		}
		for (int i=0;i<q;i++) {
			scanf("%d %d",&r,&c);
			cando=0;
			dfs(1,-1,0);
			if (cando) {
				puts("1");
			} else {
				puts("0");
			}
		}
	}
	return 0;
}
