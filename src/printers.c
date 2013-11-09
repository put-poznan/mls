#include "printers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>

char filetype(mode_t mode) {
  switch (mode & S_IFMT) {
    case S_IFSOCK: return 's';
    case S_IFLNK:  return 'l';
    case S_IFBLK:  return 'b';
    case S_IFDIR:  return 'd';
    case S_IFCHR:  return 'c';
    case S_IFIFO:  return 'f';
  }
  return '-';
}

char *filemode(mode_t mode, char buff[10]) {
  int i = 0, shift,  masked;
  for (i = shift = 0; i < 3; i++, shift = i * 3) {
    masked = mode & (07 << shift);

    buff[shift + 0] = (02 << shift) & masked ? 'r' : '-';
    buff[shift + 1] = (04 << shift) & masked ? 'w' : '-';
    buff[shift + 2] = (01 << shift) & masked ? 'x' : '-';
  }

  return buff;
}

void default_format(struct dirent *name, options _) {
  puts(name->d_name);
}

void long_format(struct dirent *name, options opts) {
  struct stat stats;
  struct passwd *user;
  struct group  *group;
  char perm[10] = {0}, time[100], *filepath;
  int filepath_l = 0;

  filepath_l = strlen(name->d_name) + strlen(opts.path);
  filepath = (char*)malloc(filepath_l + 10);

  strcpy(filepath, opts.path);
  strcat(filepath, "/");
  strcat(filepath, name->d_name);

  lstat(filepath, &stats);
  user = getpwuid(stats.st_uid);
  group = getgrgid(stats.st_gid);

  strftime(time, 99, "%m-%d %R", localtime(&stats.st_ctime));

  printf("%c%s %3d %s %s %5u %s %s\n",
      filetype(stats.st_mode),       /* filetype */
      filemode(stats.st_mode, perm), /* permissions */
      stats.st_nlink,                /* hard links */
      user->pw_name,                 /* user name */
      group->gr_name,                /* group name */
      stats.st_size,                 /* file size */
      time,                          /* change time */
      name->d_name                   /* file name */
      );
}
