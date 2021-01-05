#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "inout.h"
#include "database.h"
PPACIENTE p_register(PPACIENTE pPac){
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
  do
  {
    get_string("DNI",9,9, pAux->DNI);
    comp=verify_DNI(pAux->DNI);
  }
  while(comp==0);
  pAux->edad=get_integer("Date",1900,2020);
  pAux->fiebre=yes_or_no("Fever?");
  pAux->tos=yes_or_no("Cough?");
  pAux->sintoma=get_character("Symptom?", "FSTMN");
  printf("New patient:");
  display_patient(pAux);
  printf("\n");


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
    while(pAux!=NULL)
    {
      if(strcmp(pAux->DNI,dni)==0) 
      {
	     z=1;
       break;
      }
      else
      {
      pAux=pAux->sig;
      }
    }
    if (z==1)
    {
      printf("Patient data:\n");
      display_patient(pAux);
    }
    else printf("Unknown patient\n");
       
  }

  return 0;
}

PPACIENTE p_discharge(PPACIENTE pac){
  char dni[10];
  int u = 0;
  PPACIENTE pAux;
  PPACIENTE temp = NULL;  // punteiro a previo a borrar
  pAux=pac;
  fprintf(stdout,"Discharge\n\n");
  if (pac==NULL)
  {
    printf("No patients yet\n");
  }
  else
  {
    get_string("DNI",9,9,dni);
    while(pAux!=NULL)
    {
      if(strcmp(pAux->DNI,dni)==0) 
      {
        u=1;
        break;
      }
      else
      {
        temp=pAux;
        pAux=pAux->sig;
      }
    }
    if (u==1)
    {
      if (pAux==pac)
      {
         // é o primeiro así que actualiza o inicio
         pac=pAux->sig;
      }
      else
      {
         //non é o primeiro así que actualiza o elemento anterior
         temp->sig=pAux->sig;
      }
      free(pAux);
      printf("Patient deleted\n");
    }
    else
    {
      printf("Unknown patient\n");
    }
  }
  return pac;
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
    while (pAux != NULL)
    {
      if (*pAux->DNI <= i)
      {
	      display_patient(pAux);
	      pAux=pAux->sig;
      }
      else pAux=pAux->sig;
    }
  }
  return 0;
}


int p_mark(PPACIENTE p){
  PPACIENTE pAux;
  pAux=p;

  fprintf(stdout,"Positives\n");
  if (p==NULL)
  {
    printf("No patients yet\n");
  }
  else
  {
    while(pAux!=NULL)
    {
      if ((pAux->fiebre==0)||(pAux->tos==0)||(pAux->sintoma=='N'))
      {

        pAux=pAux->sig;
      }
      else 
      {
        display_patient(pAux);
        pAux=pAux->sig;
      }
    }
  }


  return 0;
}
