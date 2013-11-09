#ifndef _PRINTERS_H
#define _PRINTERS_H

#include <dirent.h>

#include "option_parse.h"

typedef void (*formatter_t)(struct dirent *, options);

void default_format(struct dirent *name, options);
void long_format(struct dirent *name, options);

#endif /* _PRINTERS_H */
