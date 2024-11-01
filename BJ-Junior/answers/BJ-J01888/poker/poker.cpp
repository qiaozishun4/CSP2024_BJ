#include <bits/stdc++.h>
using namespace std;
int h[200][200];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int ans=52;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(!h[s[0]][s[1]]){
			ans--;
			h[s[0]][s[1]]++;
		}
	}
	cout<<ans;
	return 0;
}
