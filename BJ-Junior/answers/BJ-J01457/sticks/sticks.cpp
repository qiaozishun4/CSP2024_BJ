#include<bits/stdc++.h>
using namespace std;
int kf(int m){
int a=1;
for(int i=0;i<m;i++){a*=10;}
return a;
}
int qw(int c,int v){
    return c/kf(v-1)%10;
}
int jw(int s){
    for(int i=1;i<8;i++){
        if(s<kf(i)){
            return i;
        }
    }
}
int js(int n){
    int w,sum,ans;
        if(n%7==0){w=n/7;}else{w=n/7+1;}
    for(int i=1;i<kf(w);i++){
    //    return kf(w);
            sum=0;
        for(int j=1;j<=jw(i);j++){
                int p=qw(i,j);
    if(p==0){sum+=6;}
    if(p==1){sum+=2;}
    if(p==2){sum+=5;}
    if(p==3){sum+=5;}
    if(p==4){sum+=4;}
    if(p==5){sum+=5;}
    if(p==6){sum+=6;}
    if(p==7){sum+=3;}
    if(p==8){sum+=7;}
    if(p==9){sum+=6;}
        }
        if(sum==n){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
            cin>>n;
    cout<<js(n)<<endl;
    }

        fclose(stdin);
        fclose(stdout);
       return 0;
        }


