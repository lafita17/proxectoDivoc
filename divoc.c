#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "inout.h"
#include "database.h"

int main () {
  char c,texto[256];
  int x;
  FILE *fichero;

  PPACIENTE inicio=NULL;
  PPACIENTE pAux=NULL;
  

  if((fichero=fopen("patients.txt","r"))!=NULL)
  {
    while(fgets(texto,sizeof(texto),fichero)!=NULL)
    {
      PPACIENTE nuevo=(PPACIENTE)malloc(sizeof(PACIENTE));
      sscanf(texto,"%s %s %d %d %d %c",nuevo->nombre,nuevo->DNI,&nuevo->edad,&nuevo->fiebre,&nuevo->tos,&nuevo->sintoma);
      nuevo->sig=NULL;
      if (inicio==NULL)
      {
      inicio=nuevo;
      }
      else 
      {
        pAux=inicio;
        while(pAux->sig!=NULL) pAux=pAux->sig;
        pAux->sig=nuevo;
      }
    }
    fclose(fichero);
  }	
    
  stripe('-',50);
  headline ("DIVOC_", '|',50);
  stripe('-',50);
  printf("\n");

 do { 
   fprintf (stdout,"\nR) Register a patient\n");
  fprintf (stdout,"S) Search for a patient\n");
  fprintf (stdout,"D) Discharge a patient\n");
  fprintf (stdout,"L) List patients by age\n");
  fprintf (stdout,"P) Mark positive\n\n");
  fprintf (stdout,"X) Exit the program\n");

  c=get_character("Choose an option","RSDLPX");

  switch (toupper(c)){

  case 'R':
    inicio=p_register(inicio);

    break;
  case 'S':
    p_search(inicio);
    break;
  case 'D':
    inicio=p_discharge(inicio);
    
    break;
  case 'L':
    p_list(inicio);
    break;
  case 'X':
    printf("\nExit\n");
    x=yes_or_no("Are you sure you want to exit the program?(y/n):");
    if (x==1){
      fichero = fopen("patients.txt", "w");
      if (fichero!=NULL)
      {
        pAux=inicio;
        while(pAux!=NULL)
        {
          fprintf(fichero, "%s %s %d %d %d %c\n",pAux->nombre,pAux->DNI,pAux->edad,pAux->fiebre,pAux->tos,pAux->sintoma);
          pAux=pAux->sig;
        }
      }
      fclose(fichero);
    }
    break;
  case 'P':
    p_mark(inicio);
    break;
  default:
    break;
  }
 }while (x!=1);
  return 0;
}






