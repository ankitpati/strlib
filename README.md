# strlib

This project provides a small C++ library that allows more natural manipulation of strings using sensible arithmetic operators. It goes beyond just the '+' that most other languages support. The operands are capable of accepting traditional strings `(char *)`, and `int` as second operands, besides `cString` objects. Support for more types is planned.  

* `+` Concatenates two strings.

* `-` Removes one occurrence of the second operand from the first, if it appears at the end of the first. The rationale is to reverse the effect of an immediate, earlier `+`.

* `/` Removes all occurrences of the second operand from the first. The rationale is repeated subtraction.

* `== != >= <= < >` Perform alphabetical comparison.