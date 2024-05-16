#include<stdio.h>
#include"circle.h"
#include"rectangle.h"
#include"square.h"
int main()
{
int area1=area_circle(2);
printf("area of circle = %d\n",area1);
int area2=area_rectangle(2,4);
printf("area of rectangle = %d\n",area2);
int area3=area_square(2);
printf("area of square = %d\n",area3);
return 0;
}
