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
        printf("Usage: %s [-alr] [directory]\n", argv[0]);
        exit(1);
    }
  }

  return optind;
}
