#include<bits/stdc++.h>
using namespace std;
set<string>st;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string q;
		cin>>q;
		st.insert(q);
	}
	cout<<52-st.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
