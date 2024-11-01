#include<bits/stdc++.h>
using namespace std;
int h[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	string s;
	cin>>T;
	while(T--){
		cin>>n;
		s="";
		int t=max(0,n/7-1),tmp;
		for(int i=1;i<=t;i++) s='8'+s;
		n-=7*t;
		for(int i=1;i<=9;i++){
			if(n<=7 && h[i]==n){
				s=char(i+'0')+s;
				break;
			}
			if(n>7 && n-7<=h[i]){
				tmp=i;
				break;
			}
		}
		if(n>7){
			n-=h[tmp];
			for(int i=0;i<=9;i++){
				if(h[i]==n){
					s=char(i+'0')+s;
					s=char(tmp+'0')+s;
					break;
				}
			}
		}
		if(s=="") cout<<-1<<"\n";
		else cout<<s<<"\n";
	}
	return 0;
}