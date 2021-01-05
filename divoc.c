#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inout.h"
#include "database.h"

int main () {
  char c;
  int x;
  
  stripe('-',60);
  headline ("DIVOC_", '|',60);
  stripe('-',60);

  PPACIENTE inicio=NULL;
  PPACIENTE pAux=NULL;
  
 do { fprintf (stdout,"R) Register a patient\n");
  fprintf (stdout,"S) Search for a patient\n");
  fprintf (stdout,"D) Discharge a patient\n");
  fprintf (stdout,"L) List patients by age\n");
  fprintf (stdout,"P) Mark positive\n");
  fprintf (stdout,"X) Exit the program\n\n");

  fprintf (stdout,"Choose an option:  (RSDLPX)\n");
  fscanf (stdin," %s",&c);

  switch (toupper(c)){

  case 'R':
    pAux=p_register(pAux);
    if(pAux->num==1) inicio=pAux;
    break;
  case 'S':
    p_search(inicio);
    break;
  case 'D':
    inicio=p_discharge(inicio);
    pAux=inicio;
    break;
  case 'L':
    p_list(inicio);
    break;
  case 'X':
    x=yes_or_no("Seguro que quieres salir del programa?\n");
    break;
  case 'P':
    p_mark(inicio);
    break;
  default:
    fprintf(stdout,"Has seleccionado una opcion no valida\n");
    break;
  }
 }while (x!=1);
  return 0;
}






