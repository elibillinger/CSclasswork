# Eli Billinger
# CSCI 101 - Section G
# Python Lab 5B

num_years = int(input('Input the number of years to print in the reforestation table:\nYEAR> '))
inital_acres = 14000
acres_now = 2500
i = 1
year =0
percent_of_forest = (acres_now / inital_acres)*100
output = 'OUTPUT\t',year,acres_now,percent_of_forest
percent_sign = '%'

print('The reforestation table is then\n')
print('OUTPUT\tYear\t# Acres in Forest\t% of Forest')
print('OUTPUT\t%d\t %.1f \t\t %.2f %s' % (year,acres_now,percent_of_forest,percent_sign))

while i <= num_years:
    acres_now = (acres_now * 1.02)
    percent_of_forest = (acres_now / inital_acres)*100
    year += 1
    i += 1
    print('OUTPUT\t%d\t %.1f \t\t %.2f %s' % (year,acres_now,percent_of_forest,percent_sign))


# years until 100% coverage   
while year < 1000:
    acres_now = (acres_now * 1.02)
    percent_of_forest = (acres_now / inital_acres)*100
    year += 1
    if percent_of_forest >= 100:
        print('OUTPUT ',year)
        break
    
