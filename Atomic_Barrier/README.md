<h1>Atomic_Barrier</h1>

<p>The Atomic_Barrier class is responsible for <b>CREATING</b> a synchronization barrier for multiple threads, <b>DETECTING</b> and <b>WAITING</b> for all threads to reach the barrier, and <b>RELEASING</b> all threads once they reach the barrier.</p>

<h3>Its attributes are:</h3>
<ul>
  <li>an atomic integer barrier_level (for defining the number of threads to wait for);</li>
  <li>an atomic integer counter (for counting the number of threads that reached the barrier);</li>
  <li>an atomic boolean releaser (for signaling the threads to be released from the barrier);</li>
  <li>a mutex mtx_counter (for protecting the counter attribute);</li>
  <li>a condition variable detainer (for notifying the threads that the barrier has been reached).</li>
</ul>
  
<h3>The methods include:</h3>
<ul>
  <li>A default constructor that sets the barrier level to INT32_MAX (maximum integer value).</li>
  <li>A constructor that allows for defining a specific barrier level.</li>
  <li>A default destructor.</li>
  <li>A method <b>detain()</b> that adds the current thread to the counter, detects if all threads reached the barrier, signals the releaser if so, and waits for the releaser to release the threads.</li>
  <li>A method <b>detained()</b> that returns the current number of threads that reached the barrier.</li>
  <li>A method <b>release()</b> that signals the releaser to release the threads.</li>
</ul>

<h3>The libraries used:</h3>
<ul>
  <li>iostream</li>
  <li>atomic</li>
  <li>mutex</li>
  <li>condition_variable</li>
</ul>
