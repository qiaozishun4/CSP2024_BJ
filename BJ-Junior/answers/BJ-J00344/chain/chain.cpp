else if(s > 7 && s < 1000){
            for(int i = 1; i <= 9; i++){
                for(int j = 0; j <= 9; j++){
                        for(int k =  1; k <= 9; k++){
                    if(a[i] + a[j] + a[k] == s && a[i] < a[j] && a[j] < a[k]){
                        if(sss > i && xxx > j && uuu > k && a[i] != a[j] && a[j] != a[k] && a[k] != a[i]){
                            sss = i;
                            xxx = j;
                            uuu = k;
                        }
                        }

                        }

                }
            }
        cout << sss << xxx << uuu;
        break;
        }