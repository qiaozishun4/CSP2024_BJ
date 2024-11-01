#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
const int N=62;
string s[N];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		bool f=0;
		for(int j=1;j<i;j++){
			if(s[i]==s[j]){
				f=1;
				break;
			}
		}
		if(!f) cnt++;
	}
	cout<<52-cnt;
	return 0;
}