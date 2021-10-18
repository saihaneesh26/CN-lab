#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* xor(char* a,char*b){
    char *res=malloc(sizeof(char));
    int l = strlen(a);int k=0;
    for(int i=0;i<l;i++){
        if(a[i]==b[i])
        res[k++]='0';
        else res[k++]='1';
    }
    return res;
}

int func(char *div,int l)
{
    for(int i=0;i<l;i++)
    {
        if(div[i]=='1')
            return 1;
    }return 0;
}

char* rem(char *div,char* g){
    char *res=malloc(sizeof(char));
    int ptr=0;
    int l1=strlen(div);
    int l2=strlen(g);
        char a[10];char *temp=malloc(sizeof(char));
    while(ptr<l1-1)
    {
        for(int i=0;i<l2;i++)
        {
            a[i]= div[ptr+i];
        }
      temp = xor(a,g);
        // printf("temp%s",xor(a,g));
        for(int i=0;i<strlen(temp);i++)
        {
            div[ptr+i]=temp[i];
        }
        for(int i=0;i<l1;i++)
        {
            if(div[i]=='1')
            {ptr=i;break;}
        }
    }
    for(int i=1;i<l2;i++){
        res[i-1]=div[l1-l2+i];        
    }
    return res;
}

void main(){
    printf("enter code data:");
    char code[100],copy[100];
    scanf("%s",&code);
    
    printf("enter generator value:");
    char g[10];
    scanf("%s",&g);
    printf("data: %s, g:%s\n",code,g);
    //append 0s
    int i=0;
    int l2=strlen(g);
    int l1= strlen(code);
    for(int i=0;i<l1;i++)
    {
        copy[i]=code[i];
    }
    for(int i=0;i<l2-1;i++){
        code[l1+i]='0';
    }
    char *r =malloc(sizeof(char));
    r=rem(code,g);
    printf("rem %s\n",r);
    for(int i=0;i<l2-1;i++)
    {
        copy[l1+i]=r[i];
    }
    printf("final transmissin word:%s\n",copy);
}