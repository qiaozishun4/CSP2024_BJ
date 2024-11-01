#include<stdio.h>
const int maxx=15;
int a[maxx+1];
int main(){
freopen("color.in","r",in);
freopen("color.out","w",out)
int t;
scanf("%d",&t);
int n;
while(t--){
int k=0;
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
}
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
if(a[i]==a[j]&&a[i]!=-1&&a[j]!=-1){
k=k+a[i];
a[i]=-1;
a[j]=-1;
}
}
}

printf("%d/n",k);
}



return 0;
}