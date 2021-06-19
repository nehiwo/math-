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
    int a = 0, d = 0, c = 0;
    
    for(c = 0; c < N - 1; c++){
        for(a = c + 1; a < N; a++){
            b[a] = b[a] - (b[c] * A[a][c]) / (A[c][c]);
        }
        for(d = c + 1; d < N; d++){
            for(a = c + 1; a < N; a++){
                A[a][d] = A[a][d] - (A[a][c] * A[c][d]) / (A[c][c]);
            }
        }
    }
    
    x[N-1] = b[N-1] / A[N-1][N-1];
    for(c = N - 2; c > -1; c--){
        x[c] = b[c];
        for(a = c + 1; a < N; a++){
            x[c] = x[c] - A[c][a] * x[a];
        }
        x[c] = x[c] / A[c][c];
    }
    
    printf("solution=\n");
    for(c = 0; c < N; c++){
        printf("%f\n",x[c]);
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
    int N = 0;
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
