####################################
######### DATA ANALYTICS ###########
#########     WEEK3      ###########
####################################

####################################
# VECTOR OPERATIONS
####################################
# subset examples
vec1 = c(5,6,7,8)

vec1[4]

vec1[1:3]
vec1[4]
subset(vec1, vec1>6)

# other functions defined on vectors in R (non exclusive list - many more available)
#Sorting a vector with sort()
vec2 = c(8,7,6,5)
length(vec2) #returns the length of a vector

# this should return TRUE
length(vec1)==length(vec2)

# sums all elements in the vector
sum(vec1) 

# takes the mean of a vector
mean(vec1)

# returns the product of all elements in the vector
prod(vec1)

# append(vector variable name, element(s) to be appended) 
# append(v, values, after = i)  
# x = the vector the values are to be appended to; values  = elements to be added to vector; after = the subscript after which values are appended
append(vec2, c(10,11), after = 2)

# remember we can use logical operations to subset too:
# this returns just elements 1 and 3: 5 7
vec1[c(TRUE, FALSE, TRUE, FALSE)] 

vec3 = c(1, 3, 5, 6) # c() concatenates elements to a vector
vec4 = rep(3.14, 10) # replicates ten times

vec5 = c(1, 5, -14, - 1, 15)
which(vec5<0)

vec6 = c(1, 5,NA, - 1, NA)
which(is.na(vec6))

mean(vec3)
# what will happen here?
mean(vec6)

sd(vec3)
# what about missing values?
sd(vec6)

# reminder
NA+5

# this removes the NAs and replaces them with 10:
vec7 = c(1,2,3,4,5,NA)
vec7[is.na(vec7)] = 10 
vec7

# let's revert
vec7 = c(1,2,3,4,5,NA)

# let's use a function with parameters: na.rm is a parameter of mean and is set to TRUE:
mean(vec7, na.rm=TRUE)

# a library is a collection of functions written by someone else.
# first we must install the library (aka "package")
install.packages("na.tools")

# then we must reference the library (aka upload the function definitions in memory)
library(na.tools)

# now we can use the new library
na.replace(vec7, mean(vec7, na.rm=TRUE))

# let's see what happens if we do operations on vectors of different lengths
vec8=c(1,3,5)
vec9=c(1,4,5,6,7,7)

# interesting! R copied over vec8 and essentially used vec8,vec8 as the first vector. 
vec8 + vec9
vec8*vec9

# what if we do not have a multiple of length of the first vector into the second vector?
vec10 = c(1,2)
vec11 = c(3,4,5)

vec10+vec11
vec10*vec11
# it still tries to do the same, but we do get a warning that "longer object length is not a multiple of shorter object length"


####################################
# FUNCTIONS, LOOPS, LOGIC
####################################


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


####################################
# PLOTS
####################################

# generates a vector out of 100 random draws from normal distribution
y = rnorm(100)
z = rnorm(100)
plot(y,z)
plot(y,z, xlab="x axis", ylab="y axis", main="scatterplot of two random variables")

#########################################################################################



