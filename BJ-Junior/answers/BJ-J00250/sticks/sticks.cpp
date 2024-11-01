#include<bits/stdc++.h>
using namespace std;
int t,n;
void fun(int n){
	while(n!=0){
		cout<<"8";
		n-=7;
	}
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			fun(n);
		}else if(n%7==1){
			if(n>=8){
				cout<<"16";
				fun(n-8);
			}else{
				cout<<"-1";
			}
		}else if(n%7==2){
			cout<<"1";
			fun(n-2);
		}else if(n%7==3){
			if(n>=10){
				cout<<"22";
				fun(n-10);
			}else{
				cout<<"7";
			}
		}else if(n%7==4){
			if(n>=11){
				cout<<"20";
				fun(n-11);
			}else{
				cout<<"4";
			}
		}else if(n%7==5){
			cout<<"2";
			fun(n-5);
		}else if(n%7==6){
			cout<<"6";
			fun(n-6);
		}
		cout<<endl;
	}
	return 0;
}
/*
-1
1
7
6
208
*/
//想要
