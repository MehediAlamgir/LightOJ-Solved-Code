    #include<stdio.h>

    int main()
    {
    int a,t,c,s;

    scanf("%d\n\n",&t);
    for(c=1;c<=t;c++)
    {
    scanf("%d",&a);

 if(a>20)  break;
    if(a%2==0){

    printf("%d %d\n",a/2,a/2);
    }
    else

    printf("%d %d\n",(a-1)/2,(a-(a-1)/2));

    }

    return 0;
    }
