#################################################
######## Eli Billinger                  #########
######## Lab 10B - Function Definitions #########
######## Section - C                    #########
#################################################
        
# Imports
import math

################################################
########   Function 1 : PrintOutput    #########
################################################

def PrintOutput(string):
    print('OUTPUT',string)

################################################
########   Function 2 : TriangleArea   #########
################################################

def TriangleArea(height,width):
    area = height * width * .5
    PrintOutput('%.2f'%area)

################################################
########   Function 3 : FeetToMeters   #########
################################################

def FeetToMeters(feet):
    meters = feet * 0.3048
    PrintOutput('%.3f'%meters)

################################################
########   Function 4 : PolarCoords    #########
################################################

def PolarCoords(x,y):
    r = math.sqrt((x**2)+(y**2))
    theta = math.degrees(math.atan(y/x))
    PrintOutput('%.1f'%r)
    PrintOutput('%.1f'%theta)

################################################
########   Function 5 : EurosToDollars #########
################################################

def EurosToDollars(euros):
    dollars = euros*1.12
    PrintOutput('%.2f'%dollars)
