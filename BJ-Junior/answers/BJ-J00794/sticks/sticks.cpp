#include<bits/stdc++.h>
using namespace std;

int numb[11]={6,2,5,5,4,5,6,3,7,6};
long long numberm[16889],t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(unsigned long long i=1;i<=17000;i++){
        numberm[i]=0x3f3f;
	}
	for(long long i=10;i<=16888;i++){
        long long s=i,sum=0;
        while(s!=0){
            sum+=numb[s%10];
            s/=10;
        }
        numberm[sum]=min(i,numberm[sum]);
	}
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
        }
        else if(n==2){
            cout<<1<<endl;
        }
        else if(n==3){
            cout<<7<<endl;
        }
        else if(n==4){
            cout<<4<<endl;
        }
        else if(n==5){
            cout<<5<<endl;
        }
        else if(n==6){
            cout<<6<<endl;
        }
        else if(n==7){
            cout<<8<<endl;
        }
        else if(numberm[n]==0x3f3f){
            cout<<"-1"<<endl;
        }
        else {
            cout<<numberm[n]<<endl;
        }
    }

	return 0;
}
