#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin.tie(0);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
if(n<=1){
cout<<"-1\n";
continue;
}
if(n==2){
cout<<"1\n";
continue;
}
if(n==3){
cout<<"7\n";
continue;
}
if(n==4){
cout<<"4\n";
continue;
}
if(n==5){
cout<<"2\n";
continue;
}
if(n==6){
cout<<"6\n";
continue;
}
int k=n/7;
int p=n%7;
if(p==0){
	string ss;
	for(int i=0;i<k;i++){
		ss.push_back('8');
	}
	cout<<ss<<"\n";
	}
else if(p==1){
	string ss;
	ss.push_back('1');
	ss.push_back('0');
	for(int i=2;i<=k;i++){
		ss.push_back('8');
	}
	cout<<ss<<"\n";
}
else if(p==2){
	string ss;
	ss.push_back('1');
	for(int i=1;i<=k;i++){
		ss.push_back('8');
	}
	cout<<ss<<"\n";
}
else if(p==3){
	string ss;
	ss.push_back('2');
	ss.push_back('2');
	for(int i=1;i<=k-1;i++){
		ss.push_back('8');
	}
	cout<<ss<<"\n";
}
else if(p==4){
	string ss;
	ss.push_back('2');
	ss.push_back('0');
	for(int i=1;i<=k-1;i++){
		ss.push_back('8');
	}
	cout<<ss<<"\n";
}
else if(p==5){
	string ss;
	ss.push_back('2');
	for(int i=1;i<=k;i++){
		ss.push_back('8');
	}
	cout<<ss<<"\n";
}
else if(p==6){
	string ss;
	ss.push_back('6');
	for(int i=1;i<=k;i++){
		ss.push_back('8');
	}
	cout<<ss<<"\n";
}
}
fclose(stdin);
fclose(stdout);
return 0;
}