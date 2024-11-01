#include <bits/stdc++.h>
using namespace std;
int n,H,D,cnt=0;
int a[5][15];
char h,d;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>h>>d;
		if (h=='D') H=1;
		if (h=='C') H=2;
		if (h=='H') H=3;
		if (h=='S') H=4;
		if (d=='A') D=1;
		if (d=='T') D=10;
		if (d=='J') D=11;
		if (d=='Q') D=12;
		if (d=='K') D=13;
		if (d>='2' && d<='9') D=d-'0';
		a[H][D]=1;
	}
	for (int i=1;i<=4;i++){
		for (int j=1;j<=13;j++){
			cnt+=(1-a[i][j]);
		}
	}
	cout<<cnt;
	return 0;
}
