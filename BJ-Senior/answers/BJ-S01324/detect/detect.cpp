#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <algorithm>
#define MAXN 100010
#define MAXL 1000010
#define sqr(x) ((x)*(x))
using namespace std;
struct car {
	int d,v,a;
};
int t,n,m,csyp[MAXN],l,v,asw1;
int yyv[MAXN];
car cs[MAXN];
vector<pair<int,int> > ncsy;
deque<int> alcsy;
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d %d %d",&n,&m,&l,&v);
		for (int i=0;i<n;i++) {
			scanf("%d %d %d",&cs[i].d,&cs[i].v,&cs[i].a);
		}
		for (int i=0;i<m;i++) {
			scanf("%d",csyp+i);
			yyv[i]=0;
		}
		asw1=0;
		for (int i=0;i<=n;i++) {
			if (cs[i].a==0) {
				if (cs[i].v>v&&csyp[m-1]>=cs[i].d) {
					asw1++;
					int j=m-1;
					for (;j>=0&&csyp[j]>=cs[i].d;j--) {
						yyv[j]++;
					}
					ncsy.push_back(make_pair(j+1,m-1));
				}
			} else if (cs[i].a<0) { // 减速
				int j=m-1;
				while (j>=0&&csyp[j]>=cs[i].d) j--;
				j++;
				if (csyp[j]>=cs[i].d) { // 找到测速仪
					int wyssqr=sqr(cs[i].v)+2*cs[i].a*(csyp[j]-cs[i].d);	
					if (wyssqr>sqr(v)) { // 超速
						asw1++;
						int p=j;
						for (;p<m;p++) {
							wyssqr=sqr(cs[i].v)+2*cs[i].a*(csyp[p]-cs[i].d);
							if (wyssqr<=sqr(v)) break;
							yyv[p]++;
						}
						ncsy.push_back(make_pair(j,p-1));
					}
				}
			} else { // 加速
				if (csyp[m-1]>=cs[i].d) {
					int wyssqr=sqr(cs[i].v)+2*cs[i].a*(csyp[m-1]-cs[i].d);
					if (wyssqr>sqr(v)) { // 超速
						asw1++;
						int j=m-1;
						for (;j>=0&&csyp[j]>=cs[i].d;j--) {
							wyssqr=sqr(cs[i].v)+2*cs[i].a*(csyp[j]-cs[i].d);
							if (wyssqr<=sqr(v)) {
								break;
							}
							yyv[j]++;
						}
						ncsy.push_back(make_pair(j+1,m-1));
					}
				}
			}
		}
		printf("%d",asw1);
		/*for (auto each:ncsy) {
			printf("l=%d,r=%d\n",each.first,each.second);
		}*/
		for (int i=0;i<m;i++) {
			alcsy.push_back(i);
		}
		sort(alcsy.begin(),alcsy.end(),[](int a,int b)->bool{
			return yyv[a]<yyv[b];
		});
		while (!alcsy.empty()) {
			alcsy.pop_front();
			bool able1=1;
			for (auto each:ncsy) {
				bool able2=0;
				for (int csy:alcsy) {
					if (csy>=each.first&&csy<=each.second) {
						able2=1;
						break;
					}
				}
				if (!able2) {
					 able1=0;
					 break;
				}
			}
			if (!able1) {
				printf(" %ld\n",m-alcsy.size()-1);
				break;
			}
		}
		alcsy.clear();
		ncsy.clear();
	}
	return 0;
}
			
										
							
				
