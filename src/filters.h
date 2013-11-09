#ifndef _FILTERS_H
#define _FILTERS_H

#include <dirent.h>

typedef int (*filter_t)(const struct dirent *);

int skip_dotfiles(const struct dirent *);

#endif /* _FILTERS_H */
