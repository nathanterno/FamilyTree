Nathan Moliterno
4-4-19 11:27

Purpose:
	The Purpose of this program is to read commands from a file and build
and analyze a graph accordingly. There are two types of vertices that belong to
the graph: and individual, and a family. Individual vertices can only be
connected to family vertices and visa versa. There are two types of edges by
which an individual vertex can be connected to a family vertex: a parent/child
edge and a marriage egde. An individual is allowed to have up to ten marriages,
and a family is allowed up to ten children in the graph.

There are four commands that the program is able to read and execute:
	1) "Individual" - Adds an individual vertex as well as any potential
edge relationships it may posess to the graph.
	2) "Family" - Adds a family vertex as well as any potential edge
relationships it may posess to the graph.
	3) "Check" - The program verifies that for every parent/child edge,
the parent vertex properly identifies the correct child vertex as such and
the child vertex properly identifies the correct parent vetex as such. For
each marriage, the program verifies that each individual connected by the
marriage edge properly idenfies the other vertex as their spouse.
	4) "Relate" - The program receives integer values associated with
two individual vertices as arguments. It then traverses the graph in order
to find the shortest path from individual one to individual two.

Compiling:
	To compile the program, simply type "make" into the command line under
the directory where the program files are located.

Running:
	To run the program, type "./FamilyTree " followed by either "test.txt"
or "testnqm.txt" depending on which test you intend to run.
