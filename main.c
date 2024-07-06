#include "RegexEngine/regex_engine.h"
#include <stdio.h>
#include <string.h>
#define LINESIZE 4095
int main(int argc, char *argv[]) {
  // first input will be regex
  // second input will be file
  if (argc < 2) {
    fprintf(stderr, "Please provide a regular expression and file name eg: "
                    "./main \"ab*|c\" main.c \n");
    return 1;
  }

  char *regex = argv[1], *file = argv[2], line[LINESIZE];
  compileRegex(regex);

  FILE *fptr = fopen(file, "r"), *ptr;
  ptr = fptr;

  if (fptr == NULL) {
    fprintf(stderr, "Unable to open file.\n");
    return 1;
  }

  for (int i = 0; !feof(ptr); i++) {
    fgets(line, sizeof(line), ptr);

    // creates temp line to search through as strtok adds delimeters to arr
    char tempLine[LINESIZE];
    memcpy(tempLine, line, sizeof(line));

    char delim[] = " ,.![]()*+-/\\|:<>?%$#@^&{}`~\"_'";
    char *token = strtok(tempLine, delim);

    // look through each word of the line
    while (token != NULL) {
      // if word is matched then get then stop matching
      // LLLLLLLL
      // printf("token : %s\n", token);
      if (match(token)) {
        printf("%d: %s", i + 1, line);
        break;
      }
      // increment search through line
      token = strtok(NULL, delim);
    }
  }

  return 0;
}
