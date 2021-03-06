#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){

    double a[5][5] = {{38.0,-6.0,0.0,0.0,0.0}, {-6.0,38.0,-3.0,0.0,0.0}, {0.0,-3.0,38.0,0.0,0.0}, {0.0,0.0,0.0,38.0,-9.0}, {0.0,0.0,0.0,-9.0,38.0}}; //入力用の配列
    double inv_a[5][5]; //ここに逆行列が入る
    double buf = 0.0; //一時的なデータを蓄える
    int i = 0, j = 0, k = 0; //カウンタ
    int n = 5;  //配列の次数

    //Aの行列ノルムを求める
    double A_norm1 = 0; //||A||1
    double s1 = 0; //各行の和の最大値が入る
    double buf1 = 0.0; //一時的なデータを蓄える
    for(i = 0; i < n; i++){
        s1 += a[0][i];
    }
    for(i = 0; i < n; i++){
        buf1 = 0.0;
        for(j = 0; j < n; j++){
            buf1 += a[i][j];
        }
        if(s1 < buf1){
            s1 = buf1;
        }
    }
    A_norm1 = s1;
    printf("A_norm1=%lf\n", A_norm1);

    double A_norm2 = 0.0; //||A||∞
    double s2 = 0.0; //各列の和の最大値が入る
    double buf2 = 0.0; //一時的なデータを蓄える
    for(i = 0; i < n; i++){
        s2 += a[i][0];
    }
    for(i = 0; i < n; i++){
        buf2 = 0.0;
        for(j = 0; j < n; j++){
            buf2 += a[j][i];
        }
        if(s2 < buf2){
            s2 = buf2;
        }
    }
    A_norm2=s2;
    printf("A_norm∞=%lf\n",A_norm2);

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
            printf(" %f",inv_a[i][j]);
        }
        printf("\n");
    }

    //inv_Aのノルムを求める
    double inv_A_norm1 = 0.0; //||inv_A||1
    double inv_s1 = 0.0; //各行の和の最大値を取る
    double inv_buf1 0.0; //一時的にデータを蓄える
    
    for(i = 0; i < n; i++){
        inv_s1 += inv_a[0][i];
    }

    for(i = 0; i < n; i++){
        inv_buf1 = 0.0;
        for(j = 0; j < n; j++){
            inv_buf1 += inv_a[i][j];
        }
        if(inv_s1 < inv_buf1){
            inv_s1 = inv_buf1;
        }
    }
    inv_A_norm1 = inv_s1;
    printf("inv_A_norm1=%lf\n", inv_A_norm1);

    double inv_A_norm2 = 0.0; //||inv_A||∞
    double inv_s2 = 0.0; //各列の和の最大値を取る
    double inv_buf2 = 0.0; //一時的にデータを蓄える
    
    for(i = 0; i < n; i++){
        inv_s2 += inv_a[i][0];
    }
    
    for(i = 0; i < n; i++){
        inv_buf2 = 0.0;
        for(j = 0; j < n; j++){
            inv_buf2 += inv_a[j][i];
        }
        if(inv_s2 < inv_buf2){
            inv_s2 = inv_buf2;
        }
    }
    inv_A_norm2 = inv_s2;
    printf("inv_A_norm∞=%lf\n", inv_A_norm2);

    //条件数を求める
    double cond1 = A_norm1 * inv_A_norm1, cond2 = A_norm2 * inv_A_norm2;
    printf("cond1=%lf\ncond∞=%lf\n", cond1, cond2);

    return 0;
}
