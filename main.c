#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printByteInBinary(unsigned char byte) {
  for (int i = 7; i >= 0; i--) {
    printf("%d", (byte >> i) & 1);
  }
}

int main() {
  char ipAddress[16];
  struct in_addr ipAddr;
  unsigned char bytes[4];
  printf("Entrez une adresse IP (au format a.b.c.d) : ");
  scanf("%15s", ipAddress);
  if (inet_pton(AF_INET, ipAddress, &ipAddr) != 1) {
    fprintf(stderr, "Adresse IP invalide.\n");
    return 1;
  }
  memcpy(bytes, &ipAddr.s_addr, 4);
  printf("Adresse IP en binaire :\n");
  for (int i = 0; i < 4; i++) {
    printByteInBinary(bytes[i]);
    if (i < 3) {
      printf(".");
    }
  }
  printf("\n");

  return 0;
}
