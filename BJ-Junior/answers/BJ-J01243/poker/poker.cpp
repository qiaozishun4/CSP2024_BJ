#include<bits/stdc++.h>
using namespace std;
bool b[60];
int c(string str){
	int cnt;
	if(str[0]=='D') cnt=0;
	else if(str[0]=='C') cnt=13;
	else if(str[0]=='H') cnt=26;
	else if(str[0]=='S') cnt=39;
	if(str[1]>='2' && str[1]<='9') cnt+=str[1]-'1';
	else if(str[1]=='T') cnt+=9;
	else if(str[1]=='J') cnt+=10;
	else if(str[1]=='Q') cnt+=11;
	else if(str[1]=='K') cnt+=12;
	return cnt;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(b[c(s)]==0){
			b[c(s)]=1;
			sum++;
		}
	}
	cout<<52-sum;
	
	return 0;
}
