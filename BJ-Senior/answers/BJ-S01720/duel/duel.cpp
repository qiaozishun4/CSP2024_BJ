#include<bits/stdc++.h>
using namespace std;
long long a[100005];
struct monster{
    long long type;
    long long num;
    long long tgt;
}b[100005];
long long c[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int j=0;
    for(int i=1;i<=n;i++){
        if(c[a[i]]==0){
            c[a[i]]++;
            j++;
            b[j].type=a[i];
            b[j].num++;
        }else{
            b[j].num++;
        }
    }
    for(int i=1;i<=j;i++){
        b[i].tgt=b[i-1].tgt+b[i-1].num;
    }
    long long ttl=b[j].tgt;
    long long ttlminus=0;
    long long tmp=ttlminus;
    for(int i=2;i<=j;i++){
        tmp=ttlminus;
        ttlminus+=min(b[i].num,b[i].tgt-tmp);
    }

    cout<<ttl-ttlminus+b[j].num;
    return 0;
}
