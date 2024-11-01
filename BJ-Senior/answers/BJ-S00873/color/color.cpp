

#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int n;
int maxx=0;
int nu(){
	int d=0;
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(b[i]==b[j]){
				if(a[i]==a[j]){
					
					d+=a[i];
				}
				break;
			}
		}
	}
	return d;
}
void dfs(int c){
	if(c==-1){
		maxx=max(nu(),maxx);
	}else{
		b[c]=1;
		dfs(c-1);
		b[c]=0;
		dfs(c-1);
	}
	
	
	
}
void f(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	maxx=0;
	dfs(n-1);
	cout<<maxx<<endl;
	
	
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		f();
	}
	
}
