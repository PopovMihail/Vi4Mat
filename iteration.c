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
  system("PAUSE");	
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
 
	int i, j, k = 0, f;
	float temp;
	float x[n];
	float t[n];
	
	for (i = 0; i < n; i++ ) {
		temp = matr[i][i];
		for(j = 0; j < n + 1; j++){
			if(temp != 0)
				matr[i][j] /= temp;			
		}
	}
	
	for (i = 0; i < n; i++ ) {
		for(j = 0; j < n + 1; j++){
			matr[i][i] = 0;
			x[i] = 0;
			t[i] = 0;	
		}
	}
	
	//ñàì ìåòîä
	while(f != n){
		f = 0;
	
	    /*for (i = 0; i < n; i++ ) {
			for(j = 0; j < n ; j++){
				t[i] = t[i] - matr[i][j] * x[j];
			}
		}*/
		for (i = 0; i < n; i++ ) {
			for(j = 0; j < n ; j++){
				if(i == 0){
                     t[i] = t[i] - matr[i][j] * x[j];
                     }
             t[i] = t[i] - matr[i][j] * t[j];
            }
		}
	
	for (i = 0; i < n; i++ ) {
           // printf("del = %.5f\n", fabs(t[i] + matr[i][n] - x[i]));
            	if(fabs(t[i] + matr[i][n] - x[i]) <= 0.001){
                    	f++;
            	}
		x[i] = t[i] + matr[i][n];
	 	t[i] = 0;
	}
		//sleep(500);
        
		k++;
	}
	
	
	//â èòîãå âñå ïî êðàñîòå âûâîäèì 
	//è ðàäóåìñÿ æèçíè =)
	
	printf("Ответ:\n");
	printf("******************\n");
	for(i = 0; i < n; i++)
		printf("x%d = %.3f\t", i+1, x[i]);
    printf("\nКол-во итераций = %d",k);	
    printf("\n******************\n");		
	
		
}
