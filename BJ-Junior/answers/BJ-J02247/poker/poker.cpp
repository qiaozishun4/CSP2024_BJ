#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
int a[20][20];
string s;
int turn(char c){
    int res;
    if(c>='0' && c<='9'){
        res=c-'0';
    }else if(c=='A'){
        res=1;
    }else if(c=='T'){
        res=10;
    }else if(c=='J'){
        res=11;
    }else if(c=='Q'){
        res=12;
    }else{
        res=13;
    }
    return res;
}
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int i;
    t=52;
    for(i=1;i<=n;i++){
        cin>>s;
        int tp=turn(s[1]);
        if(s[0]=='D'){
            if(a[1][tp]==0){
                t--;
            }
            a[1][tp]++;
        }else if(s[0]=='C'){
            if(a[2][tp]==0){
                t--;
            }
            a[2][tp]++;
        }else if(s[0]=='H'){
            if(a[3][tp]==0){
                t--;
            }
            a[3][tp]++;
        }else{
            if(a[4][tp]==0){
                t--;
            }
            a[4][tp]++;
        }
    }
    cout<<t<<endl;
    return 0;
}
