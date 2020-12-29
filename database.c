#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "inout.h"
#include "database.h"
PPACIENTE p_register(PPACIENTE pPac){
  char la_cadena[25];
  int comp;

  printf("Register\n");
  PPACIENTE pAux = (PPACIENTE)malloc(sizeof(PACIENTE));

  get_string("Name",1,24,pAux->nombre);
  if (pPac!=NULL)
  {
    pAux->num=pPac->num+1;
    pPac->sig=pAux;
  }
  else
  {
    pAux->num=1;
    pAux->sig=NULL;
  }
  do{
    get_string("DNI",9,9, pAux->DNI);
    comp=verify_DNI(pAux->DNI);}
  while(comp==0);
  pAux->edad=get_integer("Date",1900,2020);
  pAux->fiebre=yes_or_no("Fever?");
  pAux->tos=yes_or_no("Cough?");
  /*falta sintoma que non vai get_char*/
  printf("New patient:");
  /*falta display patient*/


  return pAux;
}

int p_search(PPACIENTE p){
  char dni[10];
  PPACIENTE pAux;
  pAux=p;
  fprintf(stdout,"Search\n\n");

  if (p==NULL)
  {
    printf("No patients yet\n");
  }
  else
  {
    get_string("DNI",9,9,dni);
    while(pAux!=NULL){
      if(strcmp(pAux->DNI,dni)==0) {
      printf("Patient data:\n");
      /*displaypatient*/
      pAux=pAux->sig;}
      else printf("Unknown patient\n");
    }

  }

  return 0;
}

int p_discharge(){
  fprintf(stdout,"Discharge\n\n");
  return 0;
}

int p_list(struct unPaciente *tabla, int numero){
  int i;
  fprintf(stdout,"Tabla de pacientes:\n");
  for (i=0;i<numero;i++){
    fprintf(stdout,"%s:%i\n",tabla[i].nombre,tabla[i].edad);
  }
  return 0;
}
int p_mark(){
  fprintf(stdout,"Mark\n\n");
  return 0;
}
