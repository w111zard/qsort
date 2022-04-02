int str_len(char *str) {
  char *end;

  for (end = str; *end; ++end)
    ;

  return end - str;
}

void str_copy(const char *from, char *to) {
  while ( (*to++ = *from++) )
    ;
}

int str_cmp(char *s, char *t) {
  for ( ; *s == *t; ++s, ++t)
    if (*s == '\0')
      return 0;

  return *s - *t;
}
