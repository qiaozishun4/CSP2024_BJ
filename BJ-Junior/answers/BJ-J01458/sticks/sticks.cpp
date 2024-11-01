#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[12]={100,100,1,7,4,2,0,8};
int b[12]={100,100,1,7,4,2,6,8};
int n;
string s;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==1 || n==0){
            printf("-1\n");
            continue;
        }
        int len=(n+6)/7;

        for(int i=0;i<len;i++){
            int mi=9;
            //cout<<n<<' '<<len<<' '<<n-7*(len-i-1)<<' '<<n-2*(len-i-1)<<endl;
            for(int j=n-7*(len-i-1);j<=min(7,n-2*(len-i-1));j++){
                if(i!=0)mi=min(mi,a[j]);
                else mi=min(mi,b[j]);
            }
            n-=mi;
            printf("%d",mi);
        }
        printf("\n");
    }
    return 0;
}
