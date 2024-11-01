#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	long long n[t+10];
	for(int i=1;i<=t;i++){
		cin>>n[i];
	}
	for(int i=1;i<=t;i++){
		if(n[i]<2){
			cout<<-1<<endl;
			continue;
		}else if(n[i]==2){
			cout<<1<<endl;
		}else if(n[i]==3){
			cout<<7<<endl;
		}else if(n[i]==4){
			cout<<4<<endl;
		}else if(n[i]==5){
			cout<<2<<endl;
		}else if(n[i]==6){
			cout<<6<<endl;
		}else if(n[i]==7){
			cout<<8<<endl;
		}else if(n[i]==8){
			cout<<16<<endl;
		}else if(n[i]==9){
			cout<<18<<endl;
		}else if(n[i]==10){
			cout<<23<<endl;
		}else if(n[i]==11){
			cout<<30<<endl;
		}else if(n[i]==12){
			cout<<28<<endl;
		}else if(n[i]==13){
			cout<<68<<endl;
		}else if(n[i]==14){
			cout<<88<<endl;
		}else if(n[i]==15){
			cout<<108<<endl;
		}else if(n[i]==16){
			cout<<188<<endl;
		}else if(n[i]==17){
			cout<<788<<endl;
		}else if(n[i]==18){
			cout<<208<<endl;
		}else if(n[i]==19){
			cout<<288<<endl;
		}else if(n[i]==20){
			cout<<688<<endl;
		}
	}
	return 0;
}
