#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
cin>>T>>n>>m>>L>>V;
int matter[3][n],light[m];
int manycar=0;
void through(int a,int b,int c){
    float v,s;
    for(int t=0;t<n;i++){
        v=b+c*t;
        s=b*t+0.5*c*t*t;
        if(b==0){
            return 0;
        }
        for(int i=0;i<m;i++){
            if(s<=light[i]){
                if(v>V){
                    return 1;
                }
            }
        }
    }
    return 0;
}
void aduce(){
    int muchcar=0,x=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=a;j++){
            for(int y=0;y<=m;y++){
                for(int i=0;i<n;i++){
                    muchcar=muchcar+through(matter[1][i],matter[2][i],matter[3][i]);
                }
                if(muchcar==manycar){
                    x=j;
                }
            }
        }
    }
    return x;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    for(int i=0;i<n-1;i++){
        cin>>matter[1][i];
        cin>>matter[2][i];
        cin>>matter[3][i];
    }
    for(int i=0;i<=m;m++){
        cin>>light[i];
    }
    for(int i=0;i<n;i++){
        manycar=manycar+through(matter[1][i],matter[2][i],matter[3][i]);
    }
    cout>>manycar>>" ">>aduce();
    return 0;
}
