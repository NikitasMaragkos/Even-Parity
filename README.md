# Even-Parity
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT "MIT License")

![Even-Parity cover image](https://github.com/NikitasMaragkos/Path-Finding-With-Multiple-Algorithms/blob/main/Images/PathFinding.png?raw=true)

With this code you can test the function of both even parity and double even parity. The menu is

![Even-Parity cover image](https://github.com/NikitasMaragkos/Path-Finding-With-Multiple-Algorithms/blob/main/Images/PathFinding.png?raw=true)

#### Case 1

Here, the user gives an input and the program returns the same message with even parity applied to it. An example can be seen below.

![Even-Parity cover image](https://github.com/NikitasMaragkos/Path-Finding-With-Multiple-Algorithms/blob/main/Images/PathFinding.png?raw=true)

#### Case 2

Here, the user gives an input and the program creates 3 outputs. One without any errors, one with a single error and one with two errors. As we can see from the example below, even parity cannot detect that the message has errors if the number of errors is an even number.

![Even-Parity cover image](https://github.com/NikitasMaragkos/Path-Finding-With-Multiple-Algorithms/blob/main/Images/PathFinding.png?raw=true)

#### Case 3

Here, the user gives a 28-bit input and the program creates 4 7-bit numbers so as to apply double even parity and return the output. An example can be seen below.

![Even-Parity cover image](https://github.com/NikitasMaragkos/Path-Finding-With-Multiple-Algorithms/blob/main/Images/PathFinding.png?raw=true)

#### Case 4

Here, purposely the program add some errors on the given input in order to check if double even parity can detect them. Altought, double even parity is stronger than even parity (since it can detect the exact location of errors), there are specific occasions that it cannot detect errors. These occasions are:
1) single error on one of the 4 corners
2) 4 * k errors that create k rectangles

An example can be seen below.

![Even-Parity cover image](https://github.com/NikitasMaragkos/Path-Finding-With-Multiple-Algorithms/blob/main/Images/PathFinding.png?raw=true)
