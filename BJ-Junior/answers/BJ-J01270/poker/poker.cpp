#include<bits/stdc++.h>
using namespace std;
string x;
map<string,int> b;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.ans","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		b[x]++;
	}
	if(b.size()==52){
		cout<<0;
		return 0;
	}
	cout<<52-b.size();
	return 0;
}
