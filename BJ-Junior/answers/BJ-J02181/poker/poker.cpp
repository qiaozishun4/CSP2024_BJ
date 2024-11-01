#include<bits/stdc++.h>
using namespace std;
int n,y,x=0;
bool a[5][53];
string q;
void jia(int y){
    if(q[1]=='A'){
        if(a[y][1]==0)x++;
        a[y][1]=1;
    }
    if(q[1]>'1'&q[1]<='9'){
        if(a[y][q[1]-'0']==0)x++;
        a[y][q[1]-'0']=1;
    }
    if(q[1]=='T'){
        if(a[y][10]==0)x++;
        a[y][10]=1;
    }
    if(q[1]=='J'){
        if(a[y][11]==0)x++;
        a[y][11]=1;
    }
    if(q[1]=='Q'){
        if(a[y][12]==0)x++;
        a[y][12]=1;
    }
    if(q[1]=='K'){
        if(a[y][13]==0)x++;
        a[y][13]=1;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>q;
        if(q[0]=='D'){
            jia(1);
        }
        else if(q[0]=='C'){
            jia(2);
        }
        else if(q[0]=='H'){
            jia(3);
        }
        else if(q[0]=='S'){
            jia(4);
        }
    }
    int c=52-x;
    printf("%d",c);
    return 0;
}