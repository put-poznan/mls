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

#include "listers.h"

#include <stdlib.h>

void normal(struct dirent **namelist, int count, formatter_t f, options o) {
  int i;

  for (i = 0; i < count; i++) {
    f(namelist[i], o);
    free(namelist[i]);
  }
}

void reverse(struct dirent **namelist, int count, formatter_t f, options o) {
  int i;

  for (i = count - 1; i >= 0; i--) {
    f(namelist[i], o);
    free(namelist[i]);
  }
}
