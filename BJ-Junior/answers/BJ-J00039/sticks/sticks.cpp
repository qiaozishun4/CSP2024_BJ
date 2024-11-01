#include<iostream>
using namespace std;

long long ans[55];
int main(){
	int T;
	cin>>T;
	int n;
	for(int a=1;a<=T;a++){
		cin>>n;
		if(n<7){
			if(n==1){ans[a]=-1;}
			else if(n==2){ans[a]=1;}
			else if(n==3){ans[a]=7;}
			else if(n==4){ans[a]=4;}
			else if(n==5){ans[a]=2;}
			else if(n==6){ans[a]=6;}
		}
		else if(n>=7){
			if(n%7==0){
				ans[a]=8;
				for(int i=1;i<=(n/7-1);i++){
					ans[a]=ans[a]*10+8;
				}
			}
			else if(n%7==1){
				ans[a]=10;
				for(int i=1;i<=(n/7-1);i++){
					ans[a]=ans[a]*10+8;
				}
			}
			else if(n%7==2){
				ans[a]=18;
				for(int i=1;i<=(n/7-1);i++){
					ans[a]=ans[a]*10+8;
				}
			}
			else if(n%7==3){
				ans[a]=22;
				for(int i=1;i<=(n/7-1);i++){
					ans[a]=ans[a]*10+8;
				}
			}
			else if(n%7==4){
				ans[a]=20;
				for(int i=1;i<=(n/7-1);i++){
					ans[a]=ans[a]*10+8;
				}
			}
			else if(n%7==5){
				ans[a]=28;
				for(int i=1;i<=(n/7-1);i++){
					ans[a]=ans[a]*10+8;
				}
			}
			else if(n%7==6){
				ans[a]=68;
				for(int i=1;i<=(n/7-1);i++){
					ans[a]=ans[a]*10+8;
				}
			}
		}
	}
	for(int i=1;i<=T;i++){cout<<ans[i];}
	return 0;
}