#include <iostream>
#include <cstdio>
using namespace std;
int T,n;
int d1[100010],d2[100010];
const int val[]={6,2,5,5,4,5,6,3,7,6};
void gowork(int x,int b) {
	if (x==0) return;
	for (int j=b;j<10;j++) {
		if (x>=val[j]&&d2[x-val[j]]+1==d2[x]) {
			cout << j;
			gowork(x-val[j],0);
			return;
		}
	}
}
int main(void) {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (int i=1;i<=100000;i++) d2[i]=d1[i]=1e9;
	d1[0]=0;
	for (int i=0;i<=100000;i++)
		for (int j=0;j<10;j++)
			d1[i+val[j]]=min(d1[i+val[j]],d1[i]+1);
	for (int i=0;i<=100000;i++)
		for (int j=1;j<10;j++)
			d2[i+val[j]]=min(d2[i+val[j]],d1[i]+1);
	for (;T--;) {
		cin >> n;
		if (d2[n]==1e9) {
			cout << "-1" << endl;
			continue;
		}
		gowork(n,1);
		cout << endl;
	}
	return 0;
}