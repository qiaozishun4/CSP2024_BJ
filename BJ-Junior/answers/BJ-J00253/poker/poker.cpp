#include<bits/stdc++.h>
using namespace std;
int a[21]={},b[21]={},c[21]={},d[21]={};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		if(s[0]=='D'){
			if(s[1]>='2'&&s[1]<='9'){
				a[s[1]-'0']++;
			}else if(s[1]=='T'){
				a[10]++;
			}else if(s[1]=='J'){
				a[11]++;
			}else if(s[1]=='Q'){
				a[12]++;
			}else if(s[1]=='K'){
				a[13]++;
			}else if(s[1]=='A'){
				a[1]++;
			}
		}else if(s[0]=='C'){
			if(s[1]>='2'&&s[1]<='9'){
				b[s[1]-'0']++;
			}else if(s[1]=='T'){
				b[10]++;
			}else if(s[1]=='J'){
				b[11]++;
			}else if(s[1]=='Q'){
				b[12]++;
			}else if(s[1]=='K'){
				b[13]++;
			}else if(s[1]=='A'){
				b[1]++;
			}
		}else if(s[0]=='H'){
			if(s[1]>='2'&&s[1]<='9'){
				c[s[1]-'0']++;
			}else if(s[1]=='T'){
				c[10]++;
			}else if(s[1]=='J'){
				c[11]++;
			}else if(s[1]=='Q'){
				c[12]++;
			}else if(s[1]=='K'){
				c[13]++;
			}else if(s[1]=='A'){
				c[1]++;
			}
		}else if(s[0]=='S'){
			if(s[1]>='2'&&s[1]<='9'){
				d[s[1]-'0']++;
			}else if(s[1]=='T'){
				d[10]++;
			}else if(s[1]=='J'){
				d[11]++;
			}else if(s[1]=='Q'){
				d[12]++;
			}else if(s[1]=='K'){
				d[13]++;
			}else if(s[1]=='A'){
				d[1]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=13;i++){
		if(a[i]==0){
			ans++;
		}
	}
	for(int i=1;i<=13;i++){
		if(b[i]==0){
			ans++;
		}
	}
	for(int i=1;i<=13;i++){
		if(c[i]==0){
			ans++;
		}
	}
	for(int i=1;i<=13;i++){
		if(d[i]==0){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}