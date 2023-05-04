<h1>Atomic_Barrier Class Documentation</h1>

<h1>Class Description</h1>
<p>The Atomic_Barrier class is a synchronization primitive that allows a group of threads to synchronize the execution of a particular code segment. The class provides a mechanism for threads to wait at a barrier until a specified number of threads have reached the barrier, at which point all threads are released.</p>

<h2>Public Members</h2>

<h3><code>Atomic_Barrier()</code></h3>
<p>The default constructor for the Atomic_Barrier class. Sets the barrier level to the maximum value of a 64 bit unsigned int.</p>

<h3><code>Atomic_Barrier(unsigned barrier_level)</code></h3>
<p>A constructor that allows the barrier level to be set to a specific value.</p>
<p>Parameters:</p>
<ul>
	<li><code>barrier_level</code>: The number of threads required to reach the barrier before the threads are released.</li>
</ul>

<h3><code>~Atomic_Barrier()</code></h3>
<p>The destructor for the Atomic_Barrier class.</p>

<h3><code>void detain()</code></h3>
<p>A member function that causes the calling thread to wait at the barrier until a specified number of threads have reached the barrier, at which point all threads are released.</p>

<h3><code>unsigned detained()</code></h3>
<p>A member function that returns the current number of threads that are waiting at the barrier.</p>

<h3><code>void release()</code></h3>
<p>A member function that releases all threads waiting at the barrier.</p>

<h2>Private Members</h2>
<p>The following member variables are private and cannot be accessed directly from outside the class.</p>

<h3><code>std::atomic&lt;int&gt; barrier_level</code></h3>
<p>A private member variable that holds the number of threads required to reach the barrier before the threads are released.</p>

<h3><code>std::atomic&lt;int&gt; counter</code></h3>
<p>A private member variable that counts the number of threads that have reached the barrier.</p>

<h3><code>std::atomic&lt;bool&gt; releaser</code></h3>
<p>A private member variable that indicates whether the barrier has been released.</p>

<h3><code>std::mutex mtx_counter</code></h3>
<p>A private member variable that provides mutual exclusion for the counter member variable.</p>

<h3><code>std::condition_variable detainer</code></h3>
<p>A private member variable that provides a condition variable for threads waiting at the barrier.</p>
