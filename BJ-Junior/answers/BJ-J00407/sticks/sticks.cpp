#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=1){
			cout<<-1<<"\n";
		}else if(n%7==0){
			for(int i=1;i<=n/7;i++)cout<<"8";
			cout<<"\n";
		}
		else if((n-1)%7==0){
			cout<<"10";
			for(int i=1;i<(n-1)/7;i++)cout<<"8";
			cout<<"\n";
		}
		else if((n+1)%7==0){
			cout<<"6";
			for(int i=1;i<(n+1)/7;i++)cout<<"8";
			cout<<"\n";
		}else if(n<=50){
			if(n==2)cout<<1<<endl;
			if(n==3)cout<<7<<endl;
			if(n==4)cout<<4<<endl;
			if(n==5)cout<<2<<endl;
			if(n==6)cout<<6<<endl;
			if(n==7)cout<<8<<endl;
			if(n==8)cout<<10<<endl;
			if(n==9)cout<<18<<endl;
			if(n==10)cout<<22<<endl;
			if(n==11)cout<<20<<endl;
			if(n==12)cout<<28<<endl;
			if(n==13)cout<<68<<endl;
			if(n==14)cout<<88<<endl;
			if(n==15)cout<<108<<endl;
			if(n==16)cout<<188<<endl;
			if(n==17)cout<<408<<endl;
			if(n==18)cout<<208<<endl;
			if(n==19)cout<<288<<endl;
			if(n==20)cout<<688<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
