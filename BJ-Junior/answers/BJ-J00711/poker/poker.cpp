#include<bits/stdc++.h>
using namespace std;
string s[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	int m=n;
	for(int i=1;i<=n;i++){
		if(s[i]==s[i-1]){
			m--;
		}
	}
	cout<<52-m;
	return 0;
}