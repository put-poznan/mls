#include "listers.h"

#include <stdlib.h>

void normal(struct dirent **namelist, int count, formatter_t f) {
  int i;

  for (i = 0; i < count; i++) {
    f(namelist[i]);
    free(namelist[i]);
  }
}

void reverse(struct dirent **namelist, int count, formatter_t f) {
  int i;

  for (i = count - 1; i >= 0; i--) {
    f(namelist[i]);
    free(namelist[i]);
  }
}
