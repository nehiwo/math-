#include <stdio.h>
#include <stdlib.h>

void readData(int N, double mat[N][N], double vec[N], FILE* in_FILE);
int getSize(FILE* in_FILE);
void printVec(int N, double vec[N], char* msg);
void printMat(int N, double mat[N][N], char* msg);

int main(int argc, const char ** argv){
	FILE* in_FILE = fopen(argv[1], "r");
	int N = getSize(in_FILE);
	double A[N][N]; double b[N]; 
	readData(N, A, b, in_FILE);
	fclose(in_FILE);
	double x[N];
	int k,l,m,y;
        double tmp1[N],tmp2;
        for(m=0;m<N-1;m++){ 
         if(A[m][m]==0){
          for(y=m;y<N;y++){
           tmp1[y]=A[m][y];
           A[m][y]=A[m+1][y];
           A[m+1][y]=tmp1[y];
          }
          tmp2=b[m];
          b[m]=b[m+1];
          b[m+1]=tmp2;
         }
          for(k=m+1;k<N;k++){
            b[k]=b[k]-(b[m]*A[k][m])/(A[m][m]);
          }
          for(l=m+1;l<N;l++){
            for(k=m+1;k<N;k++){
              A[k][l]=A[k][l]-(A[k][m]*A[m][l])/(A[m][m]);
            }
          }
        }
        x[N-1]=b[N-1]/A[N-1][N-1];
        for(m=N-2;m>-1;m--){
          x[m]=b[m];
          for(k=m+1;k<N;k++){
            x[m]=x[m]-A[m][k]*x[k];
          }
          x[m]=x[m]/A[m][m];
        }
        printf("solution=\n");
        for(m=0;m<N;m++){
          printf("%f\n",x[m]);
        }
        printf("\n");

	return 0;
}
void readData(int N, double mat[N][N], double vec[N], FILE* in_FILE){
	for(int i=0; i < N; i++){
		fscanf(in_FILE, "%lf", &(vec[i]));
	}
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			fscanf(in_FILE, "%lf", &(mat[i][j]));
		}
	}
}
int getSize(FILE* in_FILE){
	if (in_FILE == NULL){
		printf("File does not exist.\n");
		exit(1);
	}
	int N;
	fscanf(in_FILE, "%d", &N);
	return N;
}
void printVec(int N, double vec[N], char *msg){
	printf("%s\n", msg);
	for(int i=0; i<N; i++){
		printf("%lf ", vec[i]);
	}
	printf("\n");
}
void printMat(int N, double mat[N][N], char *msg){
	printf("%s\n", msg);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%lf ", mat[i][j]);
		}
		printf("\n");
	}
}
