
# Hello this is a comment

## Download links:
## R - http://cran.r-project.org/mirrors.html (install R first pick a server close to US East Coast)
## RStudio (a useful development environment) -  http://www.rstudio.com/ide/download/desktop

## You can either type code in the console or right here in the script editor
## You can run code from the script editor by selecting it and hitting CTRL+ENTER
## Or the run button on the right.

## Best practices: use comments - anything starting with # is a comment
## If you do more than basic arithmetic or prototyping, best to do it in the editor
## and save the file with the .R extension

2+2 # addition

2-2 # subtraction

2*2 # multiplication

2^2 # exponentiation

2/3 # division

log(5) # the log function in R is base e, or the "natural log"

exp(2) ## you square e, where e is Euler's Number which like Pi is an irrational number (can't write a fraction to represent it)
## e is an infinite sequence of digits which can be calculated as 1 + 1/1! + 1/2! + 1/3! + 1/4! + 1/5!+...
## e approximately 2.71828

sqrt(7)

sqrt(4)==2

## R preserves the typical LEFT-To-RIGHT order of operations - PEMDAS (parantheses, exponents, multiplication, division, 
## addition, subtraction)

## exponentiation before division:
3/2^2 == 3/4
(2+3)^2 == 5^2

## to pull up help put one question mark before the name of the function if you already know the function
## this will pull up R's help
?sqrt()

## this will pull up all matching help pages 

??sqr 

#########################################
############# OBJECTS ###################
#########################################

## everything is stored in your 'workspace' 
## R stores objects in memory
## if you are using R studio you can look to the right to see in the 'Global Environment' tab what is stored

## Manipulable variables are stored in R's active memory or "workspace."
## If you're using RStudio, you can see what's in your workspace on the top right.
## If not, use the ls() function to get a list of everything in the workspace.

ls()

# This is an empty list (length of zero; notice how the index starts at 1 not 0)
length(ls())

rm(list=ls())
## Objects are created using assignment operator
x <- 3 #integer
x=3
x # access the content of x

# assignment can be done with <- or =

X

# valid
F00 = 12
F00

# not valid (object names need to start with a character) 
#00F = 12

### Single element objects - integers, numeric ("real numbers"), strings, logical
numeric <- 3.14 # Numeric
string <- "The cat chased the dog" 
numeric
string

logical <- TRUE # TRUE or FALSE only two possible values
logical 

# e notation 
# this is NOT Euler's Number
121121121121121121 # 1.211211e+17 this means the number preceding e * 10^17
0.000000000000000021 # 2.13e-17 this means the number preceding e * 10^(-17)

## Vectors
vector_1 <- c(1, 3, 5, 6) # c() concatenates elements to a vector

vector_2 <- rep(3.14, 10) # rep replicates the same element into the vector the number of times given by the second parameter

vector_1 - 2*vector_1 # vector arithmetic 

# can we do vector_1 - vector_2?

# index notation: vector[i] picks the ith element
vector_1[4] # Can select an element of a vector using brackets

# range notation: vector[j:k] picks all elements with index i between j and k

vector_1[2:4] # selects multiple elements in the index range 

# try
vector_1[0]

# NOTE: for those familiar with other languages with vectors starting at index 0, this isn't the case in R
# index starts at 1

vector_1[1]

# you can delete individual elements by using a negative index
vector_1[-2]

# out of bounds: you get an NA
vector_1[9]

# NA is missing value
# it is a constant of legnth 1
# it is a reserved word (cannot name something else like it)
# How to test for it:
is.na(vector_1[9])

# sum of the elements in a vector
sum(vector_1)

# product of all elements in a vector
prod(vector_1)

## NOTE: NULL is not the same as NA
## NA is a constant representing Missing Value whereas NULL is actually empty entity like in other programming languages
foo = NULL
foo

# empty vector declaration:
empty_vector = c(NA, NA, NA)
empty_vector

# this doesn't make sense:
c(NULL, NULL, NULL)
# returns still NULL 

# there is a is.null function:
is.null(c(NULL))

# for error checking: NULL dominates any other operation
# let's say you have a NULL instead of a NA
100 - NULL + Inf
# this yields the empty vector of the same type as the operation (numeric in this case)
100==NULL
# now it is a logical empty vector (attempted a logical operation)

#correct:
is.null(100)

# this is still NA 
100 - NA + Inf

mean_of_vector_1 = mean(vector_1)
mean_of_vector_1

