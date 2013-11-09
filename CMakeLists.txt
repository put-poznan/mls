cmake_minimum_required (VERSION 2.6)
project (mls)

add_executable (
  bin/mls

  src/main.c
  src/option_parse.c
  src/printers.c
  src/listers.c
  src/filters.c
  )
