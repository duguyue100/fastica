FILE(REMOVE_RECURSE
  "lib/libicalib.pdb"
  "lib/libicalib.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/icalib.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
