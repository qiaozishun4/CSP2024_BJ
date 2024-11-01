#include<bits/stdc++.h>
using namespace std;
int poker[5][14],SUM=52;
void number(int k,char o){
	if(o<='9'){
		poker[k][o-'0']++;
		if(poker[k][o-'0']==1) SUM--;
		return ;
	}
	if(o=='A') {poker[k][1]++; if(poker[k][1]==1) SUM--;}
	if(o=='T') {poker[k][10]++; if(poker[k][10]==1) SUM--;}
	if(o=='J') {poker[k][11]++; if(poker[k][11]==1) SUM--;}
	if(o=='Q') {poker[k][12]++; if(poker[k][12]==1) SUM--;}
	if(o=='K') {poker[k][13]++; if(poker[k][13]==1) SUM--;}
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		string k;
		cin>>k;
		if(k[0]=='C')
			number(1,k[1]);
		else if(k[0]=='H')
			number(2,k[1]);
		else if(k[0]=='S')
			number(3,k[1]);
		else if(k[0]=='D')
			number(4,k[1]);
	}
	cout<<SUM;
	return 0;
}
