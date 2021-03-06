#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double F(double x){
return x*x-9*x+14;
}

//Функция поиска корня:
double FindRoot(double (*f)(double), double a, double b, double eps){
    double c;
    while(abs(f(b) - f(a)) > eps){
         c=(f(b) * a - f(a) * b) / (f(b) - f(a));
         if((f(a) * f(c)) > 0) 
                  a = c;
         else b = c;
    }
    return c;
}
int main(){
    //Интервал, погрешность и корень:
    double a, b, eps, x;
    printf("Введите точку а\n");
    scanf("%lf", &a);
    printf("\nВведите точку b\n");
    scanf("%lf", &b);
    //Проверка корректности интервала:
    if(F(a)*F(b) > 0){
          printf("\nНеверный интервал!!!\n");
          return 0;
     }
    printf("\nТочность:\n");
    scanf("%lf", &eps);
    //Поиск решения:
    x=FindRoot(F,a,b,eps);
    printf("\nX = %f\n", x);
    system("pause");
return 0;
}
