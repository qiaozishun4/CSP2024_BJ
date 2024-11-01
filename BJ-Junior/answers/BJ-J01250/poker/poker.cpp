#include<iostream>
#include<cstdio>
using namespace std;
char d[14];
char h[14];
char s[14];
char c[14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int d3=0,h3=0,c3=0,s3=0;
    for(int i=1;i<=n;i++){
        char c1,c2;
        cin>>c1>>c2;
        if(c1=='D'){
            bool f=true;
            for(int i=1;i<=d3;i++){
                if(d[i]==c2){
                    f=false;
                }
            }
            if(f==true){
                d3++;
                d[d3]=c2;
            }
        }
        if(c1=='C'){
            bool f=true;
            for(int i=1;i<=c3;i++){
                if(c[i]==c2){
                    f=false;
                }
            }
            if(f==true){
                c3++;
                c[c3]=c2;
            }
        }
        if(c1=='H'){
            bool f=true;
            for(int i=1;i<=h3;i++){
                if(h[i]==c2){
                    f=false;
                }
            }
            if(f==true){
                h3++;
                h[h3]=c2;
            }
        }
        if(c1=='S'){
            bool f=true;
            for(int i=1;i<=s3;i++){
                if(s[i]==c2){
                    f=false;
                }
            }
            if(f==true){
                s3++;
                s[s3]=c2;
            }
        }
    }
    int cnt=52-s3-h3-c3-d3;
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}