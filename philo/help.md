# PHILOOOOOOOO

## ISSUE

F | 1 2 3 4 5
P |  1 2 3 4 5

## Parsing

- if the first arg == 0, wait that at lest one philo die
- if the arg is not unsigned it error arguments
- if there is a the four argument (nb_lunch) the progrm must be end when you reach == (mn_lunch)

## Initialise

- nb_philo = nb_fork because each philo have his fork
- struct philos {int id, pthread_t thread}

## Fonctions use

### usleep

#### Usage: int usleep(useconds_t usec);
#### Description: Suspends execution of the calling thread for (at least) usec microseconds.

#### ----------------

### gettimeofday

#### Usage: int gettimeofday(struct timeval *tv, struct timezone *tz);
#### Description: Gets the current time. The tv structure is filled with the number of seconds and microseconds since the Epoch (00:00:00 UTC, January 1, 1970).

#### ----------------

### pthread_create

#### Usage: int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
#### Description: Creates a new thread, which starts execution by invoking start_routine.
#### Demo : pthread_t thread /pthread_create(&thread, NULL, thread_function, NULL);

#### ----------------

### pthread_join

#### Usage: int pthread_join(pthread_t thread, void **retval);
#### Description: Waits for the specified thread to terminate and retrieves its exit status.