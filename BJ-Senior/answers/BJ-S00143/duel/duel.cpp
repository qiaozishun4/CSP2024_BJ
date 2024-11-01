#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxx=1e5;
int a[maxx+1];
int main(){
freopen("duel.in","r",in);
freopen("duel.out","w",out);
int n;
scanf("%d",&n);
int k=0;
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);

}
sort(a+1,a+n+1);
a[0]=-1;
for(int i=1;i<=n;i++){
if(a[i-1]==-1){
break;
}else{
if(a[i-1]<a[i]){
a[i-1]=-1;
k=k+1;
}
if(a[i-1]==a[i]){
for(int j=2;j<=n;j++){
if(a[i-j]==a[i]||a[i-j]==-1){
break;
}else{
a[i-j]=-1;
k=k+1;
}
}
}
}

}
printf("%d",k);



return 0;}