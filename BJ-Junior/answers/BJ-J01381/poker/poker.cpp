#include <bits/stdc++.h>
using namespace std;
int a[60][60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(a[s[0]-'0'][s[1]-'0']==0){
			ans++;
		}
		a[s[0]-'0'][s[1]-'0']++;
	}
	cout<<52-ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
