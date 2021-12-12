This is a rush project by 42.
Its goal is to make in 2 days a C program that reads keys and values from the standard input,
then reads keys and prints its associated value, as fast as possible.

An example of input would be something like this

------
key1
value1
key2
value2
hello
world

key1
hello
key2
key7
------

and the output would be

------
value1
world
value2
key7: Not found.
------

We achieved this by implementing a HashMap based on an AVL binary tree.
Even though it could be improved, we still managed to get good performance.

This was achieved with Carmen LOEW (cloew), huge thanks to her!
