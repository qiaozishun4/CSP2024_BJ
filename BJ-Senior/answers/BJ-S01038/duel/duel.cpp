#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,a[N],buc[N],maxa,precnt,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        buc[a[i]]++;
        maxa=max(maxa,a[i]);
    }
    for(int i=1;i<=maxa;i++){
        if(buc[i]>=precnt){
            ans-=precnt;
            precnt=buc[i];
        }
        else ans-=buc[i];
    }
    printf("%d\n",ans);
    return 0;
}
//Workingmen of all countries, unite!