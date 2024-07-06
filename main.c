#include "RegexEngine/regex_engine.h"
#include <stdio.h>
#include <string.h>
#define LINESIZE 4095
void info() {

  fprintf(stderr, "Please provide a regular expression and file name eg: "
                  "./main \"ab*|c\" main.c \nRun ./main -h to list help");
}
int main(int argc, char *argv[]) {
  // settings
  int lineNumbers = 0, caseInsensitive = 0;

  if (argc == 1) {
    info();
    return 1;
  }

  if (argc > 5) {
    fprintf(stderr, "Too many arguments.\n");
    info();
    return 1;
  }

  char *input[2], **tmp;
  tmp = input;
  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-h")) {
      printf("Options:\n-i : case insensitivity\n-c : line numbers\n");
      return 0;
    } else if (!strcmp(argv[i], "-c")) {
      lineNumbers = 1;
    } else if (!strcmp(argv[i], "-i")) {
      caseInsensitive = 1;
    } else {
      // extract the regex, then extract the file path.
      *tmp++ = argv[i];
    }
  }

  char *regex = input[0], *file = input[1], line[LINESIZE];
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
      if (match(token)) {
        if (lineNumbers) {
          printf("%d: %s", i + 1, line);
        } else {
          printf("%s", line);
        }
        break;
      }
      // increment search through line
      token = strtok(NULL, delim);
    }
  }

  return 0;
}
