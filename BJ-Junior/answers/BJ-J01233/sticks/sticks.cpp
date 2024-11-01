//T3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void print(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar((x%10)^48);
}
ll T,n,dth;
ll trans(ll x){
    switch(x){
        case 0:return 6;
        case 1:return 2;
        case 2:return 5;
        case 4:return 4;
        case 6:return 6;
        case 7:return 3;
        case 8:return 7;
    }
}
namespace cod1{//baoli
    ll num[505];
    bool dfs(ll sy,ll dep){
        if(dep>dth){
            if(sy==0){
                for(int i=1;i<=dth;i++){
                    print(num[i]);
                }
                return true;
            }
            return false;
        }
        for(int i=0;i<=9;i++){
            if(i==3 || i==5 || i==9 || i==6)continue;
            num[dep]=i;
            if(dfs(sy-trans(i),dep+1))return true;
            num[dep]=0;
        }
        return false;
    }
    void work(){
        for(int i=1;i<=9;i++){
            if(i==3 || i==5 || i==9)continue;
            num[1]=i;
            if(dfs(n-trans(i),2)){
                return;
            }
        }
    }
}
namespace cod2{//A
    void work(){
        for(int i=1;i<=dth;i++){
            print(8);
        }
    }
}
namespace cod3{//B
    void work(){
        print(10);
        for(int i=3;i<=dth;i++){
            print(8);
        }
    }
}
namespace cod4{
    void work(){
        if(n<7 || n==10){
            switch(n){
                case 2:print(1);return;
                case 3:print(7);return;
                case 4:print(4);return;
                case 5:print(2);return;
                case 6:print(6);return;
                case 10:print(22);return;
            }
        }
        ll i=1;
        switch(n%7){
            case 2:print(1);i=2;break;
            case 3:print(200);i=4;break;
            case 4:print(20);i=3;break;
            case 5:print(2);i=2;break;
            case 6:print(6);i=2;break;
        }
        for(;i<=dth;i++){
            print(8);
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        dth=(((ll)(n/7))*7==n)?n/7:n/7+1;
        if(n==1)print(-1);
        else if(n%7==0)cod2::work();
        else if(n%7==1)cod3::work();
        else if(n<=50)cod1::work();
        else cod4::work();
        putchar('\n');
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
