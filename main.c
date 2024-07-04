#include "RegexEngine/regex_engine.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  // first input will be regex
  // second input will be file
  char *regex = argv[1];
  compileRegex(regex);

  return 0;
}
