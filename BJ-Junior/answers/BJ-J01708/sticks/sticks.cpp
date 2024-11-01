#include<bits/stdc++.h>
using namespace std;
int shuz[15]={6,2,5,5,4,5,6,3,7,6};
int n,t;
long long sum;
void dfs(int cnt){
    n=n-2-6*(cnt-1);
    if(n==0){
        cout<<1;
        cnt=cnt-1;
        while(cnt--){
            cout<<0;
        }
        cout<<endl;
    }
    else{
        if(n<cnt-1){
            cout<<1;
            cnt=cnt-1;
            while(cnt>n){
                cout<<0;
                cnt--;
            }
            while(n--){
                cout<<8;
            }
        }
        else{
            if(n-3<cnt-1){
                cout<<2;
                n=n-3;
                cnt=cnt-1;
                while(cnt>n){
                    cout<<0;
                    cnt--;
                }
                while(n--){
                    cout<<8;
                }
            }
            else if(n-4<cnt-1){
                cout<<6;
                n=n-4;
                cnt=cnt-1;
                while(cnt>n){
                    cout<<0;
                    cnt--;
                }
                while(n--){
                    cout<<8;
                }
            }
            else if(n-5<cnt-1){
                cout<<8;
                n=n-5;
                cnt=cnt-1;
                while(cnt>n){
                    cout<<0;
                    cnt--;
                }
                while(n--){
                    cout<<8;
                }
            }
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==2){
            cout<<1<<endl;
            continue;
        }
        if(n==3){
            cout<<7<<endl;
            continue;
        }
        if(n==4){
            cout<<4<<endl;
            continue;
        }
        if(n==5){
            cout<<2<<endl;
            continue;
        }
        if(n==6){
            cout<<6<<endl;
            continue;
        }
        if(n==7){
            cout<<8<<endl;
            continue;
        }
        if(n%7==0){
            while(n>0){
                cout<<8;
                n-=7;
            }
            cout<<endl;
            continue;
        }
        int ts=n;
        int cnt=0;
        while(ts>7){
            ts-=7;
            cnt++;
        }
        cnt++;
        dfs(cnt);
    }
    return 0;
}
