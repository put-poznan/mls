#ifndef _LISTERS_PARSE_H
#define _LISTERS_PARSE_H

#include <dirent.h>

#include "printers.h"

typedef void (*lister_t)(struct dirent **, int, formatter_t);

void normal(struct dirent **namelist, int count, formatter_t);
void reverse(struct dirent **namelist, int count, formatter_t);

#endif /* _LISTERS_H */
