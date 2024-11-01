#include<bits/stdc++.h>
using namespace std;
int n,a;
const int num[12]={6,2,5,5,4,5,6,3,7,6};
void check(int i){
    if(i<=1) cout<<-1<<"\n";
    else if(i<=7){
        for(int j=1;j<10;j++){
            if(num[j]==i){
                cout<<j<<"\n";
                break;
            }
        }
    }
    else{
        int minn=i/7;
        int temp=(i%7)+7;
        if(temp==7) cout<<8;
        else if(temp==8) cout<<10;
        else if(temp==9) cout<<18;
        else if(temp==10) cout<<22;
        else if(temp==11) cout<<20;
        else if(temp==12) cout<<28;
        else if(temp==13) cout<<68;
        for(int i=1;i<minn;i++){
            cout<<8;
        }
        cout<<"\n";
        }
    }
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        check(a);
    }
    return 0;
}
