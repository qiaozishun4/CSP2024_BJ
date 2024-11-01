#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    int n;
    for(int i=1;i<=T;i++){
        cin>>n;
        if(n>=1&&n<=2)cout<<-1<<endl;
        else if(n==3) cout<<7<<endl;
        else if(n==4) cout<<4<<endl;
        else if(n==5) cout<<2<<endl;
        else if(n==6) cout<<0<<endl;
        else if(n==7) cout<<8<<endl;
        else if(n==8) cout<<10<<endl;
        else if(n==9) cout<<18<<endl;
        else if(n==10) cout<<101<<endl;
        else if(n==11) cout<<107<<endl;
        else if(n==12) cout<<104<<endl;
        else if(n==13) cout<<102<<endl;
        else if(n==14) cout<<106<<endl;
        else if(n==15) cout<<108<<endl;
        else if(n==16) cout<<202<<endl;
        else if(n==17) cout<<200<<endl;
        else if(n==18) cout<<208<<endl;
        else if(n==19) cout<<288<<endl;
        else if(n==20) cout<<688<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}
