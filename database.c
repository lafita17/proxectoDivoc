#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "inout.h"
#include "database.h"
PPACIENTE p_register(PPACIENTE pPac){
  int comp;
 printf ("\n");
  printf("Register\n");
  PPACIENTE pAux = (PPACIENTE)malloc(sizeof(PACIENTE));
  PPACIENTE ultimo = pPac;
  

  get_string("Name",1,24,pAux->nombre);

  do
  {
    get_string("DNI",9,9, pAux->DNI);
    comp=verify_DNI(pAux->DNI);
    if (comp==0){
      printf("\nInvalid DNI");}
  }
  while(comp==0);
  pAux->edad=get_integer("Date",1900,2020);
  pAux->fiebre=yes_or_no("Fever (y/n):");
  pAux->tos=yes_or_no("Cough (y/n):");
  pAux->sintoma=get_character("Symptom", "FSTMN");
  printf("\nNew patient:\n");
  display_patient(pAux);
  printf("\n");
  pAux->sig=NULL;
  if (pPac==NULL)
  {
    pPac=pAux;
    return pPac;
  }
  else 
  {
    while(ultimo->sig!=NULL) ultimo=ultimo->sig;
    ultimo->sig=pAux;

  }

  return pPac;
}

int p_search(PPACIENTE p){
  char dni[10];
  PPACIENTE pAux;
  int z;
  pAux=p;
   printf ("\n");
  fprintf(stdout,"Search\n");

  if (p==NULL)
  {
    printf("\nNo patients yet\n");
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
      printf("\nPatient data:\n");
      display_patient(pAux);
    }
    else printf("\nUnknown patient\n\n");
       
  }

  return 0;
}

PPACIENTE p_discharge(PPACIENTE pac){
  char dni[10];
  int u = 0;
  PPACIENTE pAux;
  PPACIENTE temp = NULL;  // punteiro a previo a borrar
  pAux=pac;
   printf ("\n");
  fprintf(stdout,"Discharge\n");
  if (pac==NULL)
  {
    printf("\nNo patients yet\n");
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
      printf("\nDischarged patient\n");
    }
    else
    {
      printf("\nUnknown patient\n\n");
    }
  }
  return pac;
}

int p_list(PPACIENTE pcc){
  int i;
  PPACIENTE pAux;
  pAux=pcc;
   printf ("\n");
  fprintf(stdout,"List\n");
  if (pcc==NULL)
  {
    printf("\nNo patients yet\n");
  }
   else
  {
    i=get_integer("Date",1900,2020);
    fprintf(stdout,"\nPatients born before %d:\n",i);
    while (pAux != NULL)
    {
      if (pAux->edad <= i)
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
  fprintf(stdout,"\nPositives\n");
  if (p==NULL)
  {
    printf("\nNo patients yet\n");
  }
  else
  { printf("\nPositive patients:\n");
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
