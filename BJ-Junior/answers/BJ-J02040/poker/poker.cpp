#include<bits/stdc++.h>
using namespace std;
bool h[5][14];
int ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0] == 'D'){
			s[0]=1;
		}
		if(s[0] == 'C'){
			s[0]=2;
		}
		if(s[0] == 'H'){
			s[0]=3;
		}
		if(s[0] == 'S'){
			s[0]=4;
		}
		if(s[1] == 'T'){
			s[1]=10;
		}
		else if(s[1] == 'A'){
			s[1]=1;
		}
		else if(s[1] == 'J'){
			s[1]=11;
		}
		else if(s[1] == 'Q'){
			s[1]=12;
		}
		else if(s[1] == 'K'){
			s[1]=13;
		}
		else{
			s[1]-='0';
		}
		h[int(s[0])][int(s[1])]=1;
		//cout<<int(s[0])<<" "<<int(s[1])<<"\n";
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!h[i][j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
