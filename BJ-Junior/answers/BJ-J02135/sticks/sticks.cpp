#include<bits/stdc++.h>
using namespace std;
int dsn[10]={6,2,5,5,4,5,6,3,7,6};
int sn(int x){
    int cpo=0;
    for(int i=pow(10,log10(x));i>=1;i/=10){
        int qwn=x/i%10;
        cpo+=dsn[qwn];

    }
    return cpo;
}
int main(){
freopen("stick.in","r",stdin);
freopen("stick.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        if(t<2){
            cout<<-1;
        }else{
            if(t<29){
        for(int j=0;j<=10100;j++){
            if(sn(j)==t){
                cout<<j<<endl;
                break;
            }
        }
            }else if(t<40){
                for(long long j=10100;j<=10100000;j++){
            if(sn(j)==t){
                cout<<j<<endl;
                break;
            }
        }
            }else {//
                for(long long j=1001000;j<=101000000;j++){
            if(sn(j)==t){
                cout<<j<<endl;
                break;
            }
        }
            }

        }
    }
    return 0;
}