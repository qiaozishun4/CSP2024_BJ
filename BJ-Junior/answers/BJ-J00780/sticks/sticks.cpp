#include <bits/stdc++.h>
using namespace std;
string a[10000]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","80","88","108","188"};
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >>T;
	while(T--){
		cin >>n;
		if(n<=11)cout <<a[n];
		else if(n==17) cout <<220;
		else{
			cout << a[11+(n-11)%7];
			n=(n-11)/7;
			while(n--) cout<<8;
		}
		cout <<"\n";
	}
	return 0;
}