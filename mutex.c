#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *add ();

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int soma = 0;
int somaGeral = 0;
int elemento;
int **matrizGlobal;
int tam;
int count = 0;

int main(void)
{
  scanf("%d", &tam);
 
  matrizGlobal = malloc(sizeof(int*) * tam);
 
  for (int i = 0; i < tam; i++){
  	matrizGlobal[i]= malloc(sizeof(int*) * tam);
	//aloca quant x de inteiro
  }
  pthread_t threads[tam];
 
  for(int i = 0; i<tam; i++){
   
    for(int j= 0; j<tam; j++){
      scanf(" %d", &elemento);
      matrizGlobal[i][j]= elemento;
    }
   
    if(pthread_create(&(threads[i]), NULL, add, NULL)){
	printf("\nA thread %d não foi criada\n", i);
    }

  }
 
  for(int i = 0; i < tam; i++){
	pthread_join(threads[i], NULL);
  }
 
  printf("%d", somaGeral);
 
  return 0;
}
void *add()
{
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < tam; i++){
 	soma += matrizGlobal[count][i];
  }
  //printf("Valor da Soma %d", soma);
  somaGeral += soma;
  soma = 0;
  count++;
  pthread_mutex_unlock(&mutex);
}
