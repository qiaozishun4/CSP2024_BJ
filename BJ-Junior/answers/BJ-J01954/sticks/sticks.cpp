#include<bits/stdc++.h>
using namespace std;

int ansx=0;
int T;
int n;
int m;
int v[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		m=n/7;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==2){
			cout<<1<<endl;
			continue;
		}
		if(n==3){
			cout<<7<<endl;
			continue;
		}
		if(n==4){
			cout<<4<<endl;
			continue;
		}
		if(n==5){
			cout<<2<<endl;
			continue;
		}
		if(n==6){
			cout<<6<<endl;
			continue;
		}
		if(n==7){
			cout<<8<<endl;
			continue;
		}
		if(n==8){
			cout<<10<<endl;
			continue;
		}
		if(n==9){
			cout<<18<<endl;
			continue;
		}
		if(n==10){
			cout<<22<<endl;
			continue;
		}
		if(n==11){
			cout<<20<<endl;
			continue;
		}
		if(n==12){
			cout<<28<<endl;
			continue;
		}
		if(n==13){
			cout<<68<<endl;
			continue;
		}
		if(n==14){
			cout<<88<<endl;
			continue;
		}
		if(n==15){
			cout<<108<<endl;
			continue;
		}
		if(n==16){
			cout<<188<<endl;
			continue;
		}
		if(n==17){
			cout<<200<<endl;
			continue;
		}
		if(n==18){
			cout<<208<<endl;
			continue;
		}
		if(n==19){
			cout<<288<<endl;
			continue;
		}
		if(n==20){
			cout<<688<<endl;
			continue;
		}
		if(n==23){
			cout<<1888<<endl;
			continue;
		}
		n%=7;
		if(n==2){
			cout<<1;
		}
		if(n==3){
			cout<<7;
		}
		if(n==4){
			cout<<4;
		}
		if(n==5){
			cout<<2;
		}
		if(n==6){
			cout<<6;
		}
		
		if(n==1){
			cout<<10;
			m-=1;
		}
		for(int i=1;i<=m;i++){
			cout<<8;
		}
		cout<<endl;
	}

	fclose(stdin);
	fclose(stdout);//rp++
	return 0;
}
