#include<bits/stdc++.h>
using namespace std;
int a[10];
int biaos[10]={0,1,2,4,6,7,8};
int biao[10]={6,2,5,4,6,3,7};
int bc[10]={1,5,2,3,1,4,0};
int b[10]={6,2,5,4,6,7};
int cha[10]={1,5,2,3,1,0};
int s[10]={0,1,2,4,6,8};
void st(int n){
    int w=n/7;
    if(n%7!=0){
        w++;
    }
    int p=7*w;
    int c=p-n;
    for(int i=1;i<=w;i++){
        a[i]=8;
    }
    for(int i=1;i<=w;i++){
        if(c==0){
            break;
        }
        int j;
        if(i==1){
            j=1;
        }else{
            j=0;
        }
        for(;j<6;j++){
            if(c>=cha[j]){
                c-=cha[j];
                a[i]=s[j];
                break;
            }
        }
    }
    for(int i=0;i<7;i++){
        if(c==bc[i]){
            a[w]=biaos[i];
            break;
        }
    }
    for(int i=1;i<=w;i++){
        cout<<a[i];
    }
    cout<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==1){
                cout<<"-1"<<endl;
            continue;
        }
        st(x);
    }
    return 0;
}
