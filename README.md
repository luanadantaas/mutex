# mutex
o codigo pede um inteiro inicial e cria uma matriz de acordo com o tamanho determinado. a partir disso, sao escaneados numeros para serem inseridos na matris e com a criação de um array de threads, cada thread vai somar os elementos de uma linha da matriz ee dar uma print da soma geral de todas as threads, usando o mutex para que as threads nao executem ao mesmo tempo.

# comandos
$make - compila o codigo e cria o binario
$make clean - exclui o binario
$make run - executa o codigo

# função executada pelas threads
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

pthread_mutex_lock e pthread_mutex_unlock sao utilizados para que as threads naos ejam executadas ao mesmo tempo.
inteiro soma armazena a soma dos elementos de uma linnha, enquanto o somaGeral armazena a soma de todas as linhas da matriz.
