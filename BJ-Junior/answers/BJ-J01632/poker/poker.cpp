#include<bits/stdc++.h>
using namespace std;
int n;
string ss;
set<string> pp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ss;
		pp.insert(ss);
	}
	cout<<52-pp.size();
	return 0;
}