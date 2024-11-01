#include<bits/stdc++.h>
using namespace std;
int d[15];
int c[15];
int h[15];
int s1[15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s[0]=='D'){
			if(s[1]=='T'){
				d[10]++;
			}
			else if(s[1]=='A'){
				d[1]++;
			}
			else if(s[1]=='J'){
				d[11]++;
			}
			else if(s[1]=='Q'){
				d[12]++;
			}
			else if(s[1]=='K'){
				d[13]++;
			}
			else{
				d[s[1]-'1'+1]++;
			}
		}
		else if(s[0]=='C'){
			if(s[1]=='T'){
				c[10]++;
			}
			else if(s[1]=='A'){
				c[1]++;
			}
			else if(s[1]=='J'){
				c[11]++;
			}
			else if(s[1]=='Q'){
				c[12]++;
			}
			else if(s[1]=='K'){
				c[13]++;
			}
			else{
				c[s[1]-'1'+1]++;
			}
		}
		else if(s[0]=='H'){
			if(s[1]=='T'){
				h[10]++;
			}
			else if(s[1]=='A'){
				h[1]++;
			}
			else if(s[1]=='J'){
				h[11]++;
			}
			else if(s[1]=='Q'){
				h[12]++;
			}
			else if(s[1]=='K'){
				h[13]++;
			}
			else{
				h[s[1]-'1'+1]++;
			}
		}
		else if(s[0]=='S'){
			if(s[1]=='T'){
				s1[10]++;
			}
			else if(s[1]=='A'){
				s1[1]++;
			}
			else if(s[1]=='J'){
				s1[11]++;
			}
			else if(s[1]=='Q'){
				s1[12]++;
			}
			else if(s[1]=='K'){
				s1[13]++;
			}
			else{
				s1[s[1]-'1'+1]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=13;i++){
		if(d[i]==0){
			ans++;
		}
		if(h[i]==0){
			ans++;
		}
		if(c[i]==0){
			ans++;
		}
		if(s1[i]==0){
			ans++;
		}
	}
	cout<<ans;
    return 0;
}
