#!/usr/bin/python

#Kamal Chaya
#chayak@onid.orst.edu
#CS311-400
#Homework 2

import math, sys


#get n value from cmd line arg
n = int(sys.argv[1])

#iterate over all numbers (exclude even numbers), until the nth prime has been found
noOfPrimes = 1
i = 2

while True:
    if (i%2 != 0):
        isPrime = True 
        x = 2
        while (x <= math.sqrt(i)): 
            if (i%x == 0): 
                isPrime = False
                break

            x+=1    
        
        if (isPrime == True):
            noOfPrimes += 1
            if (noOfPrimes == n):
                break
    i+=1

print i            



  







