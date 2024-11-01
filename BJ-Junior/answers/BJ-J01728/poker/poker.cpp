#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ls=0;
    for(int i=1;i<=n;i++){
        char b[2];
        cin>>b;
        bool f=true;
        if(b[0]=='D'){
            ls=0;
        }
        if(b[0]=='C'){
            ls=13;
        }
        if(b[0]=='H'){
            ls=26;
        }
        if(b[0]=='S'){
            ls=39;
        }
        if(b[1]=='A'){
            a[ls+1]++;
            f=false;
        }
        if(b[1]=='T'){
            a[ls+10]++;
            f=false;
        }
        if(b[1]=='J'){
            a[ls+11]++;
            f=false;
        }
        if(b[1]=='Q'){
            a[ls+12]++;
            f=false;
        }
        if(b[1]=='K'){
            a[ls+13]++;
            f=false;
        }
        if(f){
            a[ls+b[1]-'0']++;
        }
        f=true;
    }
    int ans=0;
    for(int i=1;i<=52;i++){
        if(a[i]==0)
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
