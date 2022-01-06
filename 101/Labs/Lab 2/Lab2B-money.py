# Eli Billinger
# CSCI 101 - Section G
# Python Lab 2B
dollars = 0.0
convert_rate = 0.0
item_cost = 0.0
currency = 'EUR'

currency = input('Input the currency to convert from \n CURRENCY>')
convert_rate = float(input("Input today's convert rate for " + currency +"\n RATE>"))
item_cost = int(input("Input teh cost of the item you want to purchase \n COST>"))               
dollars = item_cost * convert_rate
print("The item the costs "+str(float(item_cost))+ " in "+currency+ " currency costs $"+ str(round(dollars,2))+" in US dollars\n OUTPUT $"+str(round(dollars,2)))
