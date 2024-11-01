#include<bits/stdc++.h>
using namespace std;
int t;
string f[100001];
int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int st[10]={ 1,1,1,0,1,0,0,1,1,0};
string minn(string s1,string s2){
	if(s2=="A")return s1;
	if(s1=="A")return s2;
	if(s1.size()<s2.size())return s1;
	if(s1.size()>s2.size())return s2;
	int l=0;
	long long si=s1.size();
	while(l<si){
		if(s1[l]<s2[l])return s1;
		if(s1[l]>s2[l])return s2;
		l++;
	}
	return s1;
}
int main(){
	cin>>t;
	f[0]="";
	for(int i=1;i<=1001;i++){
		f[i]='A';
		for(int j=0;j<10;j++){
			char x=j+'0';
			if(i<cnt[j]||f[i-cnt[j]]=="A")continue;
			if(!st[j]&&(i!=6))continue;
			if(j==9)continue;
			if(i==cnt[j]){
				if(j!=0)f[i]=x;
			}
			else{
				f[i]=minn(f[i],f[i-cnt[j]]+x);
			}
		}
	}
	while(t--){
		int n;
		cin>>n;
		if(n%7==0&&n>=7){
			int cnt=n/7;
			for(int i=1;i<=cnt;i++)cout<<8;
		}
		else if(n%7==1&&n>=8){
			int cnt=(n-1)/7-1;
			cout<<1<<0;
			for(int i=1;i<=cnt;i++)cout<<8;
		}
		else if(f[n]!="A")cout<<f[n];
		else cout<<-1;
		cout<<endl;
	}
	return 0;
}
