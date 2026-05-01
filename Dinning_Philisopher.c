#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];
pthread_t philo[N];

// Philosopher function
void* philosopher(void* num)
{
    int id = *(int*)num;

    while(1)
    {
        printf("Philosopher %d is thinking\n", id);
        sleep(1);

        // Pick forks
        sem_wait(&forks[id]);
        sem_wait(&forks[(id + 1) % N]);

        printf("Philosopher %d is eating\n", id);
        sleep(1);

        // Put forks
        sem_post(&forks[id]);
        sem_post(&forks[(id + 1) % N]);
    }
}

int main()
{
    int i, id[N];

    // Initialize semaphores
    for(i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    // Create philosophers
    for(i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&philo[i], NULL, philosopher, &id[i]);
    }

    // Join threads
    for(i = 0; i < N; i++)
        pthread_join(philo[i], NULL);

    return 0;
}