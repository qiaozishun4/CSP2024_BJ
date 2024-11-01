#include<bits/stdc++.h>
using namespace std;
int n,idx=1,r1[100005],hf,hcf[100005],l[100005];
int r2[100005],r[100005],minl=100005;
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n; hf=n;
    for(int i=1;i<=n;i++) {
        cin>>r[i];
    }sort(r+1,n+r+1);
    r1[1]=hcf[1]=1;
    for(int i=2;i<=n;i++){
        if(r[i]==r[i-1]) {
            r1[idx]++;
            hcf[idx]++;
        } else {
            r1[++idx]++;
            hcf[idx]++;
        }
    } l[1]=-1;
    for(int i=1;i<=idx;i++) {
        r2[i]=r1[i];
        if(i!=1) {
            l[i]=i-1;
        } else {
            l[i]=-1;
        }
    }
    while(hf!=hcf[minl]) {
        for(int i=2;i<=idx;i++){
            if(hcf[i]>=r1[l[i]]&&l[i]!=-1) {
                hf-=(r1[l[i]]+hcf[l[i]]);
                hcf[i]-=r1[l[i]]; hcf[l[i]]=0;
                r1[l[i]]=0;
                int k=l[i],s=l[i];
                while(k--){
                    if(r1[k]!=0) {
                        l[i]=k;
                    }
                } if(l[i]==s) {
                    l[i]=-1;
                }
            } else if(l[i]!=-1) {
                if(hcf[i]<=(r2[l[i]]-hcf[l[i]])) {
                    hf-=hcf[i];
                    r1[l[i]]-=hcf[i]; hcf[i]=0;
                } else {
                    hf-=(hcf[i]+hcf[i]-(r2[l[i]]-hcf[l[i]]));
                    hcf[l[i]]-=(hcf[i]-(r2[l[i]]-hcf[l[i]]));
                    r1[l[i]]-=hcf[i]; hcf[i]=0;
                }
            }
        } int sum=0;
        for(int i=1;i<=idx;i++) {
            if(hcf[i]!=0){
                sum++;
            }
        } if(sum<=1) {
            break;
        }
    } int cnt=0;
    for(int i=1;i<=idx;i++) {
        cnt+=r1[i];
    } cout<<cnt;
    return 0;
}
