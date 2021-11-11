#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include  <wait.h>
#include <time.h>
#include <semaphore.h>
#include <sys/ipc.h>

const int TIMEOUT = 2;	// 5 segundos
const int CANT = 12;	// 12 lugares en el mostrador
const int MOZOS = 3;
const int COCINEROS = 2;
const int MAX_PLATOS= 50;
int *FIN;

void coloco_plato(sem_t *sem_coc, sem_t *sem_most, sem_t *sem_mozo, int* indice, int* most, int i){
	int a,s, plato;

	plato=rand()%20; 	// Un valor aleatorio para colocar en el mostrador.
	sem_wait(sem_coc);				// Si el mostrador está vacio, se duerme. Aumenta la cant de espacios libres.
		sem_wait(sem_most);			// Semaforo para proteger la Seccion Critica.
			// INICIO SECCION CRITICA
			(*indice)++;
			most[*indice]=plato;
			(*FIN)++;
			// FIN SECCION CRITICA
			a=sem_getvalue(sem_coc, &s);	//Solo para ver, no debería ir un printf en una SC.
			printf("Cocinero:  %d, coloca plato %d en posicion %d semaforo cocinero %d\n",i,plato,*indice,s);
		sem_post(sem_most);
	sem_post(sem_mozo);				// Aumenta la cant de platos, si el mozo está dormido lo despierta.
}

void cocinero(sem_t *sem_coc, sem_t *sem_most, sem_t *sem_mozo, int* indice, int* most, int i){
	int s, plato;
	while(*FIN < MAX_PLATOS){
		printf("Cocinero:  %d, esperando por espacio en el most.\n",i);
		coloco_plato(sem_coc, sem_most, sem_mozo,indice,most,i);
		sleep(rand()%TIMEOUT);
	}
}

retiro_plato(sem_t *sem_coc, sem_t *sem_most, sem_t *sem_mozo, int* indice, int* most, int i){
	int plato;
	int s,a;
		sem_wait(sem_mozo);				// Si el mostrador está vacio, se duerme. Aumenta la cant de espacios libres.
			sem_wait(sem_most);			// Semaforo para proteger la Seccion Critica.
				// INICIO SECCION CRITICA
				plato=most[*indice];
				most[*indice]=0;
				a=sem_getvalue(sem_mozo, &s);
				printf("Mozo:  %d, retira plato %d en posicion %d semaforo mozo %d\n",i,plato,*indice,s);
				(*indice)--;
				// FIN SECCION CRITICA
			sem_post(sem_most);
		sem_post(sem_coc);				// Aumenta la cant de platos, si el mozo está dormido lo despierta.
}

void mozo(sem_t *sem_coc, sem_t *sem_most, sem_t *sem_mozo, int* indice, int* most, int i){
	while(*FIN < MAX_PLATOS){
		printf("Mozo:       %d, esperando por platos en el most.\n",i);
		retiro_plato(sem_coc, sem_most, sem_mozo,indice,most,i);
		sleep(rand()%TIMEOUT);
	}
	while(*indice >0){	
		printf("Mozo:       %d, retirando ultimos platos en el most.\n",i);
		retiro_plato(sem_coc, sem_most, sem_mozo,indice,most,i);
		sleep(rand()%TIMEOUT);
	}
}

void imprime_mostrador(int* most){
	int i;
	for(i=0;i<CANT;i++){
		printf("Lugar:  %d  Plato: %d\n",i,most[i]);
	}
}

void inicializa_mostrador(int* most){
	int i;
	for(i=0;i<CANT;i++){
		most[i]=0;
	}
}

int main(){

	int shm_fd1, shm_fd2,shm_fd3, pid,i,a,j, size;
	int *most, *indice;
	sem_t  *sem_most, *sem_mozo, *sem_coc;
	
	srand(time(NULL));	// Inicializa el generador de numeros aleatorios.

	//Crear Memoria Compartida
	shm_fd1 = shm_open("shm1", O_CREAT | O_RDWR, 0666);	// Array de ints, representa el mostrador.
	shm_fd2 = shm_open("shm2", O_CREAT | O_RDWR, 0666);	// Indice del array
	shm_fd3 = shm_open("shm3", O_CREAT | O_RDWR, 0666);	// Condicion de FIN

	//Configurar el tamaño de la memoria compartida
	size=CANT*sizeof(int);
	ftruncate(shm_fd1, size);
	ftruncate(shm_fd2, sizeof(int));
	ftruncate(shm_fd3, sizeof(int));

	// Mapear la memoria compartida a la memoria del proceso
	most = (int(*)[12]) mmap(0,size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd1, 0);	// Mostrador, array de int
	if (most == MAP_FAILED) {
		printf("Falla al mapear\n");
		exit(-1);
	}
	indice = (int*) mmap(0,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd2, 0); 	//Indice del array
	if (indice == MAP_FAILED) {
		printf("Falla al mapear\n");
		exit(-1);
	}
	*indice=0;

	FIN = (int*) mmap(0,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd3, 0);	// Condicion de fin.
	if (FIN == MAP_FAILED) {
		printf("Falla al mapear\n");
		exit(-1);
	}
	*FIN=0;

	printf("Creada la memoria compartida\n");

	sem_unlink("/sem.txt");	
	sem_unlink("/sem1.txt");	
	sem_unlink("/sem2.txt");	

	sem_most=sem_open("/sem.txt", O_CREAT, 644, 1);		// Protege mostrador, empieza valiendo 1 (verde)
	sem_mozo=sem_open("/sem1.txt", O_CREAT, 644, 0);	// Cuenta platos en el mostrador. Empieza con el most. vacio	
	sem_coc =sem_open("/sem2.txt", O_CREAT, 644, 12);	// Cuenta espacios libres, Empieza valiendo 12 (most. vacio)

	inicializa_mostrador(most);
	imprime_mostrador(most);
	for(i=0;i<MOZOS;i++){					// Crea mozos
		pid=fork();
		if(pid==0){
			printf("Creado el mozo %d    pid %d\n",i,getpid());
			mozo(sem_coc, sem_most,sem_mozo, indice, most,i);
			exit(0);
		}
	}
	for(i=0;i<COCINEROS;i++){				// Crea cocineros.
		pid=fork();
		if(pid==0){
			printf("Creando el cocinero %d   pid %d\n",i,getpid());
			cocinero(sem_coc, sem_most,sem_mozo,indice,most,i);
			exit(0);
		}
	}
	// Al finalizar:
	for(i=0;i<COCINEROS+MOZOS; i++){
		pid=wait(NULL);
		printf("Hijo  %d termino\n",pid);
	}
	imprime_mostrador(most);
	printf("FIN\n");
}

