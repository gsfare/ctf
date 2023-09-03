#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void FUN_00010080_simplified(uint8_t *input_array,const char *user_input_pointer, int modulus) {
  int i;
  uint8_t temp=0;
  uint8_t char_in_input_array;
  
  for(i=0 ; i<0x100 ; ++i) {
    input_array[i] = i;
  }

  for(i=0 ; i<256 ; ++i) {
    temp += user_input_pointer[i % modulus] + input_array[i];
    
    char_in_input_array = input_array[i];
    input_array[i] = input_array[temp];
    input_array[temp] = char_in_input_array;
  }

  return;
}

uint8_t FUN_000100d2_simplified(uint8_t *input_array) {
  uint8_t bVar1;
  uint8_t bVar2;

  input_array[256] += 1;
  bVar1 = input_array[input_array[256]];

  input_array[257] += input_array[input_array[256]];
  bVar2 = input_array[input_array[257]];
  
  input_array[input_array[256]] = bVar2;
  input_array[input_array[257]] = bVar1;

  return input_array[(uint8_t)((int)(bVar1 + bVar2))];
}

void main_app_functionality(uint8_t *user_input, uint8_t *flag_output) {
  uint8_t abStack_138 [272];
  memset(abStack_138, 0, sizeof(uint8_t)*272);
  int i=0;

  FUN_00010080_simplified(abStack_138, user_input, 8);

  i=0;
  do {
    flag_output[i] = user_input[i] ^ FUN_000100d2_simplified(abStack_138);
    ++i;
  } while (user_input[i] != '\0');
}

int main(int argc, char *argv[]) {
  int i=0, j=0;
  uint8_t user_input[] = "picoCTF{xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx}";
  char allowed_characters[] = " !\"#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_abcdefghijklmnopqrstuvwxyz{|}";
  uint8_t flag_bytes[] = {0xc5, 0x75, 0x95, 0xa5, 0x81, 0x80, 0xf3, 0x44,
                       0xf1, 0x99, 0x34, 0x81, 0x3a, 0x5f, 0x50, 0x93,
                       0x67, 0xee, 0x12, 0x0c, 0x15, 0x3a, 0xda, 0x1c,
                       0x6f, 0x50, 0x80, 0x49, 0x63, 0xf2, 0x36, 0xd3,
                       0x93, 0x64, 0x46, 0x63, 0x84, 0xb5, 0x3a, 0x5a,
                       0x9c, 0x3e, 0x40, 0xf5, 0x19, 0x20, 0x7f, 0x08,
                       0x00, 0x48, 0x0a, 0x03, 0x00 };
  uint8_t flag_bytes_out[53];
  memset(flag_bytes_out, 0, sizeof(uint8_t)*53);


  for(i=0 ; i<52 ; ++i) {
    for(j=0; j<strlen(allowed_characters) ; ++j) {
      user_input[i] = allowed_characters[j];
      printf("%s\n", user_input);
      main_app_functionality(user_input, flag_bytes_out);
      if(flag_bytes_out[i] == flag_bytes[i]) {
        break;
      }
    }
    if(j==strlen(allowed_characters))
      printf("FAILED, index in string - %d - 0x%02x 0x%02x\n", i, flag_bytes_out[i], flag_bytes[i]);

    printf("%s\n", user_input);
  }

  return(EXIT_SUCCESS);    
}