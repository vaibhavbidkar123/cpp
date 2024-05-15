#include <stdio.h>
#include <stdlib.h>

int main()
{
    char inp[10*2];
    int count=0;
    int size = sizeof(inp)/sizeof(char);
    char sym[100];
    int top=-1;
    int temp;
    printf("enter the expression one by one \n");
    for(int i=0;i<10;i++){

        scanf("%c",&inp[i]);
        count++;

    }
    for(int i=0;i<count;i++){

        if('0'<=inp[i]<='9'){
            printf("%c",inp[i]);
        }else if(top==-1){

          sym[0]=inp[i];
        top++;
        }else if(inp[i]=='^'){

          printf("%c",inp[i]);


        }else if(inp[i]=='*' && (sym[top]=='/' || sym[top]=='*')){

          temp=sym[top];
          top--;
          sym[top]=inp[i];
          printf("%c",temp);


        }else if(inp[i]=='/' && (sym[top]=='/' || sym[top]=='*')){

          temp=sym[top];
          top--;
          sym[top]=inp[i];
          printf("%c",temp);


        }else if(inp[i]=='+' && (sym[top]=='/' || sym[top]=='*')){

          temp=sym[top];
          top--;
          sym[top]=inp[i];
          printf("%c",temp);


        }else if(inp[i]=='-' && (sym[top]=='/' || sym[top]=='*')){

          temp=sym[top];
          top--;
          sym[top]=inp[i];
          printf("%c",temp);


        }else if((inp[i]=='+' || inp[i]=='-') && (sym[top]=='+' || sym[top]=='-')){

          temp=sym[top];
          top--;
          sym[top]=inp[i];
          printf("%c",temp);

        }

    }

    return 0;
}
