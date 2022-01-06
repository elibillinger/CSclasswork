# Eli Billinger
# CSCI 101 - Section A
# Python Lab 10
import csv
gdp = []
unemploy = []
def get_gdp_data(GDP,year):
    with open (GDP, 'r') as GDP_file:
        line = GDP_file.readline()
        if year in line:
            lines = line.split('     ')
            gdp.append(lines[2])
    return gdp
def get_unemp_data(unemployment,year):
    with open(unemployment, 'r') as unem:
        line = csv.reader(unem, delimiter=',')
        for row in line:
                for part in row:
                    if part == year:
                        continue
                    else:
                        unemploy.append(part)
            
    return unemploy

def get_average_gdp(gdp_list):
    total = 0
    avg = 0
    for part in gdp_list:
        total = total + int(part)
    avg = total/len(gdp_list)
    return avg
def get_average_unemp(unemp_list):
    total = 0
    avg = 0
    for part in unemp_list:
        total = total + int(part)
    avg = total/len(gdp_list)
    return avg
GDP = input('Enter the GDP file name:\nGDP>')
unemployment = input('Enter the unemployment file name:\nUNEMPLOYMENT>')
year = input('Enter the year to examine:\nYear>')
while not (1948 <= int(year) <= 2018):
    print('Incorrect year, try again')
    year = input('Year>')

gdp_list = get_gdp_data(GDP,year)
unemp_list = get_unemp_data(unemployment,year)
average_gdp = get_average_gdp(gdp_list)
average_unemploy = get_average_unemp(unemp_list)
print('OUTPUT ',year)
print('OUTPUT ',average_gdp)
print('OUTPUT ',average_unemploy)
