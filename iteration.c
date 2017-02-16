#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_matrix(int n, float **matr, FILE *f); 
void print_matrix(int n, float **matr); 
void iteration(int n, float **matr);

int main()
{
  FILE *f ;
  f = fopen("matrix.txt", "r");
  
  int n;
  fscanf(f,"%d", &n);
  
  int i;
  
  float **mas = (float **)malloc(n*sizeof(float *));

    for(i = 0; i < n; i++) {
        mas[i] = (float *)malloc((n+1)*sizeof(float));
    }
    read_matrix(n, mas, f);
    print_matrix(n, mas);
	
	iteration(n, mas);
    //print_matrix(n, mas);

    fclose(f);
 // system("PAUSE");	
  return 0;
}

void read_matrix(int n, float **matr, FILE *f){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n+1; j++){
            fscanf(f,"%f", &matr[i][j]);
       
        }
    }
}

void print_matrix(int n, float **matr){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n+1; j++){
             printf("%.3f\t", matr[i][j]);
        }
         printf("\n");
    }
    printf("*************\n");
}

void iteration(int n, float **matr){
 
	int i, j, k = 0;
	float temp;
	float x[n];
	float t[n];
	//делю каждую строку на диагональный элемент
	//тобиш выставляю единицы на гл. деагонали
	for (i = 0; i < n; i++ ) {
		temp = matr[i][i];
		for(j = 0; j < n + 1; j++){
			if(temp != 0)
				matr[i][j] /= temp;			
		}
	}
	//зануляю гл. диагональ
	//и паралельно зануляю х вектор
	for (i = 0; i < n; i++ ) {
		for(j = 0; j < n + 1; j++){
			matr[i][i] = 0;
			x[i] = 0;
			t[i] = 0;	
		}
	}
	
	//сам метод
	while(k < 7){
		
		//тут короче говоря 
		//в итый элемент темпового массива записываем
		//каждый итый элемент матрицы умноженый а Х вектор 
		for (i = 0; i < n; i++ ) {
			for(j = 0; j < n ; j++){
				t[i] = t[i] - matr[i][j] * x[j];
			}
		}
		// а тута
		//в итый элемент массива вектора записываем из
		//темпового массива итый элемент + эный элемент
		//матрыцы
		//это для того что типа там же выражать Х1 Х2 надо было и все такое
		//и зануляем темповый массив а пздц будет
		for (i = 0; i < n; i++ ) {
			 x[i] = t[i] + matr[i][n];
			 t[i] = 0;
		}
		k++;
	}
	//в итоге все по красоте выводим 
	//и радуемся жизни =)
	
	printf("Ответ:\n");
	printf("******************\n");
	for(i = 0; i < n; i++)
		printf("x%d = %.3f\t", i+1, x[i]);
	printf("\n******************\n");		
	
		
}
