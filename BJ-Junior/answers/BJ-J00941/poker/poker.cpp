#include<bits/stdc++.h>
using namespace std;
int n,ant,x;
string s;
int p[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>s;
		if(s[0]=='C'){
			x=0;
		}else if(s[0]=='S'){
			x=1;
		}else if(s[0]=='H'){
			x=2;
		}else{
			x=3;
		}
		if(s[1]>='2'&&s[1]<='9'){
			p[x*13+s[1]-'0']=1;
		}else if(s[1]=='A'){
			p[x*13+1]=1;
		}else if(s[1]=='T'){
			p[x*13+10]=1;
		}else if(s[1]=='J'){
			p[x*13+11]=1;
		}else if(s[1]=='Q'){
			p[x*13+12]=1;
		}else if(s[1]=='K'){
			p[x*13+13]=1;
		}
	}
	for(int i=1;i<=52;i++){
		if(p[i]==0){
			ant++;
		}
	}
	cout<<ant;
	return 0;
}