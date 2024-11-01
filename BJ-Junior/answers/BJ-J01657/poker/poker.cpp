#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    int d[20]={0},c[20]={0},h[20]={0},s[20]={0};
    char a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D'){
            if(b=='A'){
                d[1]=1;
            }
            else if(b=='T'){
                d[10]=1;
            }
            else if(b=='J'){
                d[11]=1;
            }
            else if(b=='Q'){
                d[12]=1;
            }
            else if(b=='K'){
                d[13]=1;
            }
            else{
                d[b-'0']=1;
            }
        }
        if(a=='C'){
            if(b=='A'){
                c[1]=1;
            }
            else if(b=='T'){
                c[10]=1;
            }
            else if(b=='J'){
                c[11]=1;
            }
            else if(b=='Q'){
                c[12]=1;
            }
            else if(b=='K'){
                c[13]=1;
            }
            else{
                c[b-'0']=1;
            }
        }
        if(a=='H'){
            if(b=='A'){
                h[1]=1;
            }
            else if(b=='T'){
                h[10]=1;
            }
            else if(b=='J'){
                h[11]=1;
            }
            else if(b=='Q'){
                h[12]=1;
            }
            else if(b=='K'){
                h[13]=1;
            }
            else{
                h[b-'0']=1;
            }
        }
        if(a=='S'){
            if(b=='A'){
                s[1]=1;
            }
            else if(b=='T'){
                s[10]=1;
            }
            else if(b=='J'){
                s[11]=1;
            }
            else if(b=='Q'){
                s[12]=1;
            }
            else if(b=='K'){
                s[13]=1;
            }
            else{
                s[b-'0']=1;
            }
        }
    }
    for(int i=1;i<=13;i++){
        if(d[i]==0){
            ans++;
        }
        if(h[i]==0){
            ans++;
        }
        if(c[i]==0){
            ans++;
        }
        if(s[i]==0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
