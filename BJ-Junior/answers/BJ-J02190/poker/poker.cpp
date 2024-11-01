#include<bits/stdc++.h>
using namespace std;
long long num1=52,b[53];
int main(){
	freopen("joker.in","r",stdin);
	freopen("joker.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		if(a[0]=='D'){
			if(a[1]=='T'){
				b[10]=1;
			}else if(a[1]=='J'){
				b[11]=1;
			}else if(a[1]=='Q'){
				b[12]=1;
			}else if(a[1]=='K'){
				b[13]=1;
			}else if(a[1]=='A'){
				b[1]=1;
			}else{
				b[a[1]-'0']=1;
			}
		}else if(a[0]=='C'){
			if(a[1]=='T'){
				b[23]=1;
			}else if(a[1]=='J'){
				b[24]=1;
			}else if(a[1]=='Q'){
				b[25]=1;
			}else if(a[1]=='K'){
				b[26]=1;
			}else if(a[1]=='A'){
				b[14]=1;
			}else{
				b[a[1]-'0'+13]=1;
			}
		}else if(a[0]=='H'){
			if(a[1]=='T'){
				b[36]=1;
			}else if(a[1]=='J'){
				b[37]=1;
			}else if(a[1]=='Q'){
				b[38]=1;
			}else if(a[1]=='K'){
				b[39]=1;
			}else if(a[1]=='A'){
				b[27]=1;
			}else{
				b[a[1]-'0'+26]=1;
			}
		}else if(a[0]=='S'){
			if(a[1]=='T'){
				b[49]=1;
			}else if(a[1]=='J'){
				b[50]=1;
			}else if(a[1]=='Q'){
				b[51]=1;
			}else if(a[1]=='K'){
				b[52]=1;
			}else if(a[1]=='A'){
				b[40]=1;
			}else{
				b[a[1]-'0'+39]=1;
			}
		}
	}	
	for(int i=1;i<=52;i++){
		if(b[i]==1){
			num1--;
		}
	}
	cout<<num1;
	return 0;
}
