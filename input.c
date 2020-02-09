#include<stdio.h>

//This is a simple single line comment

int main(){
    int i;
    int a = 0;
    if(a>=0){
        /* This is 
        a simple multiline comment
        */
        printf("If statement works");
    }
    for(i=0;i<3;i++){
        printf("%d. For Loop works\n",i);
    }
    while(a==0 && i==3){
        printf("While statement works");
        a++;
    }
}
