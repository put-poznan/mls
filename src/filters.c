#include "filters.h"

int skip_dotfiles(const struct dirent * node) {
  return node->d_name[0] != '.';
}
