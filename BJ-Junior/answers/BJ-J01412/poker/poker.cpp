#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s[55];
bool check(int x){
	for(int i=1;i<x;i++){
		if(s[x]==s[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		if(check(i)){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
