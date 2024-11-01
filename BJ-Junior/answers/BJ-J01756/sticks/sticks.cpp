#include <bits/stdc++.h>
using namespace std;
int t, n;
const int a[11]={-1, -1, 1, 7, 4, 2, 6, 8, 0, 0, 22};
void print(int x){
	int cnt=x/7;
	while(cnt--){
		cout<<8;
	}
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=7||n==10){
			cout<<a[n]<<endl;
			continue;
		}
		if(n%7==0){
			print(n);
			cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			n-=8;
			print(n);
			cout<<endl;
		}
		else if(n%7==2){
			cout<<1;
			n-=2;
			print(n);
			cout<<endl;
		}
		else if(n%7==3){
			cout<<200;
			n-=17;
			print(n);
			cout<<endl;
		}
		else if(n%7==4){
			cout<<20;
			n-=11;
			print(n);
			cout<<endl;
		}
		else if(n%7==5){
			cout<<2;
			n-=5;
			print(n);
			cout<<endl;
		}
		else{
			cout<<6;
			n-=6;
			print(n);
			cout<<endl;
		}
	}
	return 0;
}