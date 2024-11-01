#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	bool cmp[57]={};
	int n;
	char a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int num=0;
		if(a=='C')	num=13;
		if(a=='H')	num=26;
		if(a=='S')	num=39;
		if(b=='T')	num+=9;
		else if(b=='J')	num+=10;
		else if(b=='Q')	num+=11;
		else if(b=='K')	num+=12;
		else if(b!='A')	num+=b-'0'-1;
		cmp[num]=true;
	}
	int cnt=0;
	for(int i=0;i<52;i++){
		if(!cmp[i]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

