#include <iostream>
#include <string.h>
using namespace std;
int T,n,m,l,v;// num of car/ num of detector/distant/ limit
int a[1050][4];//di ,vi , ai;
int p[1050];//position of detector
int dis[5];// to save overspeed position
int xl(int vt,int vl,int a){
    int x = ((vt*vt)-(vl*vl))/(2 * a);

    return x;
}
void cal(int d, int vo, int ai){
     if(ai == 0 ){
        if(vo >v){
        dis[0] = d;
        dis[1] = l;
        return ;
        }else{
        dis[0 ] = -1;
        dis[1] = -1;
        }

    }else if(ai > 0){

        if(vo > v){
            dis[0] = d;
            dis[1] = l;
            return ;
        }else if(vo = v){
            if(d = l){
                dis[0]  = -1;
                dis[1] = -1;
                return ;
            }else{
                dis[0] = d;
                dis[1] = l;
                return ;
            }
        }else if(vo < v){

            int x = xl(v , vo , ai);
            x += d;
            if(x > l){
                dis[0]  = -1;
                dis[1] = -1;
                return ;
            }else{
            dis[0] = x;
            dis[1] = l;
                return ;
            }
        }

    }else if(ai < 0){
        if(vo <= v){
            dis[0] = -1;
            dis[1] = -1;
            return ;
        }else{//v0  >v

            int x = xl(v, vo, ai);
            x += d;
            if(x > l){
                dis[0] = d;
                dis[1] = l;
                return ;
            }else{
                dis[0] = d;
                dis[1] = x;
                return ;
            }
        }

    }
return ;
}
int main(){
freopen("detect.in", "r", stdin);
freopen("detect.out", "w", stdout);
memset(a, 0, sizeof(a));

    cin >> T;
    while(T --){
        cin >> n >>m >> l >>v;
        for(int i = 1; i <= n; i ++){
                int n1,n2,n3;//di,vi ai
            cin >> n1 >> n2 >>n3;

            //if(n3 == 0 &&n2 <= v){
              //  continue;

            //}
           // if(n3 < 0 && n2 <= v){
            //    continue;
            //}

            a[i][0] = n1;
            a[i][1] = n2;
            a[i][2] = n3;
        }
        for(int i = 1; i <= m; i ++){
            cin >> p[i];
        }
        int al[1050][2], carn = 0, res1= 0;
        memset(al,0,sizeof(al));
        for(int i = 1; i <= n; i ++){
            if(a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0){
              continue;
            }else{

                dis[0] = 0;
                dis[1] = 0;
                cal(a[i][0], a[i][1], a[i][2]);

               if(dis[0] != -1&&dis[1] != -1) {
                    carn ++;
                 al[carn][0] = dis[0];
                 al[carn][1] = dis[1];
                res1 ++;
               }


            }

        }
        cout << res1 <<" ";
        int ans[1005] ;//if  car in ansi overspeed is 1
        memset(ans,0,sizeof(ans));
        for(int i = 0; i <= l; i ++){//ans
            for(int j = 1; j <= carn; j ++){//al

                    if(i >= al[j][0] && i<= al[j][1]){
                        ans[i] = 1;

                }
            }
        }

        int res2 = 0;
        for(int i = 0; i <= l; i ++){
            if(ans[i] == 1){
                    i ++;
                while(ans[i] == 1){
                    for(int j = 1; j <= m; j ++){
                        if(p[j] == i){
                            res2++;
                        }
                        i++;
                    }
                }
            }

        }
        cout << res2 << endl;

    }


return 0;
}




