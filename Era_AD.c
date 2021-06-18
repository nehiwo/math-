#include<stdio.h>
#include<stdlib.h>

#define ERA_BUF_SIZE 1024

#define START_OF_MEIJI 1868
#define START_OF_TAISHOU 1912
#define START_OF_SHOUWA 1926
#define START_OF_HEISEI 1989
#define START_OF_REIWA 2019

#define MOJI_OF_NUMBER 48 //文字リテラルとしての数字0を表す10進数

#define THISYEAR 2020 //作成時は西暦2020年
#define THISYEAR_OF_ERA 2 //作成時は令和2年

int Meiji_trans_AD(int year_of_meiji);
int Taishou_trans_AD(int year_of_taishou);
int Shouwa_trans_AD(int year_of_shouwa);
int Heisei_trans_AD(int year_of_heisei);
int Reiwa_trans_AD(int year_of_reiwa);

int main(){
    
    char era[ERA_BUF_SIZE];
    while(fgets(era,sizeof(era),stdin)){
        
        puts("\n");
        
        int age = 0;
        int era_of_year = 0;
        
        era_of_year = 10 * (era[1] - MOJI_OF_NUMBER) + era[2] - MOJI_OF_NUMBER;
        
        //元号判定と年齢計算
        if(era[0] == 'M'){
            if(era_of_year >= 46){
                printf("ERROR:expect year of era is wrong.\n");
                goto retry;
            }
            else{
                printf("%s年 = A.D.%d年\n",era,Meiji_trans_AD(era_of_year));
                age = THISYEAR - Meiji_trans_AD(era_of_year);
            }
        }else if(era[0] == 'T'){
            if(era_of_year >= 16){
                printf("ERROR:expect year of era is wrong.\n");
                goto retry;
            }
            else{
                printf("%s年 = A.D.%d年\n",era,Taishou_trans_AD(era_of_year));
                age = THISYEAR - Taishou_trans_AD(era_of_year);
            }
        }else if(era[0] == 'S'){
            if(era_of_year >= 65){
                printf("ERROR:expect year of era is wrong.\n");
                goto retry;
            }
            else{
                printf("%s年 = A.D.%d年\n",era,Shouwa_trans_AD(era_of_year));
                age = THISYEAR - Shouwa_trans_AD(era_of_year);
            }
        }else if(era[0] == 'H'){
            if(era_of_year >= 32){
                printf("ERROR:expect year of era is wrong.\n");
                goto retry;
            }
            else{
                printf("%s年 = A.D.%d年\n",era,Heisei_trans_AD(era_of_year));
                age = THISYEAR - Heisei_trans_AD(era_of_year);
            }
        }else if(era[0] == 'R'){
            if(era_of_year >= 3){
                printf("ERROR:expect year of era is wrong.\n");
                goto retry;
            }
            else{
                printf("%s年 = A.D.%d年\n",era,Reiwa_trans_AD(era_of_year));
                age = THISYEAR - Reiwa_trans_AD(era_of_year);
            }
        }else{
            printf("ERROR:expect initial of era is wrong.\n");
            goto retry;
        }
        if(era_of_year == THISYEAR_OF_ERA && era[0] == 'R') printf("Your age is %d.\nRight?\n",age);
        else printf("Your age is %d or %d.\nRight?\n",age,age - 1);
    
    retry:
        
        puts("\n");

    }
    return 0;
}

int Meiji_trans_AD(int year_of_meiji){
    int year_of_ad = 0;
    year_of_ad = year_of_meiji + START_OF_MEIJI - 1;
    return year_of_ad;
}

int Taishou_trans_AD(int year_of_taishou){
    int year_of_ad = 0;
    year_of_ad = year_of_taishou + START_OF_TAISHOU -1;
    return year_of_ad;
}

int Shouwa_trans_AD(int year_of_shouwa){
    int year_of_ad = 0;
    year_of_ad = year_of_shouwa + START_OF_SHOUWA - 1;
    return year_of_ad;
}

int Heisei_trans_AD(int year_of_heisei){
    int year_of_ad = 0;
    year_of_ad = year_of_heisei + START_OF_HEISEI - 1;
    return year_of_ad;
}

int Reiwa_trans_AD(int year_of_reiwa){
    int year_of_ad = 0;
    year_of_ad = year_of_reiwa + START_OF_REIWA - 1;
    return year_of_ad;
}
