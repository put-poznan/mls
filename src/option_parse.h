#ifndef _OPTION_PARSE_H
#define _OPTION_PARSE_H

typedef struct options {
  int all;
  int long_format;
  int reverse;
  const char* path;
} options;

int parse_opts(int argc, char *argv[], options* opts);

#endif /* _OPTION_PARSE_H */
