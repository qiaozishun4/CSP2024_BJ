#include <bits/stdc++.h>
#define _for(i,x,y) for(int i=x; i<=y; i++)
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int T;
    cin>>T;
    while(T--){
        ll n,cnt=0,w=0;
        cin>>n;
        cnt=cnt+n/7ll;
        n=n%7ll;
        w=cnt+(n>0)?1:0;
        if(n==0){
            _for(i,1,cnt) cout<<8;
            cout<<endl;
            continue;
            //------------------------------
        }
        if(cnt==0){
            if(n==1) cout<<-1<<endl;
            if(n==2) cout<<1<<endl;
            if(n==3) cout<<7<<endl;
            if(n==4) cout<<4<<endl;
            if(n==5) cout<<2<<endl;
            if(n==6) cout<<6<<endl;
            continue;
            //---------------------------
        }
        if(n==1){
            cout<<1<<0;
            _for(i,1,cnt-1) cout<<8;
            cout<<endl;
            continue;
            //------------
        }
        if(n==2){
            cout<<1;
            _for(i,1,cnt) cout<<8;
            cout<<endl;
            continue;
            //--------------

        }
        if(n==3){
            cout<<2<<2;
            _for(i,1,cnt-1) cout<<8;
            cout<<endl;
            continue;
            //--------------

        }
        if(n==4){
            cout<<2<<0;
            _for(i,1,cnt-1) cout<<8;
            cout<<endl;
            return 0;
            //--------------

        }
        if(n==5){
            cout<<2;
            _for(i,1,cnt) cout<<8;
            cout<<endl;
            continue;
            //--------------

        }
        if(n==6){
            cout<<6;
            _for(i,1,cnt) cout<<8;
            cout<<endl;
            continue;
            //--------------

        }
    }

    return 0;
}
