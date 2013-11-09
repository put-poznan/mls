#ifndef _LISTERS_PARSE_H
#define _LISTERS_PARSE_H

#include <dirent.h>

#include "option_parse.h"
#include "printers.h"

typedef void (*lister_t)(struct dirent **, int, formatter_t, options);

void normal(struct dirent **namelist, int count, formatter_t, options);
void reverse(struct dirent **namelist, int count, formatter_t, options);

#endif /* _LISTERS_H */
