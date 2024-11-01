#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	preopen("detect.in","i",stdin)
	preopen("detect.out","u",stdout)
	cin>>T;
	int n,m,L,V;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		int di,ui,ai;
		cin>>di>>ui>>ai;
	}
	for(int p=1;p<=m;p++){
		cin>>p;
	}
	if(ui>0){ 
		if(ai<0){
			break;
		}
	}
	if(ui>V){
		int a=0;
		a=a+1;
	}
	int b=m-a;
	cout<<a;
	cout<<b
	retuen 0;
}