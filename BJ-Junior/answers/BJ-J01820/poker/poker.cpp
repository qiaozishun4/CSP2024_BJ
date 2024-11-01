#include<bits/stdc++.h>
using namespace std;
int d[20],c[20],h[20],s[20];
char s1,s2;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    int a;
    cin>>n;
    while(n--){
        cin>>s1;
        cin>>s2;
        if(s2<='9'&&s2>='1'){
            a=s2-'0';
        }else if(s2=='T'){
            a=10;
        }else if(s2=='J'){
            a=11;
        }else if(s2=='Q'){
            a=12;
        }else if(s2=='K'){
            a=13;
        }else{
            a=1;
        }
        if(s1=='D'){
            d[a]+=1;
        }
        if(s1=='C'){
            c[a]+=1;
        }
        if(s1=='H'){
            h[a]+=1;
        }
        if(s1=='S'){
            s[a]+=1;
        }
    }
    for(int i=1;i<=13;i++){
        if(d[i]==0) ans++;
        if(c[i]==0) ans++;
        if(h[i]==0) ans++;
        if(s[i]==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}