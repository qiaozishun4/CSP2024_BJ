#include<bits/stdc++.h>
using namespace std;
int s[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c1,c2;
        cin>>c1>>c2;
        int p=0;
        if(c1=='D'){
            p=0;
        }else if(c1=='C'){
            p=1;
        }else if(c1=='H'){
            p=2;
        }else if(c1=='S'){
            p=3;
        }
        int p2=0;
        if(c2>='2'&&c2<='9'){
            p2=c2-'0';
        }else{
            if(c2=='A'){
               p2=1;
            }else if(c2=='T'){
                p2=10;
            }else if(c2=='J'){
                p2=11;
            }else if(c2=='Q'){
                p2=12;
            }else if(c2=='K'){
                p2=13;
            }
        }
        s[p*13+p2]=1;
    }
    int ans=0;
    for(int i=1;i<=52;i++){
        if(s[i]==0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
