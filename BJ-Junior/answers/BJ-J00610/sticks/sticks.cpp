#include <bits/stdc++.h>
using namespace std;
int t,n,a[20];
string ans[30];
void dfs(string x,int p){
	if(p>20) return ;
	if(ans[p].size()>x.size()) ans[p]=x;
	else if(ans[p].size()==x.size()) ans[p]=min(ans[p],x);
	for(int i=0;i<=9;i++){
		if(x=="" && i==0) continue;
		string s=x;
		s+=char(i+48);
		dfs(s,p+a[i]);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=0;i<=20;i++){
		ans[i]="999999999";
	}
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    dfs("",0);
    cin>>t;
    while(t--){
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
		if(ans[n]=="999999999") cout<<-1;
		else cout<<ans[n];
		cout<<"\n";
	}
    return 0;
}
