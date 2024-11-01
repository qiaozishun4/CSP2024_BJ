#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct card{
    int atk;
    bool able;
};

bool myf(card p,card q){
    return p.atk<q.atk;
}

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n,s;
    scanf("%d",&n);
    s=n;
    card m[n];
    for (int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        m[i]={a,1};
    }
    sort(m,m+n,myf);
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (m[j].able==1&&(m[j].atk>m[i].atk)){
                m[j].able=0;
                s--;
            }
        }
    }
    printf("%d",s);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
