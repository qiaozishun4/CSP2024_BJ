#include<bits/stdc++.h>
using namespace std;
int T,n[1000000],x=0,C[100000],max1[100000],max2[100000],max3=0;
cin>>T;
int A[1000000000][1000000000];
for(int j=0;j<T;j++){
    cin>>n[j];
    for(int i=0;i<n;i++){
        cin>>A[i][n];
    }
}
void check(){
    for(int i=0;i<n[x];i++){
        for(int j=0;j<n[x];j++){
            int m=A[i][j];
            for(int y=1;y<n[x];y++){
                if(m==A[i][y]){
                    C[i]=C[i]+1;
                }
            }
        }
        max1[x]=max(A[i]);
        C[max1[x]]=0
        max2[x]=max(A[i]);\
        for(int f=0;f<n[x];f++){
            C[f]=0;
        }
        x++;
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    check();
    for(int i=0;i<100000;i++){
        cout>>max1[i]+max2[i];
    }
    return 0;
}
