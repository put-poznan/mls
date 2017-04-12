/*
 * This file is part of mls.
 *
 * mls is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * mls is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mls; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

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
  int dirs_count, opts_count;
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
