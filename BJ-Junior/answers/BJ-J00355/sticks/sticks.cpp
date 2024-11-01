#include<bits/stdc++.h>
using namespace std;
string l[100004]={"-1","1","7","4","2","6","8","10","18","22","20","28","68","88","108","188","228","208","288","688"};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x;
		for(int i=20;i<x;i++){
		if(l[i-1][0]=='1'){
			if(l[i-1][1]=='8'){
				l[i]="2"+l[i-5];
			}else{
				l[i]="1"+l[i-2];
			}
		}
		if(l[i-1][0]=='2'){
			if(l[i-1][1]=='8'){
				l[i]="6"+l[i-6];
			}else{
				l[i]="2"+l[i-5];
				if(l[i-5][0]=='6')
				l[i][1]='0';
			}
		}
		if(l[i-1][0]=='6'){
			if(l[i-1][1]=='8'){
				l[i]="8"+l[i-7];
			}else{
				l[i]="6"+l[i-6];
			}
		}
		if(l[i-1][0]=='8'){
			if(l[i-1][1]=='8'){
				l[i]="1"+l[i-2];
				if(l[i-2][0]=='6')
				l[i][1]='0';
			}else{
				l[i]="8"+l[i-7];
			}
		}
	}
		cin>>x;
		cout<<l[x-1]<<endl;
	}
	
	
	
return 0;
}
