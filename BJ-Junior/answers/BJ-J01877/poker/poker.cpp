#include<iostream>
using namespace std;
int t[100]={0},n;

int getnumber(char a,char b){
    int sum1;
    if(a=='D'){
        sum1=0;
    }else if(a=='C'){
        sum1=1;
    }else if(a=='H'){
        sum1=2;
    }else{
        sum1=3;
    }
    int sum2;
    if(b=='T'){
        sum2=10;
    }else if(b=='A'){
        sum2=1;
    }else if(b=='J'){
        sum2=11;
    }else if(b=='Q'){
        sum2=12;
    }else if(b=='K'){
        sum2=13;
    }else{
        sum2=b-'0';
    }
    return sum1*13+sum2;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
        t[getnumber(a[0],a[1])]=1;
    }
    int ans=0;
    for(int i=1;i<=52;i++){
        if(t[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
