#include<bits/stdc++.h>
using namespace std;
set<string> st;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string x;
	cin>>n;
	while(n--){
		cin>>x;
		st.insert(x);
	}
	cout<<52-st.size();
	return 0;
}
