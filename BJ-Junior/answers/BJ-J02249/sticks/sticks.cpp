#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	int k[T+5];
	for(int i=1;i<=T;i++){	
		cin>>k[i];
	}
	for(int i=1;i<=T;i++){	
		if(k[i]%7==0){
			for(int j=1;j<=k[i]/7;j++){
				cout<<8;
			}
			cout<<endl;
		}
		else if(k[i]==1){
			cout<<-1<<endl;
		}
		else if(k[i]==2){
			cout<<1<<endl;
		}
		else if(k[i]==3){
			cout<<7<<endl;
		}
		else if(k[i]==4){
			cout<<4<<endl;
		}else if(k[i]==5){
			cout<<5<<endl;
		}
		else if(k[i]==6){
			cout<<6<<endl;
		}
		else if(k[i]==7){
			cout<<8<<endl;
		}
		else if(k[i]==8){
			cout<<10<<endl;
		}
		else if(k[i]==9){
			cout<<24<<endl;
		}else if(k[i]==10){
			cout<<22<<endl;
		}
		else if(k[i]==11){
			cout<<20<<endl;
		}
		else if(k[i]==12){
			cout<<66<<endl;
		}
		else if(k[i]==13){
			cout<<85<<endl;
		}
		else if(k[i]==14){
			cout<<88<<endl;
		}else if(k[i]==15){
			cout<<108<<endl;
		}
		else if(k[i]==16){
			cout<<188<<endl;
		}
		else if(k[i]==17){
			cout<<200<<endl;
		}
		else if(k[i]==18){
			cout<<208<<endl;
		}
		else if(k[i]==19){
			cout<<377<<endl;
		}
		else if(k[i]==20){
			cout<<1000<<endl;
		}
		else if(k[i]%7==1){
			cout<<1<<0;
			k[i]-=8;
			for(int j=1;j<=k[i]/8;j++){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}
