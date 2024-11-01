#include<bits/stdc++.h>
using namespace std;

freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);

int main(){
    int t,k,n;
    cin>>t;
    for(int i=0;i<t;i++){
		cin>>n;
		k=n;
		if(n<7){
			if(n<=1) cout<<"-1"<<endl;
			if(n==2) cout<<"1"<<endl;
			if(n==3) cout<<"7"<<endl;
			if(n==4) cout<<"4"<<endl;
			if(n==5) cout<<"2"<<endl;
			if(n==6) cout<<"6"<<endl;
		}
		if(n>=7){
			if(n==10) cout<<"22"<<endl;
			if(n%7==0){
				k/=7;
				for(int j=0;j<k;j++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(n%7==1){
				cout<<"10";
				k/=7;
				k--;
				for(int j=0;j<k;j++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(n%7==2){
				cout<<"1";
				k/=7;
				for(int j=0;j<k;j++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(n%7==3&&n!=10){
				cout<<"200";
				k/=7;
				k-=2;
				for(int j=0;j<k;j++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(n%7==4){
				cout<<"20";
				k/=7;
				k-=1;
				for(int j=0;j<k;j++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(n%7==5){
				cout<<"2";
				k/=7;
				for(int j=0;j<k;j++){
					cout<<"8";
				}
				cout<<endl;
			}
			if(n%7==6){
				cout<<"6";
				k/=7;
				for(int j=0;j<k;j++){
					cout<<"8";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
