#include <cstdio>
#include <vector>
#include <bitset>
#define MAXN 100
using namespace std;
char allds[]{'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char allhs[]{'D','C','H','S'};
char buff[32];
int n,asw;
struct pkp {
    char hs,ds;
};
bitset<MAXN> hasp;
int get_hash(pkp x) {
    int ds;
    for (int i=0;i<13;i++) {
        if (x.ds==allds[i]) {
            ds=i;
            break;
        }
    }
    int hs;
    for (int i=0;i<4;i++) {
        if (x.hs==allhs[i]) {
            hs=i;
            break;
        }
    }
    ds++;
    hs++;
    return 13*(hs-1)+ds;
}
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
		scanf("%s",buff);
		pkp tmp;
		tmp.hs=buff[0];
		tmp.ds=buff[1];
		hasp[get_hash(tmp)]=1;
	}
	for (int i=1;i<=52;i++) {
		if (!hasp[i]) {
			asw++;
		}
	}
	printf("%d",asw);
    return 0;
}
