#include <cstdio>
#include <string>
#include <algorithm>
#define MAXL 100010
using namespace std;
int stkn[10]{6,2,5,5,4,5,6,3,7,6};
int bettc[10]{0,2,1,3,4,5,6,8,9,7};
int t,n,isf;
string asw;
bool cmp(string a,string b) {
	if (a.length()!=b.length()) {
		return a.length()<b.length();
	}
	for (int i=a.length()-1;i>=0;i--) {
		if (a[i]!=b[i]) {
			return a[i]<b[i];
		}
	}
	return false;
}
void dfs(int las,string num) {
	if (las<=0) {
		if (las==0&&num[num.length()-1]!='0') {
			if (isf||!cmp(asw,num)) {
				asw=num;
				isf=0;
			}
		}
		return;
	}
	for (int i=0;i<10;i++) {
		dfs(las-stkn[i],(char)(i+'0')+num);
	}
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	/*sort(bettc,bettc+10,[](int a,int b)->bool{
		return 1.0*stkn[a]/a>1.0*stkn[b]/b;
		});*/
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		isf=1;
		dfs(n,"");
		if (isf) {
			puts("-1");
		} else {
			for (int i=0;i<(int)asw.length();i++) {
				putchar(asw[asw.length()-i-1]);
			}
			puts("");
		}
	}
	return 0;
}	
