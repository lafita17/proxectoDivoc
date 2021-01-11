#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "inout.h"
#include "database.h"

void stripe (char s,int cantidad){
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
  char d,seg[256],mas[256];
  int b,okk;
  okk=0;
 do{
    fprintf (stdout,"%s ",salir);
    fgets(seg,sizeof(seg),stdin);
    b= sscanf(seg, "%c%s",&d,mas);
    if(b==1){
      if((tolower(d)=='y')||(tolower(d)=='n')){
	okk=1;}
      else{
	continue;
      }
    }
 }while(okk!=1);
   
  if (tolower(d)=='y') {
    return 1;}
  else {
    return 0;}
}

void get_string(char *mensaje,int min,int max, char *dir_cadena){
  char cadena[256],basura[256],otra[256];
  int val,ok;
  ok=0;
  do{
    fprintf(stdout,"%s (%i,%i char): ",mensaje,min,max);
    fgets(cadena,sizeof(cadena),stdin);
    val= sscanf(cadena, "%s%s",otra,basura);
    if (val==1){
      if ((strlen(otra)>max)||(strlen(otra)<min)){
	 continue;}
      else{
	ok=1;}
    }
  }while (ok!=1);
      strcpy (dir_cadena, otra);

    
    return;
}

int get_integer(char *mensaje,int min,int max){
  int y,ok1,valor;
  char linea[256],extra[256];
  ok1=0;
  do {fprintf(stdout,"%s [%i-%i]: ",mensaje,min,max);
    fgets(linea,sizeof(linea),stdin);
    y= sscanf(linea, "%d%s",&valor,extra);
    if (y==1){
      if ((valor>max)||(valor<min)){
	continue;}
      else{
	ok1=1;}
    }
  }while (ok1!=1);
  return valor;
}

char get_character(char *mensaje,char *comprobacion){
  char q[256],extra[256];
  char z;
  int ok2,val2;
  ok2=0;
  do {
    printf("%s (%s): ",mensaje,comprobacion);
  fgets(q,sizeof(q),stdin);
  val2= sscanf(q, "%c%s",&z,extra);
    if (val2==1){
       if(strchr(comprobacion,toupper(z)) == NULL) {
    continue;}
       else ok2=1;
    }
  }while(ok2!=1);
  return toupper(z);
  
}


void display_patient(PPACIENTE tabla){
  fprintf(stdout," >%s;%s;%i;%i;%i;%c\n",tabla->nombre,tabla->DNI,tabla->edad,tabla->fiebre,tabla->tos,tabla->sintoma);

  return;
}

int verify_DNI(char *cadena){
  int indice,conv,i,v;
  char palabra[50] = "TRWAGMYFPDXBNJZSQVHLCKE";
  for(i=0;i<8;i++){
   v= isdigit(cadena[i]);
  if (v==0){
    return 0;}
  }  
  conv=atoi(cadena);
  indice = conv % 23;
  if (cadena[8]==palabra[indice]){
    return 1;}
    else return 0;
}
				    

				    
  
