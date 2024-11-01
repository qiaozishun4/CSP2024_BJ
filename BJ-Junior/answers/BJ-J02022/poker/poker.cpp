#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n;
set<string> st;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i ++){
		cin >> s;
		st.insert(s);
	}
	cout << 52 - st.size();
	
	
	return 0;
}
