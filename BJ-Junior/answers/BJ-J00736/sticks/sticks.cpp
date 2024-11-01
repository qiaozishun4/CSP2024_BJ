#include <bits/stdc++.h>
using namespace std;
int t,n;
string ans[105];
int main(){
    memset(ans,"",sizeof(ans));
	cin>>t;
	for(int z=1;z<=t;z++){
		cin>>n;
		if(n<7){
            if(n==1){
                ans[z]="-1";
                continue;
            }else if(n==2){
                ans[z]="1";
                continue;
            }else if(n==3){
                ans[z]="7";
                continue;
            }else if(n==4){
                ans[z]="4";
                continue;
            }else if(n==5){
                ans[z]="2";
                continue;
            }else if(n==6){
                ans[z]="6";
                continue;
            }
		}else if(n%7==0){
            for(int i=1;i<=n/7) ans[z]+="8";
            continue;
		}else if(n%7==1){
		    ans[z]="10";
            for(int i=1;i<=(n-8)/7) ans[z]+="8";
            continue;
		}else if(n%7==2){
		    ans[z]="1";
            for(int i=1;i<=(n-2)/7) ans[z]+="8";
            continue;
		}else if(n%7==3){
		    ans[z]="7";
            for(int i=1;i<=(n-3)/7) ans[z]+="8";
            continue;
		}else if(n%7==4){
		    ans[z]="20";
            for(int i=1;i<=(n-11)/7) ans[z]+="8";
            continue;
		}else if(n%7==5){
		    ans[z]="2";
            for(int i=1;i<=(n-5)/7) ans[z]+="8";
            continue;
		}else if(n%7==6){
		    ans[z]="6";
            for(int i=1;i<=(n-2)/7) ans[z]+="8";
            continue;
		}
	}
	for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
	return 0;
}
