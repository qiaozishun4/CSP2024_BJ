#include <bits/stdc++.h>
using namespace std;
set <string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string ss;
	cin>>n;
	int ans = 0;
	while(n--){
		cin>>ss;
		s.insert(ss);
	}
	cout<<52-s.size();
}
