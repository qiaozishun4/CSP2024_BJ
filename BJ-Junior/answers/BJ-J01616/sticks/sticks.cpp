//passwd:GL@17SXYZ
//PDF:Y#C*GF@24
//LUCK COMES TO ME
//SITCKS
//CHECK:
//long long
//freopen
//return 0

#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
bool all_break=0;
queue<int>q;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        //打表开始
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
        else if(n==11) cout<<26<<endl;
        else if(n==12) cout<<28<<endl;
        else if(n==13) cout<<68<<endl;
        else if(n==14) cout<<88<<endl;
        else if(n==15) cout<<108<<endl;
        else if(n==16) cout<<188<<endl;
        else if(n==17) cout<<200<<endl;
        else if(n==18) cout<<208<<endl;
        else if(n==19) cout<<288<<endl;
        else if(n==20) cout<<688<<endl;
        else if(n%7==0) {
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if((n-1)%7==0){
            int tmp=(n-1)/7-1;
            cout<<10;
            for(int i=1;i<=tmp;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else{//碰运气 因为是错的
            int tmp=n/7+1;
            for(int i=0;i<tmp;i++){
                if(all_break) break;
                int cnt=2;
                while(1){
                    if(n-cnt<=7*(tmp-i)){
                        break;
                    }
                    else cnt++;
                    if(cnt>=10){
                        all_break=1;
                        cout<<-1<<endl;
                        break;
                    }
                }
                int check=0;
                if(q.empty()) check=1;
                for(int i=check;i<=9;i++){
                    if(a[i]==cnt) {
                        q.push(a[i]);
                        break;
                    }
                }
            }
            for(int i=1;i<=tmp;i++){
                int x1=q.front();
                q.pop();
                cout<<x1;
            }
            cout<<endl;
        }
    }

    return 0;
}
