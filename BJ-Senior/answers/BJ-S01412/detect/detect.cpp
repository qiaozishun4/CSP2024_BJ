#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,m,l,v,y[100001]={},cnt=0,h;
struct car{
    int v;
    int d;
    int a;
}c[10001];
bool chao(int v1,int d1,int y1[],int m1){
    for(int i=0;i<m1;i++){
        if(v1>v){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n>>m>>l>>v;
    //cout<<1;
        cnt=0;
        for(int j=0;j<n;j++){
            cin>>c[j].d>>c[j].v>>c[j].a;
        }
        //cout<<43278;
        //cout<<1;
        for(int k=0;k<m;k++){
            cin>>y[k];
        }
        for(int j=0;j<n;j++){
            if(chao(c[j].v,c[j].d,y,m))
                cnt++;
            else if(c[j].a<=0)
                continue;
            if(c[j].d+((v*v)-(c[j].v*c[j].v))/(c[j].a*2)<=y[m-1]){
                cnt++;
            }
        }
        cout<<cnt<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
