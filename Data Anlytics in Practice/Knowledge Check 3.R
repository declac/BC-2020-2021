#Question 1
houses_data = read.table(file="houses.tab",header=TRUE,sep="\t",na.strings="NA",dec=".",quote="\"'")
summary(houses_data)

#Question 2
median(houses_data$SQFT)

#Question 3
mean(houses_data$PRICE[houses_data$SQFT >= 1250 & houses_data$SQFT <= 1750])

#Question 4
summary(houses_data$PRICE)

#Question 6
x = 16
y = 4
while(x == y*y)
{
  x = x^2
}
print(x)

#Question 7
A  = matrix(data = c(2,3,2,1.17), nrow=2, ncol=2, byrow = TRUE)
print(A[2,1])

#Question 8
A = t(A)
print(A[1,2])

#Question 9
vec10 = c(2, 4, 8, 16, 12, -10)
append(vec10,10)
mean(vec10)

#Question 10
v1=c(1,3,5,7,9,NA,12,NA,11,-13)
length(v1)

#Quesition 11
even <- function(n) {
  if (n%%2 == 0){
    return(TRUE)
  }
  else {
    return(FALSE)
  }
}
even(7)

#Question 12
x = 15
y = 5
while(x > y+9) 
{
  x = x+1
}

#Question 13
my_max <- function(vector){
  temp = vector[1]
  
  for(i in 1:length(vector)) {
    if(vector[i] > temp) {
      temp = vector[i]
    }
  }
  return(temp)
}
test = c(2, -4, 8, 16, 5, 96)
my_max(test)
