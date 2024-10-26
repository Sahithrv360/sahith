#include <stdio.h>
int main () { 

int a,b,c;
printf("enter the value of a=");
scanf("%d",&a);
printf("enter the value of b=");
scanf("%d",&b);
printf("enter the value of c=");
scanf("%d",&c);

if((a>b)&&(b>c))
{printf("%d>%d>%d",c,b,a);}

else if ((a>b)&&(c>b))
{printf("%d>%d>%d",b,c,a);}

else if((c>b)&&(b>a))
{printf("%d>%d>%d",a,b,c);}

else if((c>b)&&(a>b))
{printf("%d>%d>%d",b,a,c);}

else if((b>a)&&(c>a))
{printf("%d>%d>%d",a,c,b);}

else
{printf("%d>%d>%d",c,a,b);}

return 0;
}
