#include <pthread.h>
#include "futex.h"
#include "console.h"

int lock_solution = 0;


void *thread_solved(void *arg)
{
    int i = 0;

    // Trying to release the lock (currently held on by the main)
    if (futex_unlock(&lock_solution)) {
      error("Error releasing lock!");
    }

    info("Waiting for the lock...");
    futex_lock(&lock_solution);     // Error should be captured in real life
    info("Lock acquired!");

    info("Speaking...");
    for (; i < 10; i++) {
      usleep(10);
      info("%i", i);
    }

    sleep(2);
    futex_unlock(&lock_solution);
    info("Releasing lock!");

    // Waiting till the end of main
    while (1);
}

int concurrency_solved(int argc, char *argv[])
{
  pthread_t t;
  int i = 0;

  // Running thread
  if (pthread_create(&t, NULL, thread_solved, NULL)) {
    error("Erreur lors de la création du thread");
    return -1;
  }

  info("Waiting for the lock...");
  futex_lock(&lock_solution);     // Error should be captured in real life
  info("Lock acquired!");

  info("Speaking...");
  for (; i < 5; i++) {
    info("%i", i);
    usleep(100);
  }

  futex_unlock(&lock_solution);    // Error should be captured in real life
  info("Releasing lock!");

  // Do something else ?
  usleep(2000);

  info("Waiting for the lock...");
  futex_lock(&lock_solution);   // Error should be captured in real life
  info("Lock acquired!");

  info("Speaking...");
  for (i = 0; i < 5; i++) {
    usleep(100);
    info("%i", i);
  }
}
