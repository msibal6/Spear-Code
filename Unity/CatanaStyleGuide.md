# My Style Guide For C#
# How I code in C# for unity 
## This is under continual revision because I realized I really know very little

## Table Of Contents

* [Class Declaration](#Class-Declaration)
* [Formatting](#Formatting)
	* [Conditionals](#Conditionals)
* [Comments](#Comments)
	* [Comments Style](#Comments-Style)
	* [Class Comments]($Class-Comments)

## Class Declaration

### Data Member Declaration 

Group similar declarations together, placing public parts earlier.  A class
definition should usually start with a public section and then private.  Within
each section, generally prefer grouping similar kinds of declarations  together,
and generally prefer to sorted by: alphabetized type and similarity.  

### Function Declaration

Always declare protection level. 

## Formatting 

### Conditionals  

Prefer no spaces inside parentheses. The if and else keywords belong on  
separate lines.  

Do not include spaces between the parentheses and the condition. Always include spaces between the if and opening pararentheses, and between the closing  
parenthese and the opening brace.  

Single-line statements do not require braces

Leave an empty line in between new statements.  


## Comments

Before you comment, use concise and reasonable  names for new classes,  
variables, and functions.

### Comments Style   
Use the `//` style. 

When commenting a line of code, comment right on top of the line of  
code, and leave an empty line between the comment and the previous line of code. 
When commenting inline, comment a space after the code.  

### Class Comments
use the `///` summary syntax. Begin and end the block of comments with  
the `/// summary` comment line.  



