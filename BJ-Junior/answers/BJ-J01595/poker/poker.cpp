#include<bits/stdc++.h>
using namespace std;
string s;
map<char,map<char,long long> > mp;
char a[4]={'D','C','H','S'};
char b[20]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
	long long n;
	cin>>n;
	while(n--){
		cin>>s;
		mp[s[0]][s[1]]=1;
	}
	long long ans=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(!mp[a[i]][b[j]])ans++;
		}
	}
	cout<<ans;
	return 0;
}
