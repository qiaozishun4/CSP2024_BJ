#include <iostream>
using namespace std;
int n,T,t[13],s[11]={6,2,5,5,4,5,6,3,7,6};
void write(int x,char num){
    for(int i=1;i<=x;i++)cout << num;
    if(num=='8')cout << endl;
}
void solve(){
    //cout << n<<" "<<l<<" "<<res<<endl;
    int l=n/7,res=n-l*7;
    if(res==0){
        write(l,'8');
        return ;
    }else if(res==1){
        cout << 10;
        write(l-1,'8');
    }else if(res==2){
        cout << 1;
        write(l,'8');
    }else if(res==2){
        cout << 1;
        write(l,'8');
    }else if(res==3){
        if(l==0)cout << 7<<endl;
        else if(l==1)cout << 22 << endl;
        else if(l>=2){
            cout << 200;
            write(l-2,'8');
        }
    }else if(res==4){
        if(l==0)cout << 4<<endl;
        else if(l>=1){
            cout << 20;
            write(l-1,'8');
        }
    }else if(res==5){
        cout << 2;
        write(l,'8');
    }else if(res==6){
        cout << 6;
        write(l,'8');
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    t[0]=1;
    while(T--){
        cin >>n;
        if(n==1){
            cout << -1 << endl;
            continue;
        }
        solve();
    }
    return 0;
}
