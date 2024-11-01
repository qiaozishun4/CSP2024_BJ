#include<bits/stdc++.h>
using namespace std;
bool a[15];
bool b[15];
bool c[15];
bool d[15];
int find(char z){
	if(z=='A'){
		return 1;
	}
	else if(z=='T'){
		return 10;
	}
	else if(z=='J'){
		return 11;
	}
	else if(z=='Q'){
		return 12;
	}
	else if(z=='K'){
		return 13;
	}
	else{
		return z-'0';
	}
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char x,y;
		cin>>x>>y;
		if(x=='D'){
			a[find(y)]=1;
		}
		else if(x=='C'){
			b[find(y)]=1;
		}
		else if(x=='H'){
			c[find(y)]=1;
		}
		else{
			d[find(y)]=1;
		}
	}
	for(int i=1;i<=13;i++){
		if(!a[i]){
			ans++;
		}
		if(!b[i]){
			ans++;
		}
		if(!c[i]){
			ans++;
		}
		if(!d[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}