#!/usr/bin/env python
# coding: utf-8

# In[5]:


#Q2
import math

a = int(input("Enter value of a: "))
b = int(input("Enter value of b: "))
c = int(input("Enter value of c: "))
det = b**2 - (4*a*c)

if det<0:
    print("Only complex roots!")
elif det==0:
    print("Root is: " + str( -b/(2*a) ) )
else:
    x1 = ( -b+math.sqrt(det) ) / 2*a
    x2 = ( -b-math.sqrt(det) ) / 2*a
    print("First root: " + str(x1) )
    print("Second root: " + str(x2) )


# In[6]:


#Q3
def smaller(array,size,num):
    count = 0
    for x in array:
        if x < num:
            count = count+1
    return count

integers = [13, 56, 21, 45, 20, 43, 12, 43, 6]
size = len(integers)
print("Number of elements in an array of integers x of size s that are strictly less than a given number n: " + str( smaller(integers, size, 21) ))


# In[7]:


#Q4
integers = [12,24,35,24,88,120,155,88,120,155]
print(set(integers))


# In[8]:


#Q5
integers1 = [1,3,6,78,35,55]
integers2 = [12,24,35,24,88,120,155]
a = set(integers1)
a &= set(integers2) 
print(a)


# In[9]:


#Q6
weight = int(input("Enter Weight in lbs: "))
height = int(input("Enter Height in meters: "))
BMI = weight / (height**2)
print("BMI is: " + str(BMI) )


# In[10]:


#Q7
growth_multiplier = 1.3
sales = 1200000
print('Sales after 7 years: ' + str( 7*sales*growth_multiplier ) )


# In[11]:


#Q8
weight = int(input("Enter weight in kg:"))
Mstone = weight*2.2/14
print("Your weight in stones is: " + str(Mstone) )


# In[14]:


#Q9
array = [ ['Kitchen', 'Hall', 'Room'], [1, 2, 3] ]
print(array[0][0]+str(array[1][0]))
print(array[0][1]+str(array[1][1]))
print(array[0][2]+str(array[1][2]))


# In[15]:


#Q10
score1 = [3.1,3.2,3.3,3.4,3.5,3.6]
score2 = [3.1,3.2,3.3,3.4,3.5,3.6]
score3 = [3.1,3.2,3.3,3.4,3.5,3.6]
students = {}
students['Ali'] = score1
students['Azlan'] = score2
students['Aziz'] = score3
print(students['Ali'])


