#include<bits/stdc++.h>
using namespace std;
int h[50][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char op,x;
		cin>>op>>x;
		if(x=='A') h[op-'A'][1]++;
		if(x=='J') h[op-'A'][11]++;
		if(x=='Q') h[op-'A'][12]++;
		if(x=='K') h[op-'A'][13]++;
		if(x=='T') h[op-'A'][10]++;
		if(x>='2'&&x<='9') h[op-'A'][x-'0']++;
	}
	for(int i=1;i<=13;i++){
		if(h[18][i]>0) cnt++;
		if(h[3][i]>0) cnt++;
		if(h[2][i]>0) cnt++;
		if(h[7][i]>0) cnt++;
	}
	int ans=52-cnt;
	cout<<ans;
	return 0;
}