#include<bits/stdc++.h>
using namespace std;
long long n,jsq=0;
long long a[100005];
long long book[100005];
bool cmp(long long x,long long y){
    return x<y;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        book[a[i]]++;
    }
    sort(a+1,a+1+n,cmp);
    long long t=a[1],box=0;
    for(int i=1;i<=n;i++){
        if(t!=a[i]){
            if(book[t]-book[a[i]]>=0){
                book[t]-=book[a[i]];
            }
            else{
                book[t]=0;
                box=book[a[i]]-book[t];
                for(int j=i-1;j>=1;j--){
                    if(box==0){
                        break;
                    }
                    if(book[j]>0){
                        if(box>=book[j]){
                            box-=book[j];
                            book[j]=0;
                        }
                        else{
                            book[j]-=box;
                            box=0;
                        }
                    }
                }
            }
            t=a[i];
        }
    }
    for(int i=2;i<=n+1;i++){
        if(a[i-1]!=a[i]){
            jsq+=book[a[i-1]];
        }
    }
    cout<<jsq<<endl;
    return 0;
}
