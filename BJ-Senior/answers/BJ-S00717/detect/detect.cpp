#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

struct node{
    int d,v,a;
}car[MAXN]={0};

struct mide{
    int left,right;
}nitian[MAXN]={0};;

int t;
int h[MAXN]={0};

int check(int x,int y){
    int i;
    for(i=x;i<=y;i++){
        if(h[i]==1)
            return 1;
    }
    return 0;
}

void dfs(){
    float n,m,l,V,t;
    int p[MAXN]={0};
    int i;
    int num=0;
    for(i=0;i<MAXN;i++){
        nitian[i].left=0;
        nitian[i].right=0;
        h[i]=0;
    }
    cin>>n>>m>>l>>V;
    for(i=0;i<n;i++){//n*car
        cin>>car[i].d>>car[i].v>>car[i].a;
    }
    for(i=0;i<m;i++){//m*check point
        cin>>p[i];
    }
    for(i=0;i<n;i++){
        h[p[i]]=1;
    }
    //check whether beyond the principle speed,account the number of the car
    for(i=0;i<n;i++){
        t=(V-car[i].v)/car[i].a;
        if(car[i].a>0){
            if(car[i].v>V && check(car[i].d,l)==1){      //there 're have check point between di and L
                nitian[num].left=car[i].d;
                nitian[num].right=l;
                num++;
            }
            else if(car[i].v<V){
                if(check(car[i].d+car[i].v*t+(car[i].a*t*t)/2+1,l)==1){
                    nitian[num].left=car[i].d+car[i].v*t+(car[i].a*t*t)/2+1;
                    nitian[num].right=l;
                    num++;
                }
            }
        }
        else if(car[i].a<0){
            if(car[i].v>V){
                if(check(car[i].d,car[i].d+car[i].v*t+(car[i].a*t*t)/2-1)==1){
                    nitian[num].left=car[i].d;
                    nitian[num].right=car[i].d+car[i].v*t+(car[i].a*t*t)/2-1;
                    num++;
                }
            }
        }
        else if(car[i].a==0){
            if(car[i].v>V && check(car[i].d,l)==1){
                nitian[num].left=car[i].d;
                nitian[num].right=l;
                num++;
            }
        }
    }
    int sum=0;
    int k[MAXN]={0};
    int j;
    for(i=0;i<num;i++){
        for(j=nitian[i].left;j<=nitian[i].right;j++){
            k[j]=1;
        }
    }
    for(i=0;i<=m;i++){
        if(k[p[i]]==0){
            sum++;
        }
    }
    cout<<num<<" "<<m-sum<<endl;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int i;
    cin>>t;
    for(i=0;i<t;i++){
        dfs();
    }
    return 0;
}
