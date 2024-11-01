#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
string f[N];
int stk[10]={6,2,5,5,4,5,6,3,7,6};
bool cmp(string a,string b){
	if(a.size()==b.size()){
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]) return a[i]<b[i];
		}
		return a[0]<b[0];
	}
	return a.size()<b.size();
}
void solve(){;
	cin>>n;
	for(int i=1;i<=n;i++){
		f[i]="-1";
	}
	f[2]="1";
	f[3]="7";
	f[4]="4";
	f[5]="2";
	f[6]="6";
	f[7]="8";
	for(int i=8;i<=20;i++){
		for(int j=0;j<10;j++){
			if(f[i-stk[j]]=="-1") continue;
			string t=f[i-stk[j]];
			t+=(j+'0');
			if(f[i]=="-1") f[i]=t;
			else if(cmp(t,f[i])) f[i]=t;
		}
	}
	string t="";
	if(n>20){
		int md=n%7;
		if(md!=0){
			t=f[14+md];
			n-=(14+md);
		}
		for(int i=1;i<=n/7;i++){
			t+='8';
		}
		f[n]=t;
	}
	
	
	cout<<f[n]<<endl;
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
