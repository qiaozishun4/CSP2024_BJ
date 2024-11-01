#include <iostream>

using namespace std;


void pai(int a,int* b){
    for(int i=0;i<a;i++){
        int now=b[i];
        int small=i;
        for(int x=i+1;x<a;x++){
            if(b[x]<now){
                small=x;
            }
        }
        b[i]=b[small];
        b[small]=now;
    }
}

int dou(int a,int* b,int *c){
    int result=0;
    int x;
    for(int i=0;i<a;i++){
        x=i;
        while(x<a){
            if(b[x]>b[i]){
                if(c[x]!=0){
                    result+=1;
                    c[x]=0;
                    break;
                }
                else{
                    x++;
                }
            }
            else{
                x++;
            }
        }
    }
    return a-result;
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int a;
    cin >> a;
    int *b=(int*)malloc(sizeof(int)*a);
    int *c=(int*)malloc(sizeof(int)*a);
    for(int i=0;i<a;i++){
        c[i]=i;
    }
    for(int i = 0;i<a;i++){
        cin >> b[i];
    }
    pai(a,b);
    int result=dou(a,b,c);
    free(b);
    free(c);
    cout<<result<<endl;
    return 0;
}
