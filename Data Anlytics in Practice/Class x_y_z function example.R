# Class function example

# clean environment
rm(list=ls()) # CTRL + L / CMD + L(Mac) to clear console

x = 1
y = 2

# x, y now appear in global environment
add_x_y = function(x,y)
{
  z = 5
  cat("Value of z is:", z, "\n")
  return(x+y)
}

add_x_y(x,y)
# this fails as z no longer defined:
# z only exists inside add_x_y while it's being run
z

# Question from last class: what if x, y are also defined in function?
# Notice how re-defining add_x_y copies over the previous definition of add_x_y
add_x_y = function(x,y)
{
  z = 5
  cat("Value of z is:", z, "\n")
  x=3 # these are copies of x, y inside the function; they only exist here
  y=5 # notice nothing happens to x, y outside
  # returned value however is affected by the x,y defined in add_x_y which supersede
  # the global copy of x, y
  return(x+y) 
}
add_x_y(x,y)