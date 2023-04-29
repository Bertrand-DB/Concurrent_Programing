#include "Atomic_Barrier.h"

Atomic_Barrier::Atomic_Barrier()
{
    barrier_level = INT32_MAX;      // Barrier level set to the maximum value of a 32-bit integer
}

Atomic_Barrier::Atomic_Barrier(unsigned barrier_level)
{
    this->barrier_level = barrier_level;    // Initialize the barrier level with the provided value
}

Atomic_Barrier::~Atomic_Barrier()
{

}

void Atomic_Barrier::detain()
{
    std::unique_lock<std::mutex> lock(mtx_counter);    // Acquire the mutex to ensure mutual exclusion for the counter

    counter++;                              // Increment the counter for threads that have reached the barrier
    int expected = barrier_level.load();     // Get the current value of the barrier level
    bool result = counter.compare_exchange_strong(expected, 0);   // Compare and swap the counter value with the barrier level if they are equal
    releaser.store(result);                  // Store the result of the comparison in the release flag

    detainer.notify_all();                   // Notify all threads waiting on the condition variable
    detainer.wait(lock, [this]{return releaser.load();});  // Wait until the barrier is released
}

unsigned Atomic_Barrier::detained()
{
    return counter.load();   // Return the current value of the counter for detained threads in the barrier
}

void Atomic_Barrier::release()
{
    releaser.store(true);   // Mark the barrier as released, allowing detained threads to proceed
    detainer.notify_all();  // Notify all threads waiting on the condition variable
}
