#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t undefined8;

#if 0
int main(int argc, char *argv[]) {
  int i=0;
  char local_58[72];

  memset(local_58,0,0x40);

  for (i = 0; i < 4; i = i + 1) {
    strncat(local_58, argv[1] + (long)(i << 2) + 1,4);
  }

  printf("\n%s\n%s\n", argv[1], local_58);

  return(EXIT_SUCCESS);
}
#endif

int main(int argc, char *argv[]) {
  size_t input_password_length;
  void *__ptr;
  undefined8 *puVar1;
  long in_FS_OFFSET;
  int i;
  int local_fc;
  int local_e8 [4];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  char input_password [65];
  char local_58 [72];
  long local_10;
  
  char string[]="WEjMaLpGkmnnjOVp6pdeliGRslxzecvM";

  // local_10 = *(long *)(in_FS_OFFSET + 0x28);
  setbuf(stdout,(char *)0x0);
  local_c8 = 0x57456a4d614c7047;
  local_c0 = 0x6b6d6e6e6a4f5670;
  local_b8 = 0x367064656c694752;
  local_b0 = 0x736c787a6563764d;
  local_e8[0] = 8;
  local_e8[1] = 2;
  local_e8[2] = 7;
  local_e8[3] = 1;
  memset(input_password + 1,0,0x40);
  memset(local_58,0,0x40);
  printf("Password: ");
  fgets(input_password + 1,0x40,stdin);
  input_password_length = strlen(input_password + 1);
  input_password[input_password_length] = '\0';
  for (i = 0; i < 4; i = i + 1) {
    strncat(local_58,input_password + (long)(i << 2) + 1,4);
    strncat(local_58,string + (long)(i << 3),8);
  }

  printf("%s\n%s\n", input_password, local_58);
}