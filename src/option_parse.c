#include "option_parse.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int parse_opts(int argc, char *argv[], options* opts) {
  int c = 0;

  memset(opts, 0, sizeof(*opts));

  while ((c = getopt(argc, argv, "alr")) != -1) {
    switch (c) {
      case 'a':
        opts->all = 1;
        break;
      case 'l':
        opts->long_format = 1;
        break;
      case 'r':
        opts->reverse = 1;
        break;
      default:
        printf("Usage: %s [-alr] [directory]", argv[0]);
        exit(1);
    }
  }

  return optind;
}
