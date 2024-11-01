#include<bits/stdc++.h>
using namespace std;
const long long N=100010;
long long a[N],b[N],c[N],d[N];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n,cnt=0;
    char x,y;
    cin>>n;
    for(long long i=1;i<=52;i++){
        c[i]=i;
    }
    for(long long i=1;i<=n;i++){
        cin>>x>>y;
            if(n==1){
            cout<<"51";
            return 0;
        }
        if(x=='D'){
            a[i]=1;
        }else if(x=='C'){
            a[i]=14;
        }else if(x=='H'){
            a[i]=27;
        }else if(x=='S'){
            a[i]=40;
        }
        if(y=='1'){
            b[i]=1;
        }else if(y=='2'){
            b[i]=2;
        }else if(y=='3'){
            b[i]=3;
        }else if(y=='4'){
            b[i]=4;
        }else if(y=='5'){
            b[i]=5;
        }else if(y=='6'){
            b[i]=6;
        }else if(y=='7'){
            b[i]=7;
        }else if(y=='8'){
            b[i]=8;
        }else if(y=='9'){
            b[i]=9;
        }else if(y=='A'){
            b[i]=0;
        }else if(y=='T'){
            b[i]=9;
        }else if(y=='J'){
            b[i]=10;
        }else if(y=='Q'){
            b[i]=11;
        }else if(y=='K'){
            b[i]=12;
        }
    }
    for(long long i=1;i<=n;i++){
        long long sum=a[i]+b[i];
        for(long long j=1;j<=52;j++){
            c[sum]=0;
        }
    }
    for(long long i=1;i<=52;i++){
        if(c[i]==0){
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}