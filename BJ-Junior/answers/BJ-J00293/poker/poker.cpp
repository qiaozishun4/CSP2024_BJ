#include <iostream>
#include <cstring>
using namespace std;
int a[5][14];
int cnt=0;
char b[14]={'?','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		char c1,c2;
		cin>>c1>>c2;
		int t1,t2;
		if(c1=='D') t1=1;
		if(c1=='C') t1=2;
		if(c1=='H') t1=3;
		if(c1=='S') t1=4;
		for(int i=1;i<=13;i++) {
			if(b[i]==c2) {
				t2=i;
				break;
			}
		}
		a[t1][t2]++;
	}
	for(int i=1;i<=4;i++) {
		for(int j=1;j<=13;j++) {
			//cout<<a[i][j]<<" ";
			if(a[i][j]==0) {
                cnt++;
			}
		}
		//cout<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
