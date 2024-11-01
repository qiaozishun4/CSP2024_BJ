
#include <bits/stdc++.h>
using namespace std;
const int N=1e2*2+5;
long long a[N][N];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char b,c;
        cin>>b>>c;
        if(c=='A'){
            c='1';
        }
        if(c=='T'){
            c='9'+1;
        }
        if(c=='J'){
            c='9'+2;
        }
        if(c=='Q'){
            c='9'+3;
        }
        if(c=='K'){
            c='9'+4;
        }
        a[b][c]++;
    }
    long long sum=0;
    for(int i=49;i<=61;i++){
            if(a['D'][i]>=1){
                a['D'][i]=1;
            }
            if(a['C'][i]>=1){
                a['C'][i]=1;
            }
            if(a['H'][i]>=1){
                a['H'][i]=1;
            }
            if(a['S'][i]){
                a['S'][i]=1;
            }
        sum+=a['D'][i];
        sum+=a['C'][i];
        sum+=a['H'][i];
        sum+=a['S'][i];
    }
    cout<<52-sum;
    return 0;
}