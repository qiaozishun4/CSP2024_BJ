#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	bool is1[101];
	bool is2[101];
	bool is3[101];
	bool is4[101];
	cin>>n;
	int ans=52;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		int k;
		if('2'<=b&&b<='9'){
			k=b-48;
		}
		if(b=='A'){
			k=1;
		}
		if(b=='T'){
			k=10;
		}
		if(b=='J'){
			k=11;
		}
		if(b=='Q'){
			k=12;
		}
		if(b=='K'){
			k=13;
		}
		if(a=='D'){
			if(!is1[k]){
			is1[k]=true;
			ans--;
		}
		}
		if(a=='C'){
			if(!is2[k]){
			is2[k]=true;
			ans--;
		}
		}
		if(a=='H'){
			if(!is3[k]){
			is3[k]=true;
			ans--;
		}
		}
		if(a=='S'){
			if(!is4[k]){
			is4[k]=true;
			ans--;
		}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
