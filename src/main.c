#include <stdio.h>
#include <stdlib.h>

#include <dirent.h>

#include "option_parse.h"
#include "printers.h"
#include "listers.h"
#include "filters.h"

typedef int (*sorter_t)(struct dirent **, struct dirent **);

int main(int argc, char* argv[]) {
  struct dirent **namelist;
  int dirs_count, opts_count, i;
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
  opts.path = ".";

  if (opts_count < argc) {
    opts.path = argv[opts_count];
  }

  dirs_count = scandir(opts.path, &namelist, filters[opts.all], alphasort);

  if (dirs_count < 0) {
    perror("mls");

    return 1;
  } else {
    listers[opts.reverse](
        namelist,
        dirs_count,
        formatters[opts.long_format],
        opts
        );
    free(namelist);
  }

  return 0;
}
