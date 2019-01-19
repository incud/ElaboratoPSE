#include <iostream>
#include <fstream>
#include <stdint.h>

#include "xtea.h"

/**********************************************************************

     eXtended Tiny Encryption Algorithm (XTEA)
        algorithm:        en.wikipedia.org/wiki/XTEA
        course:           Progettazione di Sistemi Embedded (2018-19)
        code provided by: Sara Vinco

**********************************************************************/

using namespace std;

void logo(){
  printf("\n     (((       \n");
  printf("     ((((     XTEA - eXtended Tiny Encryption Algorithm\n");
  printf("     ))))       * Design of Embedded Systems Course\n");
  printf("  _ .----.      * 2018-2019\n");
  printf("  ( |`---'|     \n");
  printf("    |     |\n");
  printf("   : .___, :\n");
  printf("    `-----'\n\n\n");

}

int main(int argc, char *argv[])
{
  uint32_t word0, word1, k0, k1, k2, k3;
  bool mode;
  uint32_t result0, result1;

  logo();

  mode = 0;
  word0 = 0x12345678;
  word1 = 0x9abcdeff;
  k0 = 0x6a1d78c8;
  k1 = 0x8c86d67f;
  k2 = 0x2a65bfbe;
  k3 = 0xb4bd6e46;
  xtea(word0, word1, k0, k1, k2, k3, mode, &result0, &result1);
  printf("First invocation: \n");
  printf("   - the encryption of %x and %x \n", word0, word1);
  printf("   - with key %x%x%x%x \n", k0, k1, k2, k3);
  printf("is: %x, %x \n\n", result0, result1);
  if((result0 != 0x99bbb92b) || (result1 != 0x3ebd1644))
    printf("Wrong result!");

  printf("Second invocation: \n");
  mode = 1; //decryption

  word0 = result0;
  word1 = result1;

  k0 = 0x6a1d78c8;
  k1 = 0x8c86d67f;
  k2 = 0x2a65bfbe;
  k3 = 0xb4bd6e46;

  xtea(word0, word1, k0, k1, k2, k3, mode, &result0, &result1);
  printf("   - the decryption of %x and %x \n", word0, word1);
  printf("   - with key %x%x%x%x \n", k0, k1, k2, k3);
  printf("is: %x, %x \n\n", result0, result1);

  if((result0 != 0x12345678) || (result1 != 0x9abcdeff))
    printf("Wrong result!");

  printf("Done!!\n");
  return(0);

}
