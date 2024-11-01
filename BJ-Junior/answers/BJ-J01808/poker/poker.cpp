#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);


    int vis_poker[6][15];
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            vis_poker[i][j]=1;
        }
    }
    char fd[4];
    for(int i=1;i<=n;i++){
        cin>>fd;
        int li=1;
        switch(fd[0]){
            case 'D':
                li=1;
                break;
            case 'C':
                li=2;
                break;
            case 'H':
                li=3;
                break;
            case 'S':
                li=4;
                break;

        }
        if(fd[1]>='2'&&fd[1]<='9') vis_poker[li][fd[1]-'0']=0;
        else if(fd[1]=='T') vis_poker[li][10]=0;
        else if(fd[1]=='J') vis_poker[li][11]=0;
        else if(fd[1]=='Q') vis_poker[li][12]=0;
        else if(fd[1]=='K') vis_poker[li][13]=0;
        else if(fd[1]=='A') vis_poker[li][1]=0;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(vis_poker[i][j]==1){
                sum++;
            }
        }
    }
    printf("%d\n",sum);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
