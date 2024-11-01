#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    int n;
    cin>>n;
    if(n<=20&&n>1){
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
        if(n==7){
            cout<<8;
        }
        if(n==8){
            cout<<16;
        }
        if(n==9){
            cout<<18;
        }
        if(n==10){
            cout<<22;
        }
        if(n==11){
            cout<<20;
        }
        if(n==12){
            cout<<27;
        }
        if(n==13){
            cout<<48;
        }
        if(n==14){
            cout<<88;
        }
        if(n==15){
            cout<<108;
}
        if(n==16){
            cout<<188;
        }
        if(n==17){
            cout<<200;
        }
    	if(n==18){
            cout<<208;
        }
        if(n==19){
            cout<<288;
        }
        if(n==20){
            cout<<808;
	}
cout<<endl;
	continue;
    }


    if(n<=1){
    cout<<-1<<endl;
    continue;
    }
     	if(n%7==0){
	while(n){
cout<<8;
n-=7;
        }

    }else if(n%7==1){
    cout<<10;
    while(n-8>=7){
        cout<<8;
        n-=7;
    }

    }
cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
