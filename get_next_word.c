#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 1

int ft_strlen(char *str) {
  int i = 0;
  while (str[i]) {
    i++;
  }
  return (i);
}

int ft_strchar(char *str, char *chars) {
  while (*str) {
    while (*chars) {
      if (*str == *chars)
        return (0);
      chars++;
    }
    str++;
  }
  return (1);
}

char *ft_strjoin(char *s1, char *s2) {
  char *str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
  while (*s1) {
    *str++ = *s1++;
  }
  while (*s2) {
    *str++ = *s2++;
  }
  *str = 0;
  return (str);
}

char *get_next_word(int fd) {
  static char buf[BUFFER + 1];
  char *word;
  char *line;
  int i = 0;

  while (ft_strchar(line, " \n\t") && (i = read(fd, buf, BUFFER))) {
    buf[i] = 0;
    word = ft_strjoin(word, buf);
  }

  printf("%s\n", word);
  return (word);
}
