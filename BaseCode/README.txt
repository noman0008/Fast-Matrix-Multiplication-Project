Read this file carefully before running the provided code.

By Jiecao Chen (jiecchen@indiana.edu)
============================================

## Platform
Provided code has been carefully tested under linux machine (both Ubuntu and Redhat), hopefully it will also work under Mac OS.


## Compile the code
in your terminal, run

    $ make

which generates two excutable files *test* and *generator*.


## Generate test data
*generator* can be used to create test files for this project. The general way to call *generator* is to run the following in your terminal,
    
    $ ./generator An Am Bn

This will print the following to standard output,

     An Am Bn

     an An * Am matrix 

     an Am *  Bn matrix B

     the product of A * B

For example, run 
    
    $ ./generator 2 3 3

prints

	2 3 3

        7       -5       16
       10        4      -15



       -3      -13        2
       -8      -10        7
      -13       10        5



     -189      119       59
      133     -320      -27

To create test file (say *test.dat*), you use the following trick,

   $ ./generator 100 20 30 > test.dat

This creates a file *test.dat* in your current dir. You can create multiple test files in this way.

!!!Note, it takes quite a while for *generator* to generate large test file, because it uses the naive method to calculate the product of two matrices. So be patient.


## Test your Product.cpp
In the attached code, Product.cpp is provided (only partially implemented). Once your have implemented your own Product.cpp, you should overwrite the existing one and make *test* again via the command

   $ make test

Now you have a new excutable file *test*, this program will call your implemented Product.cpp to calculate matrix product and compare with standard results. Assume you have generated *test0.dat*, *test1.dat*, *test2.dat* using *generator* as discuss above, simply run

    $ ./test *.dat

it will print

   test0.dat: 1.2702613e-06 secs
   test1.dat: 3.5873483e-06 secs
   test2.dat: 0.0035286627 secs

You should be able to make use of those results to create figures etc.

Error information will also be printed if you did something wrong.

!!!Note, if your implement Product.c instead of Product.cpp, there at least two ways to make things work,
	 1. rename your Product.c as Product.cpp, or
	 2. modify the Makefile, replace all "Product.cpp" with "Product.c"



Send me an email if you have question, any feedback would be appreciated.









     
