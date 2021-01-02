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
  int z;
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
	z=1;}
      pAux=pAux->sig;}
    if (z==1){
      printf("Patient data:\n");
      /*displaypatient*/}
    else printf("Unknown patient\n");
       
  }

  return 0;
}

int p_discharge(PPACIENTE pac){
  char dni[10];
  int u;
  PPACIENTE pAux;
  pAux=pac;
  fprintf(stdout,"Discharge\n\n");
  if (pac==NULL)
  {
    printf("No patients yet\n");
  }
   else
  {
    get_string("DNI",9,9,dni);
    while(pAux!=NULL){
      if(strcmp(pAux->DNI,dni)==0) {
	u=1;}
      pAux=pAux->sig;
    }
    if (u==1){
    }
    else printf("Unknown patient\n");
  }
  return 0;
}

int p_list(PPACIENTE pcc){
  int i;
  PPACIENTE pAux;
  pAux=pcc;
  fprintf(stdout,"List\n");
  if (pcc==NULL)
  {
    printf("No patients yet\n");
  }
   else
  {
    i=get_integer("DATE",1900,2020);
    fprintf(stdout,"Patients born before %d:\n",i);
    while (pAux != NULL){
      if (*pAux->DNI <= i){
	display_patient(pAux);
	pAux=pAux->sig;}
      else
	pAux=pAux->sig;
    }
  }
  return 0;
}
int p_mark(){
  fprintf(stdout,"Mark\n\n");
  return 0;
}
