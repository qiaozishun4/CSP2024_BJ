#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int colorArray[10000][2];
int cs[10000];
int n;
int maxNow=-2147483648;
void paint(int n,int q){
    int c[n];
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(colorArray[i][0]==colorArray[j][0]&&colorArray[i][1]==colorArray[j][1]){
                c[i]=colorArray[i][0];
                break;
            }
        }
    }
    cs[q]=0;
    for(int x=0;x<n;x++){
        cs[q]+=c[n];
    }
    return;
}
void colors(int q,int n){
    if(q>=n){
        paint(n,q);
        return;
    }
    colorArray[q][1]=0;
    colors(q+1,n);
    colorArray[q][1]=1;
    return;
}
int main(){
    freopen("color.in","r+",stdin);
    freopen("color.out","w+",stdout);
    int dataNumber;
    cin>>dataNumber;
    for(int dataNow=0;dataNow<dataNumber;dataNow++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>colorArray[i][0];
        }
        colors(0,n);
        maxNow=-2147483648;
        for(int x=0;x<n;x++){
            maxNow=max(maxNow,cs[n]);
        }
        cout<<maxNow<<endl;
    }
    return 0;
}
