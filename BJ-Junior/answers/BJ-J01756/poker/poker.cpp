#include <bits/stdc++.h>
using namespace std;
int n, cnt=52;
bool t[4][14];
char a, b;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w",stdout);
	cin>>n;
	while(n--){
		int t1, t2;
		cin>>a>>b;
		if(a=='D'){
			t1=0;
		}
		else if(a=='C'){
			t1=1;
		}
		else if(a=='H'){
			t1=2;
		}
		else{
			t1=3;
		}
		if(b=='A'){
			t2=1;
		}
		else if(b=='T'){
			t2=10;
		}
		else if(b=='J'){
			t2=11;
		}
		else if(b=='Q'){
			t2=12;
		}
		else if(b=='K'){
			t2=13;
		}
		else{
			t2=b-'0';
		}
		if(!t[t1][t2]){
			cnt--;
			t[t1][t2]=1;
		}
	}
	cout<<cnt;
	return 0;
}