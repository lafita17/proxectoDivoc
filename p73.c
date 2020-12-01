#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define P_REGISTER 'R'
#define P_SEARCH 'S'
#define P_DISCHARGE 'D'
#define P_LIST 'L'
#define P_EXIT 'X'
#define CAR '+'
#define LIN 60
#define NOM "DIVOC_"

void headline(char *, char *);
int yes_or_no(char *);
void stripe(char *);

int p_register();
int p_search();
int p_discharge();
int p_list();

int main() {

	char t, confirmacion;
	int i, numero, salir=0;
	
	stripe("*");
	headline("pirola", "*");
	stripe("*");

	while(salir==0) {

	printf("\nR) Register a patient\nS) Search for a patient\nD) Discharge a patient\nL) List a patient\nX) Exit the program\n\nChoose an option:\n");
	fscanf(stdin," %c", &t);
	printf("\n");
    t=toupper(t);

	switch(t) {
		case P_REGISTER:
			p_register();
			break;
		case P_SEARCH:
			p_search();
			break;
		case P_DISCHARGE:
			p_discharge();
			break;
		case P_LIST:
			p_list();
			break;
		case P_EXIT:
			salir=yes_or_no("queres sair?");
			break;

	} 
	
}	return 0;
}

void headline(char *titulo, char *delim) {
	int numero;
	numero=(LIN-2-strlen(titulo))/2;
	printf("%s", delim);
	for (int i = 0; i < numero; i++) printf(" ");
	for ( ; *titulo!= '\0'; titulo++) printf ("%c", *titulo);
	
	for (int i = 0; i < numero; i++) printf(" ");
		printf("%s\n", delim);
	return;
}

int yes_or_no(char *frase) {
	int t, salir=0;
	char c;
	
	while (salir != 1) {
		printf("%s\n", frase);
		scanf(" %c", &c);

			if ((c=='y')||(c=='Y')) {
				salir=1;
			}
			if ((c=='n')||(c=='N')){
				salir=0;
			}
	}

			return salir;
}

void stripe(char *linea) {
	char a;
	for (int i = 0; i < 60; i++) {
		printf("%s", linea);}
		printf("\n");
}

int p_register() {
	printf("register\n");
	return 0;
}

int p_search() {
	printf("search\n");
	return 0;
}

int p_discharge() {
	printf("discharge\n");
	return 0;
}

int p_list() {
	printf("list\n");
	return 0;;
}