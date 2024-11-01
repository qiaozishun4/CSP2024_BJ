#include <bits/stdc++.h>
using namespace std;
int n;
char s[4];
bool sf[1000];
bool sh[1000];
bool dh[1000];
bool dc[1000];
int ans;
int main(){
	memset(sf,false,sizeof(sf));
	memset(sf,false,sizeof(sh));
	memset(sf,false,sizeof(dh));
	memset(sf,false,sizeof(dc));
	cin>>n;
	ans=52-n;
	for (int i=1;i<=n;i++){
		cin>>s;
		if (s[0]=='D'){
			if (sf[s[1]]==true){
				ans++;
				continue;
			}
			sf[s[1]]=true;
		}
		else if (s[0]=='C'){
			if (dc[s[1]]==true){
				ans++;
				continue;
			}
			dc[s[1]]=true;
		}
		else if (s[0]=='H'){
			if (sh[s[1]]==true){
				ans++;
				continue;
			}
			sh[s[1]]=true;
		}
		else{
			if (dh[s[1]]==true){
				ans++;
				continue;
			}
			dh[s[1]]=true;
		}
	}
	cout<<ans;
	return 0;
}
