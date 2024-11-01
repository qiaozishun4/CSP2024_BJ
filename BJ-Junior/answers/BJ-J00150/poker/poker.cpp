#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
map<string,bool> mp;
string a1[5]={" ","D","C","H","S"};
string a2[14]={" ","A","2","3","4","5","6","7","8","9","T","J","Q","K"};
string p[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	int n,p1=1;
	cin>>n;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			p[p1++]=a1[i]+a2[j];
		}
	}
	for(int i=0;i<n;i++){
		string st;
		cin>>st;
		mp[st]=1;
	}
	int sum=52;
	for(int i=1;i<p1;i++){
		if(mp[p[i]]) sum--;
	}
	cout<<sum;
	return 0;
}
