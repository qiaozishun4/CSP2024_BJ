#include<bits/stdc++.h>
using namespace std;

int datas[15]={6,2,5,5,4,5,6,3,7,6};
unordered_map<int,int> m;
int n;

inline int solve(int a){
    int ret=0;
    int counts=0;
    while(a){
        ret+=datas[a%10];
        a=a/10;
        counts++;
    }
    if(counts*2>n){
        return -1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(m[n]!=0){
            cout<<m[n]<<endl;
            continue;
        }
        if(n==0){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<10;
            for(int i=1;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        for(int i=1;true;i++){
            if(solve(i)==-1){
                cout<<-1<<endl;
                break;
            }else if(solve(i)==n){
                m[n]=i;
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
