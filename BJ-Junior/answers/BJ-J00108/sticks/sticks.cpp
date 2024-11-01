#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		string cur="";
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==1){
			cur+="10";
			n-=8;
		}else if(n%7==2){
			cur+="1";
			n-=2;
		}else if(n%7==3){
			if(n==3){
				cur+="7";
				n-=3;
			}else if(n==10){
				cur+="22";
				n-=10;
			}else{
				cur+="200";
				n-=17;
			}
		}else if(n%7==4){
			if(n==4){
				cur+="4";
				n-=4;
			}else{
				cur+="20";
				n-=11;
			}
		}else if(n%7==5){
			cur+="2";
			n-=5;
		}else if(n%7==6){
			cur+="6";
			n-=6;
		}
		while(n){
			cur+="8";
			n-=7;
		}
		cout<<cur<<endl;
	}
}