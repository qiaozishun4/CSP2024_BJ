#include<bits/stdc++.h>
using namespace std;
bool p[65];
int n,sum,ans;
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        sum=0;
        if(a=='C'){
            sum+=13;
        }
        if(a=='H'){
            sum+=26;
        }
        if(a=='S'){
            sum+=39;
        }
        if(b=='A'){
            sum++;
        }
        else if(b=='T'){
            sum+=10;
        }
        else if(b=='J'){
            sum+=11;
        }
        else if(b=='Q'){
            sum+=12;
        }
        else if(b=='K'){
            sum+=13;
        }
        else{
            sum+=b-'0';
        }
        p[sum]=1;
    }
    for(int i=1;i<=60;i++){
        if(p[i]==1){
            ans++;
        }
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}