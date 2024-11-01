#include<bits/stdc++.h>
#define N 100
using namespace std;
string s[N];
int n;
bool check(string ss){
	for(auto i:s){
		if(i==ss){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int ans=52;
	for(int i=1;i<=n;i++){
		string ss;
		cin>>ss;
		if(check(ss)){
			ans--;
		}
		s[i]=ss;
	}
	cout<<ans;
	return 0;
}