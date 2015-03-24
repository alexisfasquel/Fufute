#include "console.h"

// Spicing thing up to play a bit with linking issues and function pointer

typedef struct routine {
  void* funcptr;
  const char name[10];
} routine;


#define RT_NUM 3

extern int concurrency_issue();
extern int concurrency_solved();
extern int relock();

routine routines[RT_NUM] =
{
  {concurrency_issue, "issue"},
  {concurrency_solved, "solution"},
  {relock, "relock"}
};

void help() {
  int i = 0;
  info("Arguments available:");
  for(; i < RT_NUM; i++) {
    info("%s", routines[i].name);
  }
}

int main(int argc, char *argv[])
{
  int (*func) ();
  int i = 0;

  if(argc != 2) {
    help();
  } else {
    for (; i < RT_NUM; i++) {
      if (strcmp(argv[1], routines[i].name) == 0) {
        func = routines[i].funcptr;
        func();
        return 1;
      }
    }
    help();
  }
}
