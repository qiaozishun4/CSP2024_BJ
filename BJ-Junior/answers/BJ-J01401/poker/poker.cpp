#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[20][20];
int trs(char s){
	if(s=='A') return 1;
	if('2'<=s&&s<='9') return s-'0';
	if(s=='T') return 10;
	if(s=='J') return 11;
	if(s=='Q') return 12;
	if(s=='K') return 13;
	if(s=='D') return 1;
	if(s=='H') return 2;
	if(s=='C') return 3;
	if(s=='S') return 4;
}
void solve(){
	int num=52;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int x=trs(s[0]);
		int y=trs(s[1]);
		if(!vis[x][y]){
			vis[x][y]=1;
			num--;
		}
	}
	cout<<num;
	return ;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
//	int T;
//	cin>>T;
//	while(T--){
		solve();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

