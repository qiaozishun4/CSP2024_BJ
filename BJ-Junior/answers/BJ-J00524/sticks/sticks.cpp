#include <bits/stdc++.h>
using namespace std;
int n,t;
string s;
int vis[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=13){
			cout<<vis[n]<<endl;
			continue;
		}else{
			if(n%7==0){
				s="";
				for(int i=1;i<=(n/7);i++){
					s+='8';
				}
				cout<<s<<endl;
			}else{
				s="";
				for(int i=1;i<=(n/7-1);i++){
					s+='8';
				}
				cout<<vis[n%7+7]<<s<<endl;
			}
		}
	}
	return 0;
}
