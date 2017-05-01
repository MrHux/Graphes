A c++ graph library build on linux

This is an oriented-object library writted in C++ to use graph.
Some simple function enable user to create graph and import or export graph from file.

---------------------------------------------------------------------------------------------------------------------

There is 3 main classes to define a graph.

-Cgraph
-Cvertex
-Cedges

In our representation of a graph, a Cgraph contain a table of Cvertex. A Cvertex contain the list of convergent and divergent edges. An edge is just the id number of the other vertex who form the edge.

---------------------------------------------------------------------------------------------------------------------

A main.cpp file show some exemple to how to use the library, unit test are present inside this project files. They are specified with the "UNIT" part of the file name.

---------------------------------------------------------------------------------------------------------------------

Some new features has been added to search maximum independent sets in a graph.
