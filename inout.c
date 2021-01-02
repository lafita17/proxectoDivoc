#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "inout.h"
#include "database.h"

void strype (char s,int cantidad){
  int j;
   for(j=0;j<cantidad;j++){
     fprintf(stdout,"%c",s);}
    fprintf(stdout,"\n");
   return;
}

void headline (char cadena[50],char c,int cantidad){
  int i,z,a;
  a=((cantidad-2)-strlen(cadena))/2;
  fprintf(stdout,"%c",c);
  for(i=0;i<a;i++){
      fprintf(stdout," ");}
  fprintf(stdout,"%s",cadena);
  for(z=0;z<a;z++){
      fprintf(stdout," ");}
  fprintf(stdout,"%c\n",c);
  return;
}

int yes_or_no(char salir[80]){
  char d;
 do{
    fprintf (stdout,"%s",salir);
    fscanf(stdin," %s",&d);
       
 } while(((tolower(d)=='y') || (tolower(d)=='n'))!=1);
  if (tolower(d)=='y') {
    return 1;}
  else {
    return 0;}
}

void get_string(char *mensaje,int min,int max, char *dir_cadena){
  char cadena[80];
  do{  fprintf(stdout,"%s (%i,%i char):\n",mensaje,min,max);
    fscanf (stdin," %s",cadena);
    if ((strlen(cadena)>max)||(strlen(cadena)<min))
      continue; 
    else {
      strcpy (dir_cadena, cadena);}
  }while(((strlen(cadena)>max)||(strlen(cadena)<min))==1);

    
    return;
}

int get_integer(char *mensaje,int min,int max){
  int valor;
  do {fprintf(stdout,"%s [%i-%i]:\n",mensaje,min,max);
  fscanf(stdin,"%d",&valor);
  if (valor < min){
    continue;}
  else if (valor > max){
    continue;}
  }while (((valor<min)||(valor>max))==1);
  return valor;
}

char get_character(char *mensaje,char *comprobacion){
  char q[60];
  int z;
  z=0;
  while (z!=1) {
    fprintf(stdout," %s (%s):\n",mensaje,comprobacion);
  fgets(q,sizeof(q),stdin);
  if (strlen(q)!=2){
    continue;}
  else{
    if(strchr(comprobacion,toupper(*q)) == NULL) {
    continue;}
    else z=1;
  }
  }
  return toupper(*q);
  
}


void display_patient(PPACIENTE tabla){
  fprintf(stdout," >%s;%s;%i;%i;%i;%c\n",tabla->nombre,tabla->DNI,tabla->edad,tabla->fiebre,tabla->tos,tabla->sintoma);

  return;
}

int verify_DNI(char *cadena){
  int indice,conv;
  char palabra[50] = "TRWAGMYFPDXBNJZSQVHLCKE";
  conv = atoi(cadena);
  indice = conv % 23;
  if (cadena[8]==palabra[indice]){
    return 1;}
    else return 0;
}
				    

				    
  
