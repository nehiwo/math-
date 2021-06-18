#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    
    int n;
    scanf("%d",&n);
    int i,j;
    char bingo[n][n + 1];
    for(i = 0; i < n; i++){
        for(j = 0; j < n + 1; j++){
            scanf("%c",&bingo[i][j]);
        }
    }
    
    int o_counta = 0, x_counta = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n + 1; j++){
            if(j == i && bingo[i][j] == 'o') o_counta++;
            else if(j == i && bingo[i][j] == 'x') x_counta++;
            if(o_counta == n || x_counta == n) printf("Bingo!\n");
        }
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n + 1; j++){
            o_counta = 0, x_counta = 0;
            if(bingo[i][j] == 'o') o_counta++;
            else if(bingo[i][j] == 'x') x_counta++;
            if(o_counta == n || x_counta == n) printf("Bingo!\n");
        }
    }
    
    char temp;
    for(i = 0; i < n; i++){
        for(j = 0; j < n + 1; j++){
            temp = bingo[i][j];
            bingo[i][j] = bingo[j][i];
            bingo[j][i] = temp;
        }
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n + 1; j++){
            o_counta = 0, x_counta = 0;
            if(bingo[i][j] == 'o') o_counta++;
            else if(bingo[i][j] == 'x') x_counta++;
            if(o_counta == n || x_counta == n) printf("Bingo!\n");
        }
    }
    printf("\n");
    return 0;
}
