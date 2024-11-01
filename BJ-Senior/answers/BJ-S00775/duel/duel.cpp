#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,a[maxn],new1[maxn],l,len,ansl=0x3f;
bool k2 = 0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
        if(a[i]>2)k2 = 1;
    }
    if(k2 == 1){
    sort(a+1,a+1+n);
    for(int i = 1 ; i <= n ; i++){
        len = n/i;
        l = 0;
        for(int j = 1 ; j <= len ; j++){
            new1[++l]=a[j];
        }
        for(int j = 1 ; j <= n/len ; j++){
            for(int x = j*len+1 ; x <= min(n,(j+1)*len) ; x++){
                if(a[x] > new1[x-j*len])new1[x-j*len]=a[x];
                else new1[++l]=a[x];
            }
            sort(new1+1,new1+1+l);
        }
        //cout<<i<<endl;
        //for(int j = 1;  j <= l ; j++)cout<<new1[j]<<" ";
        //cout<<endl;
        ansl = min(ansl,l);
    }
    cout<<ansl;
    }
    else{
        int tot1 = 0,tot2=0;
        for(int i = 1 ; i <= n ; i++){
            if(a[i] == 1)tot1++;
            else tot2++;
        }
        cout<<min(tot1,tot2);
    }
    return 0;
}