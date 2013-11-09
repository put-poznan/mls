#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <dirent.h>

#include "option_parse.h"
#include "printers.h"
#include "listers.h"
#include "filters.h"

typedef int (*sorter_t)(struct dirent **, struct dirent **);

int main(int argc, char* argv[]) {
  struct dirent **namelist;
  int dirs_count, opts_count, i;
  const char *dir = ".";
  options opts;

  formatter_t formatters[] = {
    default_format,
    long_format
  };

  lister_t listers[] = {
    normal,
    reverse
  };

  filter_t filters[] = {
    skip_dotfiles,
    NULL
  };

  opts_count = parse_opts(argc, argv, &opts);

  if (opts_count < argc) {
    dir = argv[1];
  }

  dirs_count = scandir(dir, &namelist, filters[opts.all], alphasort);

  if (dirs_count < 0) {
    perror("mls");
  } else {
    listers[opts.reverse](
        namelist,
        dirs_count,
        formatters[opts.long_format]
        );
    free(namelist);
  }
}
