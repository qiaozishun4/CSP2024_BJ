#include<iostream>
using namespace std;
int n,t;
string x[1008]={"-1","-1","1","7","4","2","0","8"};
string minx(string b,string c){
    if(b.size()<c.size()) return b;
    if(b.size()>c.size()) return c;
    if(b<c) return b;
    return c;
}
string maxx(string b,string c){
    if(b.size()>c.size()) return b;
    if(b.size()<c.size()) return c;
    if(b>c) return b;
    return c;
}
void pp(){
    for(int i=8;i<=1000;i++){
            x[i]="a";
        for(int j=2;j<=i/2;j++){
            string sa=min(x[j],x[i-j]),sb=max(x[j],x[i-j]);
            string s2=sa+sb;
            if(sa=="0") {
                if(sb=="0") s2="60";
                else if(sb<"6") s2=sb+"0";
                else s2="6"+sb;

            }
            if(x[i]=="a") x[i]=s2;
            else x[i]=minx(x[i],s2);
        }
        //cout<<x[i]<<' ';
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    pp();
    while(t--){
        cin>>n;
        if(n==6) cout<<6;
        else cout<<x[n];
        cout<<endl;
    }
    return 0;
}
