
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
    return 6*x*x+2*x-3;
}
int main(){
    double a, b, c, eps = 0.01;
    printf("Введите началюную точку\n");
    scanf("%lf", &a);
    printf("\nВведите конечную точку\n");
    scanf("%lf", &b);
    printf("\n");
    
    while( (b-a)>2*eps ){
        c = (a+b)/2;
        if (f(c)==0)
            break;
        if (f(a)*f(c)<0)
            b = c;
        else
            a = c;
    }
    printf("x = %.3f", c);

      system("pause");
return 0;
}
