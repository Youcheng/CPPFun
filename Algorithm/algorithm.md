# computer algorithm
    A computer algorithm is a set of steps to accomplish a task that
    is described precisely enough that a computer can run it.
    
# what do we want from a computer algorithm
* correctness
* Resource usage
  * running time
  * computer memory
  * ...    
  
# how to characterize running time - asymptotic notation

All of these asymptotic notations give us the luxury of dropping low-order
terms and constant factors so that we can ignore tedious details and focus
on what’s important: how the function grows with n.

&theta;-notation
----------------
Although we lose precision by characterizing the running time as &theta;(n), <br>
we gain the advantages of highlighting the order of growth of the running time and<br>
suppressing tedious detail.<br>

The idea is if we have functions, f(n) and g(n), we say **f(n) = &theta;(g(n))**<br>
if f(n) is within a constant factor of g(n) for sufficiently large n.


O-notation(upper bound)
-----------------------
A function **f(n) = O(g(n))** if once n becomes sufficiently<nt>
large, f(n) is **bounded** from above by some constant times g(n).<br>
We use **O-notation** to indicate that a running time is **never worse**<br>
than a constant times some function of n.<br>

&Omega;-notation(lower bound)
-----------------------------
A function **f(n) = &Omega;(g(n))** if a running time is never better than a constant times some func
tion of n.
