FILE(REMOVE_RECURSE
  "lib/libicalib.so.pdb"
  "lib/libicalib.so.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/icalib.so.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
