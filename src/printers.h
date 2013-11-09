#ifndef _PRINTERS_H
#define _PRINTERS_H

#include <dirent.h>

typedef void (*formatter_t)(struct dirent *);

void default_format(struct dirent *name);
void long_format(struct dirent *name);

#endif /* _PRINTERS_H */
