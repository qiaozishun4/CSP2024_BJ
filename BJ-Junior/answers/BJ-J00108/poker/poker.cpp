#include<bits/stdc++.h>
using namespace std;
int n;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string cur;
		cin>>cur;
		s.insert(cur);
	}
	cout<<52-s.size()<<endl;
}
