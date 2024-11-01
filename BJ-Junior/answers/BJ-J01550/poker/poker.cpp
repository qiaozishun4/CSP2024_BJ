#include<bits/stdc++.h>
using namespace std;
int a[14],b[14],c[14],d[14];
int f(char x){
	if(x>='2'&&x<='9'){
		return x-'0';
	}
	if(x=='T'){return 10;}
	if(x=='J'){return 11;}
	if(x=='Q'){return 12;}
	if(x=='K'){return 13;}
	return 1;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		char cf,cs;
		cin>>cf>>cs;
		if(cf=='D'){
			a[f(cs)]++;
			if(a[f(cs)]==1){ans++;}
		}
		if(cf=='C'){
			b[f(cs)]++;
			if(b[f(cs)]==1){ans++;}
		}
		if(cf=='H'){
			c[f(cs)]++;
			if(c[f(cs)]==1){ans++;}
		}
		if(cf=='S'){
			d[f(cs)]++;
			if(d[f(cs)]==1){ans++;}
		}
	}
	cout<<52-ans;
	return 0;
}
