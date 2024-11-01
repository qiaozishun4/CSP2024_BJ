#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int c=0;
    char ch=getchar();

    while(ch<'0'||ch>'9'){
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c;
}

int n,r[100005],ans=0;

bool check(int a,int b){
    return r[a]>r[b];
}

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    n=read();

    ans=n;

    for(int i=1;i<=n;i++){
        r[i]=read();
    }

    sort(r+1,r+n+1);

    int a=1,b=1;

    while(a<=n){
        do{
            a++;
            if(a>n){
                break;
            }
        }while(!check(a,b));

        if(a>n){
            break;
        }

        b++;
        ans--;
    }

    cout<<ans<<"\n";

    return 0;
}
