#include <bits/stdc++.h>
using namespace std;
int n;
map<string,int> ms;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		ms[s]++;
	}
	cout<<52-ms.size();
	return 0;
}