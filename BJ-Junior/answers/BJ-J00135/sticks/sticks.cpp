#include<bits/stdc++.h>
using namespace std;
int T,n,nn,ans;
bool f;
int d[10]={6,2,5,5,4,5,6,3,7,6},mnd[8]={-1,-1,1,7,4,2,0,8};
void sv(){
	nn=0;
	cin >> n;
	if(n<8){
		if(mnd[n]==0){
			mnd[n]=6;
		}
		cout << mnd[n] << "\n";
		if(mnd[n]==6){
			mnd[n]=0;
		}
		return;
	}
	if(n==10){
		cout << 40 << "\n";
		return;
	}
	if(n%7==0){
		for(int i=1;i<=n/7;i++){
			cout << 8;
		}
		cout << "\n";
		return;
	}else if(n%7==1){
		cout << 10;
		for(int i=1;i<n/7;i++){
			cout << 8;
		}
		cout << "\n";
		return;
	}else if(n%7==2){
		cout << 1;
		for(int i=1;i<=n/7;i++){
			cout << 8;
		}
		cout << "\n";
		return;
	}else if(n%7==3){
		cout << 200;
		for(int i=1;i<n/7-1;i++){
			cout << 8;
		}
		cout << "\n";
		return;
	}else if(n%7==4){
		cout << 20;
		for(int i=1;i<n/7;i++){
			cout << 8;
		}
		cout << "\n";
		return;
	}else if(n%7==5){
		cout << 2;
		for(int i=1;i<=n/7;i++){
			cout << 8;
		}
		cout << "\n";
		return;
	}else if(n%7==6){
		cout << 80;
		for(int i=1;i<n/7;i++){
			cout << 8;
		}
		cout << "\n";
		return;
	}
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		sv();
	}
	return 0;
}