## LOGICAL OPERATORS 
## Boolean Logic (algebra using operators AND, OR, XOR, NOT)
2 == 2 # Equality operator  == denotes the boolean operator = is for assignment or for function arguments
2 != 2 # Inequality operator !=
4 > 2 # Greater than
4 >= 2 # Greater than or equal to
2 < 4 # Less than
2 <= 4 # Less than or equal to

## "NOT" OPERATOR 
!(4 > 2) # FALSE

### Can use booleans on vectors
c(1,2,5,0,-1,-4) > 0

length(vector_1)

# xor is the Exclusive OR - TRUE if either element is TRUE but FALSE if both are true
xor(2==2, 1==2) # TRUE
xor(3==3, 2==2) # FALSE

## & AND 
2==2&2==2
2==2&4==2 # Returns FALSE

(-1 >= 0) & (-1 <= 0)

## | OR 
2==2|4==2 # Returns TRUE

## how to use xor to swap two values
a = TRUE
b = FALSE
# swap
a=xor(a,b)
b=xor(a,b)
a=xor(a,b)
a
b

## NOTE: RESERVED NAMES IN R (DO NOT USE THESE)
# if, else, for, while, function, repeat, break, next, TRUE, FALSE, the logical operators above, Inf, -Inf, NA, NULL, NaN
pi / 0

is.infinite(pi/0)

# NaN is not a number; do not test any logic against NaN as this varies from system to system 
# a complex number will yield NaN
sqrt(-1)
z = 1 + sqrt(-1)

# generate a random number
set.seed(5)
r = rnorm(100)
hist(r)
r = rnorm(100000)
hist(r)

# what's going on here?
#r = rnorm(100000000000)

?sample
sample(1:100, 1)

sample(1:100, 6)

sample(1:3, 2, replace = TRUE)

# Conditions
## if (condition) 
#
#{
#  execute code here
#}


# clean environment
rm(list=ls())
# hit CTRL+L to clean console window

x = 3
y = 5

if(x<y)
{
  x = x^2
}

x

# R is an interpreted language - it only sees the lines it executed (if you select part of the statement above without the definitions of x and y 
# and run it, R will not know what they are)
# C for example would be a compiled language, where the entirety of the code is executed into a binary with machine instructions before you run it

if(x>y)
{
  x = 1
} else
{
  cat("Condition was",x<y)
  x = 2
}
x



#########################################
############ FUNCTIONS ##################
#########################################

## To do things in R, you use functions. Functions take some input, do something to it, and (usually) return some output
## Functions are called using the function name followed by parentheses denoting some inputs (these are typically called the "arguments" to the function)
mean(c(2,3,10,3)) # This line calls the function mean() with the argument c(2,3,10,3), taking the mean of that vector
## To know what arguments a function takes, look up its documentation 
?mean
## Functions take arguments in order, or you can specify them using the "=" sign
mean(x=c(2,3,10,3)) # mean takes one argument, x

### We can define our own functions
add_2 <- function(x){ # function commands are in the brackets and separated by lines
  k <- x + 2 # add 2
  return(k) # return the k variable
}

### Again, we can store function output using the assignment operator "<-"
adding_2_to_6 <- add_2(6)
adding_2_to_6

# fibonacci sequence
fibonacci = function(n)
{
  fib = vector()
  fib[1] = 1;
  fib[2] = 1;
  for (i in 3:n)
  {
    fib[i] = fib[i-1] + fib[i-2]
  }
  return (fib)
}

fibonacci(5)

#recursive fibonacci sequence
recursive_fibonacci <- function(n) 
{
  if(n <= 1) 
  {
    return(n)
  }else
  {
    return(recursive_fibonacci(n-1) + recursive_fibonacci(n-2))
  }
}

recursive_fibonacci(5)

# while loops

x = 1
while (x<10)
{
  x = x + 1
  cat("\n'x is now",x,"\n")
}

## sample bad code: this creates an infinite loop
#x = 1
#while (x>0)
#{
#  x = x + 1
#  cat("\n'x is now",x,"\n")
#}


# repeat, next, break -- more complex examples
x = 0
repeat
{
  x = x+1
  y = sample(1:100, 1)
  if(x+y<10)
  {
    next
  }
  x = x+ 10
  if(x+y>50)
  {
    cat("Break",x+y)
    break
  }
}

y = rnorm(100)
z = rnorm(100)
plot(y,z)
plot(y,z, xlab="x axis", ylab="y axis", main="scatterplot of two random variables")

#######################################################################################


