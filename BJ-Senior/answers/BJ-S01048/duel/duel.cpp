#include<bits/stdc++.h>
using namespace std;

void rst(int lst[10000]){
    for(int vuj=0;vuj<=10000;vuj++){
        lst[vuj] = 0;
    }
}

int len(int lst[10000]){
    int cnt=0;
    for(int mjb=0;mjb<10000;mjb++){
        if(lst[mjb]!=0) cnt++;
    }
    return cnt;
}

int main(){
    int n,rem=0,eq=0;
    int cnt=0,cnt_ans=0;
    int a[10000];
    rst(a);
    cin>>n;
    for(int in=0;in<n;in++){
        scanf("%d",&a[in]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rem<=len(a)){
                if(a[i]==a[j]) eq++;
                else if(a[i]>a[j]) {
                    a[j] = 0;
                    rem++;
                } else if(a[i]<a[j]){
                    a[i] = 0;
                    rem++;
                }
            }
        }
    }
    cout<<len(a)+eq-1;
    return 0;
}
