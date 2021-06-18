/* header files */
#include <stdio.h>
#include <stdlib.h>

/* main */
int main(void) {
    char program1[] = "./primegeneration.out";
    int result1;

    /* 他プログラムを実行する */
    result1 = system(program1);
    if ( result1 == EXIT_SUCCESS ) {
        puts("正常に実行されました．");
    } else {
        puts("正常に実行されませんでした．");
    }


    char program2[] = "./primegeneration.out";
    int result2;

    /* 他プログラムを実行する */
    result2 = system(program2);
    if ( result2 == EXIT_SUCCESS ) {
        puts("正常に実行されました．");
    } else {
        puts("正常に実行されませんでした．");
    }

    char program3[] = "./keygeneration.out";
    int result3;

    /* 他プログラムを実行する */
    result3 = system(program3);
    if ( result3 == EXIT_SUCCESS ) {
        puts("正常に実行されました．");
    } else {
        puts("正常に実行されませんでした．");
    }

    char program4[] = "./angou.out";
    int result4;

    /* 他プログラムを実行する */
    result4 = system(program4);
    if ( result4 == EXIT_SUCCESS ) {
        puts("正常に実行されました．");
    } else {
        puts("正常に実行されませんでした．");
    }

    char program5[] = "./hukugou.out";
    int result5;

    /* 他プログラムを実行する */
    result5 = system(program5);
    if ( result5 == EXIT_SUCCESS ) {
        puts("正常に実行されました．");
    } else {
        puts("正常に実行されませんでした．");
    }

    return EXIT_SUCCESS;
}
