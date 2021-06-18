#include<stdio.h>
#include<math.h>

int main(){
    
    int sq1_x[4],sq1_y[4],sq2_x[4],sq2_y[4];
    int i;
    
    //1つ目の矩形の座標入力
    for(i = 0; i < 4; i++){
        scanf("%d %d",&sq1_x[i],&sq1_y[i]);
    }
    //２つ目の矩形の座標入力
    for(i = 0; i < 4; i++){
        scanf("%d %d",&sq2_x[i],&sq2_y[i]);
    }
    
    //矩形の中心座標の算出と２つの矩形の距離
    double cent1_x = (sq1_x[0] + sq1_x[2]) / 2.0, cent1_y = (sq1_y[0] + sq1_y[2]) / 2.0;
    double cent2_x = (sq2_x[0] + sq2_x[2]) / 2.0, cent2_y = (sq2_y[0] + sq2_y[0]) / 2.0;
    double distance_x = fabs(cent1_x - cent2_x), distance_y = fabs(cent1_y - cent2_y);
    
    //矩形の横幅、縦幅の算出
    double width1 = sq1_x[0] - sq1_x[2], height1 = sq1_y[0] - sq1_y[2];
    double width2 = sq2_x[0] - sq2_x[2], height2 = sq2_y[0] - sq2_y[0];
    
    printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",cent1_x,cent1_y,cent2_x,cent2_y,distance_x,distance_y,width1,height1,width2,height2);
    
    //衝突条件
    if(sq1_x[0] > sq2_x[0] && sq1_x[2] < sq2_x[2] && sq1_y[0] > sq2_y[2] && sq1_y[2] < sq2_y[2]) printf("FAULES(sq1>sq2)\n");
    else if(sq1_x[0] < sq2_x[0] && sq1_x[2] > sq2_x[2] && sq1_y[0] < sq2_y[2] && sq1_y[2] > sq2_y[2]) printf("FAULES(sq1<sq2)\n");
    else if(distance_x < (width1 + width2) / 2.0 && distance_y < (height1 + height2) / 2.0) printf("TRUE\n");
    else printf("FAULES\n");
    return 0;
}
