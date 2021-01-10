# RealRootEquationSolver

Use this only when you are sure that the equation has no complex roots or to
find if an equation has complex roots

# Complex roots will cause this program to be stuck.

<p>
To initialize ,you do<br \></p>
   equation &lt double &gt eq;
<p>

Then you call the the get_equation function</p> get_equation(eq);

<p>
This prompts the user for necessary inputs<br \></p>

<p>  
To get the solution you use  the find_roots function
which returns a vector of the roots of the equation</p>
  vector &lt double &gt roots=find_roots(eq);
<p>

Then you can print the roots with a loop if you want

</p>
