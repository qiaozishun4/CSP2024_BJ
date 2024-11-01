#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int>p;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,s=0;
	string a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(!p[a]){
			p[a]=1;
			s++;
		}
	}
	cout<<52-s;
	return 0;
} 