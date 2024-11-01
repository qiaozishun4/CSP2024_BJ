#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[10][60];
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ll n,cnt=0;
    scanf("%lld",&n);
    for(ll i=0;i<n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]>='0'&&s[1]<='9'){
                if(a[0][s[1]-'0']==0){
                    cnt++;
                    a[0][s[1]-'0']=1;
                }
            }else if(s[1]=='T'){
                if(a[0][10]==0){
                    cnt++;
                    a[0][10]=1;
                }
            }else if(s[1]=='J'){
                if(a[0][11]==0){
                    cnt++;
                    a[0][11]=1;
                }
            }else if(s[1]=='Q'){
                if(a[0][12]==0){
                    cnt++;
                    a[0][12]=1;
                }
            }else if(s[1]=='K'){
                if(a[0][13]==0){
                    cnt++;
                    a[0][13]=1;
                }
            }else{
                if(a[0][1]==0){
                    cnt++;
                    a[0][1]=1;
                }
            }
        }else if(s[0]=='C'){
            if(s[1]>='0'&&s[1]<='9'){
                if(a[1][s[1]-'0']==0){
                    cnt++;
                    a[1][s[1]-'0']=1;
                }
            }else if(s[1]=='T'){
                if(a[1][10]==0){
                    cnt++;
                    a[1][10]=1;
                }
            }else if(s[1]=='J'){
                if(a[1][11]==0){
                    cnt++;
                    a[1][11]=1;
                }
            }else if(s[1]=='Q'){
                if(a[1][12]==0){
                    cnt++;
                    a[1][12]=1;
                }
            }else if(s[1]=='K'){
                if(a[1][13]==0){
                    cnt++;
                    a[1][13]=1;
                }
            }else{
                if(a[1][1]==0){
                    cnt++;
                    a[1][1]=1;
                }
            }
        }else if(s[0]=='H'){
            if(s[1]>='0'&&s[1]<='9'){
                if(a[2][s[1]-'0']==0){
                    cnt++;
                    a[2][s[1]-'0']=1;
                }
            }else if(s[1]=='T'){
                if(a[2][10]==0){
                    cnt++;
                    a[2][10]=1;
                }
            }else if(s[1]=='J'){
                if(a[2][11]==0){
                    cnt++;
                    a[2][11]=1;
                }
            }else if(s[1]=='Q'){
                if(a[2][12]==0){
                    cnt++;
                    a[2][12]=1;
                }
            }else if(s[1]=='K'){
                if(a[2][13]==0){
                    cnt++;
                    a[2][13]=1;
                }
            }else{
                if(a[2][1]==0){
                    cnt++;
                    a[2][1]=1;
                }
            }
        }else{
//            cout<<"333"<<endl;
            if(s[1]>='0'&&s[1]<='9'){
                if(a[3][s[1]-'0']==0){
                    cnt++;
                    a[3][s[1]-'0']=1;
                }
            }else if(s[1]=='T'){
                if(a[3][10]==0){
                    cnt++;
                    a[3][10]=1;
                }
            }else if(s[1]=='J'){
                if(a[3][11]==0){
                    cnt++;
                    a[3][11]=1;
                }
            }else if(s[1]=='Q'){
                if(a[3][12]==0){
                    cnt++;
                    a[3][12]=1;
                }
            }else if(s[1]=='K'){
                if(a[3][13]==0){
                    cnt++;
                    a[3][13]=1;
                }
            }else{
                if(a[3][1]==0){
                    cnt++;
                    a[3][1]=1;
                }
            }
        }
    }
//    for(ll i=0;i<4;i++){
//        for(ll j=1;j<=13;j++){
//            printf("%lld ",a[i][j]);
//        }
//        printf("\n");
//    }
    printf("%lld\n",52-cnt);
    return 0;
}
