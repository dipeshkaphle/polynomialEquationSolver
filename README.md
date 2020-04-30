# RealRootEquationSolver

Use this only when you are sure that the equation 
has no complex roots or to find if an equation has
complex roots

# Complex roots will cause this program to be stuck.



To initialize ,you do\n
 \t\t equation\<double\> eq;
Then you call the the get_equation function
  \t\t get_equation(eq);
This prompts the user for necessary inputs
  
To get the solution you use  the find_roots function
which returns a vector of the roots of the equation

 \t\t vector\<double\> roots=find_roots(eq);
  
Then you can print the roots with a loop if you want
