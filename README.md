# CircuitAnalyser

Semestral project written for Computer Programming lectures.

Requirements for the project:
* no use of STL
* usage of different types of constructors, friend classes or methods, inheritance (also multiple inheritance), polymorphism

Usage:

Program runs from Command Line.
Switches:
* '-i' for name of the input file (with the extension - when different from .txt) - eg.: -i circuit.txt

Format of the file:

1. Output file name (optionally with extension)
2. List of elements in form:

	Element's name (including also elemnt's type, eg. R1) node '+' node '-' value (in basic units), eg. R1 1 0 3
	(every parameter of the element in the list should be separated from other with a whitespace)

3. End of the list:
	.END

Circuit requirements

* Nodes should be enumerated in turn (0, 1, 2, 3...) - no random or missing numbers would be accepted (eg. 0, 2, 3, 5,...)
* There should be '0' node, which means 'zero potential' (because of the calculation method - nodal analysis).
* There shouldn't be any extra (redundant) nodes.


Example of the input file is given in the repositiory (obwod.txt)