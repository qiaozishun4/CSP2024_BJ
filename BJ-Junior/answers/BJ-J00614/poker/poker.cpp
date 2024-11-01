#include<iostream>
typedef long long ll;
using namespace std;
bool t[10][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ll n,ans=0;
    char ch1,ch2;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>ch1>>ch2;
        if(ch1=='D'){
            if(ch2>='2'&&ch2<='9'){
                t[1][ch2-'0']=true;
            }
            else if(ch2=='A'){
                t[1][1]=true;
            }
            else if(ch2=='T'){
                t[1][10]=true;
            }
            else if(ch2=='J'){
                t[1][11]=true;
            }
            else if(ch2=='Q'){
                t[1][12]=true;
            }
            else{
                t[1][13]=true;
            }
        }
        else if(ch1=='C'){
            if(ch2>='2'&&ch2<='9'){
                t[2][ch2-'0']=true;
            }
            else if(ch2=='A'){
                t[2][1]=true;
            }
            else if(ch2=='T'){
                t[2][10]=true;
            }
            else if(ch2=='J'){
                t[2][11]=true;
            }
            else if(ch2=='Q'){
                t[2][12]=true;
            }
            else{
                t[2][13]=true;
            }
        }
        else if(ch1=='H'){
            if(ch2>='2'&&ch2<='9'){
                t[3][ch2-'0']=true;
            }
            else if(ch2=='A'){
                t[3][1]=true;
            }
            else if(ch2=='T'){
                t[3][10]=true;
            }
            else if(ch2=='J'){
                t[3][11]=true;
            }
            else if(ch2=='Q'){
                t[3][12]=true;
            }
            else{
                t[3][13]=true;
            }
        }
        else{
            if(ch2>='2'&&ch2<='9'){
                t[4][ch2-'0']=true;
            }
            else if(ch2=='A'){
                t[4][1]=true;
            }
            else if(ch2=='T'){
                t[4][10]=true;
            }
            else if(ch2=='J'){
                t[4][11]=true;
            }
            else if(ch2=='Q'){
                t[4][12]=true;
            }
            else{
                t[4][13]=true;
            }
        }
    }
    for(ll i=1;i<=4;i++){
        for(ll j=1;j<=13;j++){
            if(t[i][j]==false){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
