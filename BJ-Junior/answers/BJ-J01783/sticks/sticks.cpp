#include<bits/stdc++.h>
using namespace std;
string r,c[10]={"0","1","2","3","4","5","6","7","8","9"};
int u=0,t,w,m[10]={6,2,5,5,4,5,6,3,7,6};
void p(int n,string ans,int s){
	if(n<0||s>w/2)return;
	if(n==0){
		if(!u){
			r=ans;
			u++;
		}else{
			if(r.size()>ans.size())r=ans;
			else if(ans.size()>r.size())return;
			else{
				bool flag=true;
				for(int i=0;i<r.size();i++){
					if(r[i]<ans[i])flag=false;
				}
				if(flag)r=ans;
			}
			return;
		}
	}
	if(s){
		p(n-6,ans+"0",s+1);
	}
	for(int i=1;i<10;i++){
		p(n-m[i],ans+c[i],s+1);
	}
} 
int main(){
cin>>t;
while(t--){
	cin>>w;
	if(w%7==0){
		for(int i=0;i<w/7;i++)cout<<'8';
		cout<<endl;
		continue;
	}else if(w%7==1&&w!=1){
		for(int i=0;i<(w-8)/7;i++)cout<<'8';
		cout<<"01\n";
		continue;
	}
	r="999999999999999999999999";
	p(w,"",0);
	if(r=="999999999999999999999999")cout<<"-1\n";
	else cout<<r<<endl;
}
	return 0;
}