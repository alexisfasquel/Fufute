#include <pthread.h>
#include "console.h"

void *thread_issue(void *arg)
{
    int i = 0;
    info("Speaking");
    for (; i < 10; i++) {
      usleep(10);
      info("%i", i);
    }
}

int concurrency_issue()
{
  pthread_t t;
  if (pthread_create(&t, NULL, thread_issue, NULL)) {
    error("Erreur lors de la création du thread");
    return -1;
  }
  int i = 0;
  info("Speaking");
  for (; i < 5; i++) {
    info("%i", i);
    usleep(100);
  }

  info("Speaking");
  for (i = 0; i < 5; i++) {
    usleep(100);
    info("%i", i);
  }
}
