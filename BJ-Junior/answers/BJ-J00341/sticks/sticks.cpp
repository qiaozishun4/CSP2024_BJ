#include<bits/stdc++.h>
using namespace std;
int t;
string stick[8]={"888","108","188","200","208","288","688","888"};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int weishu=n/7;
        if(n%7!=0) weishu++;
        //cout<<weishu<<endl;
        //cout<<t<<' '<<n<<endl;
        if(n<=14){
            if(n==1) cout<<-1<<endl;
            else if(n==2) cout<<1<<endl;
            else if(n==3) cout<<7<<endl;
            else if(n==4) cout<<4<<endl;
            else if(n==5) cout<<2<<endl;
            else if(n==6) cout<<6<<endl;
            else if(n==7) cout<<8<<endl;
            else if(n==8) cout<<10<<endl;
            else if(n==9) cout<<18<<endl;
            else if(n==10) cout<<22<<endl;
            else if(n==11) cout<<20<<endl;
            else if(n==12) cout<<28<<endl;
            else if(n==13) cout<<68<<endl;
            else if(n==14) cout<<88<<endl;
        }else{
            string ans=stick[n%7];
            cout<<ans;
            for(int i=0;i<weishu-3;i++) cout<<8;
            cout<<endl;
        }
    }
    return 0;
}
