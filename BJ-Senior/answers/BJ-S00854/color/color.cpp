#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
int T;
int n;
int a[N];
int colour[N];
long long maxn;
void f(int num,long long sum){
    if(num==n+1){
        maxn=max(maxn,sum);
        return;
    }
    for(int cl=0;cl<=1;cl++){
        colour[num]=cl;
        int ok=0;
        for(int i=num-1;i>0;i--){
            if(colour[i]==cl){
                if(a[i]==a[num]){
                    f(num+1,sum+a[i]);
                }
                else{
                    f(num+1,sum);
                }
                ok=1;
                break;
            }
        }
        if(ok==0){
            f(num+1,sum);
        }
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        memset(colour,0,sizeof(colour));
        cin>>n;
        maxn=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        f(1,0);
        cout<<maxn<<endl;
    }
    return 0;
}