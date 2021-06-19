#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){

    double a[5][5] = {{38.0,-6.0,0.0,0.0,0.0}, {-6.0,38.0,-3.0,0.0,0.0}, {0.0,-3.0,38.0,0.0,0.0}, {0.0,0.0,0.0,38.0,-9.0}, {0.0,0.0,0.0,-9.0,38.0}}; //入力用の配列
    double inv_a[5][5]; //ここに逆行列が入る
    double buf = 0.0; //一時的なデータを蓄える
    int i = 0, j = 0, k = 0; //カウンタ
    int n = 5;  //配列の次数

    //単位行列を作る
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            inv_a[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    //掃き出し法
    for(i = 0; i < n; i++){
        buf = 1 / a[i][i];
        for(j = 0; j < n; j++){
            a[i][j] *= buf;
            inv_a[i][j] *= buf;
        }
        for(j = 0; j < n; j++){
            if(i != j){
                buf = a[j][i];
                for(k = 0; k < n; k++){
                    a[j][k] -= a[i][k] * buf;
                    inv_a[j][k] -= inv_a[i][k] * buf;
                }
            }
        }
    }
    //逆行列を出力
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf(" %f", inv_a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
