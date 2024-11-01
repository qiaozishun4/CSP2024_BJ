#include<bits/stdc++.h>
using namespace std;
int n;
string s;
set<string>st;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		st.insert(s);
	}
	n=0;
	for(auto i:st){
		n++;
	}
	cout<<52-n;
}
