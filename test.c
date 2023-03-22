# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

int main()
{
    pthread_mutex_t *mux;

    mux = NULL;
    printf("%d\n", pthread_mutex_destroy(mux));
}