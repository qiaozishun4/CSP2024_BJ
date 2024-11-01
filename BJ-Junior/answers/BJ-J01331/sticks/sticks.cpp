#include<iostream>
using namespace std;
string a[105];
bool lit(string X,string Y){
    if(X==Y){
        return 0;
    }
    if(X==""){
        return 0;
    }
    if(Y==""){
        return 1;
    }
    if(X.size()!=Y.size()){
        return X.size()<Y.size();
    }
    else{
        return X<Y;
    }
}
bool big(string X,string Y){
    if(X==Y){
        return 0;
    }
    if(Y==""){
        return 0;
    }
    if(X==""){
        return 1;
    }
    if(X.size()!=Y.size()){
        return X.size()>Y.size();
    }
    else{
        return X>Y;
    }
}
string ins(string x,string tp){
    //cout<<x<<' '<<tp<<'\n';
    if(tp==""){
        return x;
    }
    if(x=="0"){
        tp=tp[0]+x+tp.substr(1,tp.size()-1);
        return tp;
    }
    else{
        if(tp[0]>x[0]){
            int k=1;
            while(k<tp.size()&&tp[k]==0){
                k++;
            }
            tp=tp.substr(0,k)+tp[0]+tp.substr(k,tp.size()-k);
            tp[0]=x[0];
        }
        else{
            int k=1;
            while(k<tp.size()&&tp[k]<x[0]){
                k++;
            }
            tp=tp.substr(0,k)+x[0]+tp.substr(k,tp.size()-k);
        }
    }
    return tp;
}
string min(string X,string Y){
    if(X==Y){
        return X;
    }
    if(lit(X,Y)){
        return X;
    }
    else{
        return Y;
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=100;i++){
        a[i]="#";
    }
    for(int i=1;i<=100;i++){
        if(i>=2&&a[i-2]!="#"){
            if(a[i]=="#"){
                a[i]="";
            }
            a[i]=min(a[i],ins("1",a[i-2]));
            //cout<<a[i]<<' '<<ins("1",a[i-2])<<'\n';
        }
        if(i>=5&&a[i-5]!="#"){
            if(a[i]=="#"){
                a[i]="";
            }
            a[i]=min(a[i],ins("2",a[i-5]));
        }
        if(i>=4&&a[i-4]!="#"){
            if(a[i]=="#"){
                a[i]="";
            }
            string tt=ins("4",a[i-4]);
            a[i]=min(a[i],tt);
        }
        if(i>=3&&a[i-3]!="#"){
            if(a[i]=="#"){
                a[i]="";
            }
            a[i]=min(a[i],ins("7",a[i-3]));
        }
        if(i>=7&&a[i-7]!="#"){
            if(a[i]=="#"){
                a[i]="";
            }
            a[i]=min(a[i],ins("8",a[i-7]));
        }
        if(i>=6&&a[i-6]!="#"){
            if(a[i]=="#"){
                a[i]="";
            }
            if(a[i-6]==""){
                a[i]="6";
            }
            else{
                a[i]=min(a[i],ins("0",a[i-6]));
            }
        }
    }
    while(T--){
        int n;
        cin>>n;
        if(n<=100){
            if(a[n]!="#"){
                cout<<a[n]<<'\n';
            }
            else{
                cout<<"-1\n";
            }
        }
        else{
            int k=n/7;
            switch(n%7){
                case 0:{
                    for(int i=1;i<=k;i++){
                        cout<<8;
                    }
                    cout<<'\n';
                    break;
                }
                case 1:{
                    cout<<10;
                    for(int i=1;i<=k-1;i++){
                        cout<<8;
                    }
                    cout<<'\n';
                    break;
                }
                case 2:{
                    cout<<1;
                    for(int i=1;i<=k;i++){
                        cout<<8;
                    }
                    cout<<'\n';
                    break;
                }
                case 3:{
                    cout<<200;
                    for(int i=1;i<=k-2;i++){
                        cout<<8;
                    }
                    cout<<'\n';
                    break;
                }
                case 4:{
                    cout<<20;
                    for(int i=1;i<=k-1;i++){
                        cout<<8;
                    }
                    cout<<'\n';
                    break;
                }
                case 5:{
                    cout<<2;
                    for(int i=1;i<=k;i++){
                        cout<<8;
                    }
                    cout<<'\n';
                    break;
                }
                case 6:{
                    cout<<6;
                    for(int i=1;i<=k;i++){
                        cout<<8;
                    }
                    cout<<'\n';
                    break;
                }
            }
        }
    }
    return 0;
}
