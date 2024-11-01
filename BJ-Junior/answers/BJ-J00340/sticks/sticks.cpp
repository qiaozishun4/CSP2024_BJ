#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[15]={6,2,5,-1,4,-1,6,3,7,-1};
int t[15];
void hm(int i){
	while(i>12){
		i-=7;
		t[8]++;
	}
	if(i>0){
		if(i==11){
			t[2]++;
			t[6]++;
		}
		if(i==10){
			t[2]+=2;
		}
		if(i==9){
			t[1]++;
			t[8]++;
		}
		if(i==8){
			t[1]++;
			t[6]++;
		}
		if(i==7){
			t[8]++;
		}
		if(i==6){
			t[6]++;
		}
		if(i==5){
			t[2]++;
		}
		if(i==4){
			t[4]++;
		}
		if(i==3){
			t[7]++;
		}
		if(i==2){
			t[1]++;
		}
	}
	return ;
}
bool check(){
	for(int i=1;i<=8;i++){
		if(t[i]>0) return 1;
	}
	return 0;
}
bool check6(){
	for(int i=1;i<=8;i++){
		if(i==3 || i==5) continue;
		else if(i!=6 && t[i]!=0) return 0;
		else if(i==6 && t[i]==0) return 0;
	}
	return 1;
}
void print(){
	bool is=0;
	if(check6()){
		cout<<6;
		t[6]--;
		while(t[6]>0){
			cout<<0;
			t[6]--;
		}
		cout<<endl;
		return ;
	}
	while(check()){
		while(t[6]>0 && is){
			cout<<0;
			t[6]--;
		}
		if(t[1]>0){
			cout<<1;
			t[1]--;
			is=1;
		}
		else if(t[2]>0){
			cout<<2;
			t[2]--;
			is=1;
		}
		else if(t[4]>0){
			cout<<4;
			t[4]--;
			is=1;
		}
		else if(t[6]>0){
			cout<<6;
			t[6]--;
			is=1;
		}
		else if(t[7]>0){
			cout<<7;
			t[7]--;
			is=1;
		}
		else if(t[8]>0){
			cout<<8;
			t[8]--;
			is=1;
		}
		
	}
	cout<<endl;
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int c=1;c<=T;c++){
		cin>>n;
		if(n<=1){
			cout<<"-1"<<endl;
			continue;
		}
		hm(n);
		print();
		memset(t,0,sizeof(t));
	}
	return 0;
}