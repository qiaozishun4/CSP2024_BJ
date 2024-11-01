#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    bool flag=true;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>2){
            flag=false;
        }
    }
    if(flag==true){
        int c=0,d=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                c++;
            }else{
                d++;
            }
        }
        printf("%d",n-min(c,d));
        return 0;
    }else{
        printf("1");
    }
    return 0;
}
