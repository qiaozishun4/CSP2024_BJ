#include<bits/stdc++.h>
using namespace std;
int num[30]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int T;
int n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	int cnt=0;
	string ans;
	while(T--){
		cnt=0;
		cin>>n;
		cnt=(n/7)-3;
		if(n%7!=0) cnt++;
		cnt=max(cnt,0);
		cout<<num[n-(7*cnt)];
		for(int i=1;i<=cnt;i++){
			cout<<8;
		}
		cout<<"\n";
	}
	return 0;
}