#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N    3
#define TMAX 100
#define EPS  (1.0e-6)

typedef double vec[N]; //ベクトル
typedef double mat[N][N]; //行列

//ベクトル初期化
void init_vec(vec x){
 int i;
 for(i=0;i<N;i++){
  x[i]=0;
 }
}

//ベクトルに行列を作用 y=Ax
void vec_x_mat(vec y, mat a, vec x){
 int i,j;
 double vxm;
 for(i=0;i<N;i++){
  vxm=0;
  for(j=0;j<N;j++){
   vxm+=a[i][j]*x[j];
  }
  y[i]=vxm;
 }
}

//内積を計算
double dot_product(vec x,vec y){
 int i;
 double dot_p=0;
 for(i=0;i<N;i++){
  dot_p+=x[i]*y[i];
 }
 return dot_p;
}

//ベクトルノルムを計算
//ベクトルノルム:=sgm(0~N-1)|x[i]|
double vec_norm(vec x){
 int i;
 double norm=0;
 for(i=0;i<N;i++){
  norm+=fabs(x[i]);
 }
 return norm;
}

//CG法
void cg_method(mat a,vec x,vec b){
 static vec p;//探索方向ベクトル
 static vec r;//残差ベクトル
 static vec ax;
 static vec ap;
 int i,iter;

 //Axを計算
 vec_x_mat(ax,a,x);

 //pとrを計算 p=r:=b-Ax
 for(i=0;i<N;i++){
  p[i]=b[i]-ax[i];
  r[i]=p[i];
 }

 //反復計算
 for(iter=1;iter<TMAX;iter++){
  double alpha,beta,err=0;

  //alphaを計算
  vec_x_mat(ap,a,p);
  alpha=+dot_product(p,r)/dot_product(p,ap);
  for(i=0;i<N;i++){
   x[i]+=+alpha*p[i];
   r[i]+=-alpha*ap[i];
  }
  err=vec_norm(r); //誤差を計算
  printf("反復回数:%d\t 誤差:%g\n",iter,err);
  if(err<EPS) break;

  //err>EPSならbetaとpを計算してループ継続
  beta=-dot_product(r,ap)/dot_product(p,ap);
  for(i=0;i<N;i++){
   p[i]=r[i]+beta*p[i];
  }
 }
}

int main(void){
 //連立方程式 Ax=b
 //行列Aは正定値対象行列
 mat a={{1.0,2.0,1.0},
        {2.0,5.0,1.0},
        {1.0,1.0,-1.0}
        };
 vec b={2.0,-3.0,1.0};
 //初期値は適当
 vec x={1.0,1.0,1.0};
 int i;
 //CG法でAx=bを解く
 cg_method(a,x,b);
 printf("###Calc End.###\n");
 for(i=0;i<N;i++){
  printf("x[%d]=%2g\n",i,x[i]);
 }
 return 0;
}