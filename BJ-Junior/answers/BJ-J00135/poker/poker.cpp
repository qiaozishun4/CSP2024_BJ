#include<bits/stdc++.h>
using namespace std;
int n,ss,ans=52;
bool sy[60];
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s;
		ss=0;
		if(s[0]=='C'){
			ss+=13;
		}else if(s[0]=='H'){
			ss+=26;
		}else if(s[0]=='S'){
			ss+=39;
		}
		if('2'<=s[1]&&s[1]<='9'){
			ss+=s[1]-'1';
		}else if(s[1]=='T'){
			ss+=9;
		}else if(s[1]=='J'){
			ss+=10;
		}else if(s[1]=='Q'){
			ss+=11;
		}else if(s[1]=='K'){
			ss+=12;
		}
		ans--;
		if(sy[ss]){
			ans++;
		}else{
			sy[ss]=1;
		}
	}
	cout << ans;
	return 0;
}
