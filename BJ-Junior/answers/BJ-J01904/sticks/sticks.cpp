#include<bits/stdc++.h>
using namespace std;
int n;
void coutn(int n){
	n/=7;
	for(int i=0; i<n; i++){
		cout<<8;
	}
	cout<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int u;
    cin>>u;
    for(int uu=0; uu<u; uu++){
		cin>>n;
		int t=n%7;
		if(t==0){
			coutn(n);
		}
		else if(t==1){
			if(n==1){
				cout<<-1<<endl;
				continue;
			}
			cout<<10;
			coutn(n-8);
		}
		else if(t==2){
			cout<<1;
			coutn(n-2);
		}
		else if(t==3){
			if(n==3){
				cout<<7<<endl;
				continue;
			}
			if(n==10){
				cout<<22<<endl;
				continue;
			}
			cout<<206;
			coutn(n-17);
		}
		else if(t==4){
			if(n==4){
				cout<<4<<endl;
				continue;
			}
			cout<<20;
			coutn(n-11);
		}
		else if(t==5){
			cout<<2;
			coutn(n-5);
		}
		else{
			cout<<6;
			coutn(n-6);
		}
	}
    return 0;
}

