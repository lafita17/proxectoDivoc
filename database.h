
 struct unPaciente{
  char nombre[25];
  char DNI[10];
  int edad;
  int fiebre;
  int tos;
  char sintoma;
  int num;
  struct unPaciente *sig;
 };
typedef struct unPaciente PACIENTE;
typedef struct unPaciente * PPACIENTE;
PPACIENTE p_register();
int p_search();
PPACIENTE p_discharge();
int p_list();
int p_mark();
