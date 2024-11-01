#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	map<string,int>m;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(m[s]==0){
			m[s]=1;
			cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
}
