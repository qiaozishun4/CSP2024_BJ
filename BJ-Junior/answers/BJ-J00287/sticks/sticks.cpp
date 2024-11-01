#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[20]={0,-1,1,7,4,2,6};
void solve0(int x){
	int k=x/7;
	for(int i=1;i<=k;i++) cout<<8;
	cout<<"\n";
}
void solve1(int x){
	int k=x/7;
	cout<<"10";
	for(int i=1;i<k;i++) cout<<8;
	cout<<"\n";
}
void solve2(int x){
	int k=x/7;
	cout<<"18";
	for(int i=1;i<k;i++) cout<<8;
	cout<<"\n";
}
void solve3(int x){
	int k=x/7;
	cout<<"22";
	for(int i=1;i<k;i++) cout<<8;
	cout<<"\n";
}
void solve4(int x){
	int k=x/7;
	cout<<"20";
	for(int i=1;i<k;i++) cout<<8;
	cout<<"\n";
}
void solve5(int x){
	int k=x/7;
	cout<<"28";
	for(int i=1;i<k;i++) cout<<8;
	cout<<"\n";
}
void solve6(int x){
	int k=x/7;
	cout<<"68";
	for(int i=1;i<k;i++) cout<<8;
	cout<<"\n";
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<7){
			cout<<a[n]<<"\n";
		}
		else if(n%7==0) solve0(n);
		else if(n%7==1) solve1(n);
		else if(n%7==2) solve2(n);
		else if(n%7==3) solve3(n);
		else if(n%7==4) solve4(n);
		else if(n%7==5) solve5(n);
		else if(n%7==6) solve6(n);
	}
	return 0;
}
