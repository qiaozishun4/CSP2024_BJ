#include<bits/std.c++>
using namespace std;
string r;
int d[10000];
int c[10000];
int h[10000];
int s[10000];
int n;
int sum;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i];
        if(r[0]=='D'){
            if(r[1]=='T'){
                d[10]=1;
            }
            else if(r[1]=='J'){
                d[11]=1;
            }
            else if(r[1]=='Q'){
                d[12]=1;
            }
            else if(r[1]=='K'){
                d[13]=1;
            }
            else if(r[1]=='A'){
                d[1]=1;
            }
            else{
                d[r[1]]=1;
            }
        }
        else if(r[0]=='C'){
            if(r[1]=='T'){
                c[10]=1;
            }
            else if(r[1]=='J'){
                c[11]=1;
            }
            else if(r[1]=='Q'){
                c[12]=1;
            }
            else if(r[1]=='K'){
                c[13]=1;
            }
            else if(r[1]=='A'){
                c[1]=1;
            }
            else{
                c[r[1]]=1;
            }
        }
        else if(r[0]=='H'){
            if(r[1]=='T'){
                h[10]=1;
            }
            else if(r[1]=='J'){
                h[11]=1;
            }
            else if(r[1]=='Q'){
                h[12]=1;
            }
            else if(r[1]=='K'){
                h[13]=1;
            }
            else if(r[1]=='A'){
                h[1]=1;
            }
            else{
                h[r[1]]=1;
            }
        }
        else if(r[0]=='S'){
            if(r[1]=='T'){
                s[10]=1;
            }
            else if(r[1]=='J'){
                s[11]=1;
            }
            else if(r[1]=='Q'){
                s[12]=1;
            }
            else if(r[1]=='K'){
                s[13]=1;
            }
            else if(r[1]=='A'){
                s[1]=1;
            }
            else{
                s[r[1]]=1;
            }
        }
    }
    for(int j=1;j<=13;j++){
        if(d[i]==0){
            sum++;
        }
    }
    for(int j=1;j<=13;j++){
        if(c[i]==0){
            sum++;
        }
    }
    for(int j=1;j<=13;j++){
        if(h[i]==0){
            sum++;
        }
    }
    for(int j=1;j<=13;j++){
        if(s[i]==0){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
//谢谢老师：）
