#include <bits/stdc++.h>
using namespace std;
map<long long,int>vis;
long long n;
string a;
long long sum;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        char a1=a[1];
        char a2=a[0];
        int a1s,a2s;
        if(a1=='A'){
            a1s=1;
        }
        if(a1>='2'&&a1<='9'){
            a1s=a1-'0';
        }
        else if(a1=='T'){
            a1s=10;
        }
        else if(a1=='J'){
            a1s=11;
        }
        else if(a1=='Q'){
            a1s=12;
        }
        else if(a1=='K'){
            a1s=13;
        }
        if(a2=='D'){
            a2s=1;
        }
        else if(a2=='C'){
            a2s=2;
        }
        else if(a2=='H'){
            a2s=3;
        }
        else{
            a2s=4;
        }
        long long ans=a2s*100+a1s;
        if(!vis[ans]){
            sum+=1;
            vis[ans]=1;
        }
    }
    cout<<52-sum;
    return 0;
}
