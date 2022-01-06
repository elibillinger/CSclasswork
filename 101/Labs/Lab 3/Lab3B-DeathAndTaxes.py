# Eli Billinger
# CSCI 101 - Section G
# Python Lab 3B
status = input('Please enter the filing status:\nSTATUS>')
income = int(input('Please enter the income earned:\nINCOME>'))
tax = 0.0
percent = 0
if status == 'single':
    if (income-9325)<=0:
        tax = income*0.1
    elif (income-37950)<=0:
        tax = (9325*0.1) + ((income-9325)*0.15)
    elif (income-91900)<=0:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((income-37950)*0.25)
    elif (income-191650)<=0:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((91900-37950)*0.25) +((income-91900)*0.28)
    elif (income-416700)<=0:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((91900-37950)*0.25) + ((191650-91900)*0.28) + ((income-191650)*0.33)
    elif (income-418,400)<=0:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((91900-37950)*0.25) + ((191650-91900)*0.28) + ((416700-191650)*0.33) + ((income-416700)*0.35)
    else:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((91900-37950)*0.25) + ((191650-91900)*0.28) + ((416700-191650)*0.33) + ((418400-416700)*0.35) + ((income-418400)*0.396)
elif status == 'joint':
    if (income-18650)<=0:
        tax = income*0.1
    elif (income-75900)<=0:
        tax = (18650*0.1) + ((income-18650)*0.15)
    elif (income-153100)<=0:
        tax = (18650*0.1) + ((75900-18650)*0.15) + ((income-75900)*0.25)
    elif (income-233350)<=0:
        tax = (18650*0.1) + ((75900-18650)*0.15) + ((153100-75900)*0.25) +((income-153100)*0.28)
    elif (income-416700)<=0:
        tax = (18650*0.1) + ((75900-18650)*0.15) + ((153100-75900)*0.25) + ((233350-153100)*0.28) + ((income-233350)*0.33)
    elif (income-470700)<=0:
        tax = (18650*0.1) + ((75900-18650)*0.15) + ((153100-75900)*0.25) + ((233350-153100)*0.28) + ((416700-233350)*0.33) + ((income-416700)*0.35)
    else:
        tax = (18650*0.1) + ((75900-18650)*0.15) + ((153100-75900)*0.25) + ((233350-153100)*0.28) + ((416700-233350)*0.33) + ((470700-416700)*0.35) + ((income-470700)*0.396)

elif status == 'separate':
    if (income-9325)<=0:
        tax = income*0.1
    elif (income-37950)<=0:
        tax = (9325*0.1) + ((income-9325)*0.15)
    elif (income-76550)<=0:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((income-37950)*0.25)
    elif (income-116675)<=0:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((76550-37950)*0.25) +((income-76550)*0.28)
    elif (income-208350)<=0:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((76550-37950)*0.25) + ((116675-76550)*0.28) + ((income-116675)*0.33)
    elif (income-235350)<=0:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((76550-37950)*0.25) + ((116675-76550)*0.28) + ((208350-116675)*0.33) + ((income-208350)*0.35)
    else:
        tax = (9325*0.1) + ((37950-9325)*0.15) + ((76550-37950)*0.25) + ((116675-76550)*0.28) + ((208350-116675)*0.33) + ((235350-208350)*0.35) + ((income-235350)*0.396)

elif status == 'head':
    if (income-13350)<=0:
        tax = income*0.1
    elif (income-50800)<=0:
        tax = (13350*0.1) + ((income-13350)*0.15)
    elif (income-131200)<=0:
        tax = (13350*0.1) + ((50800-13350)*0.15) + ((income-50800)*0.25)
    elif (income-212500)<=0:
        tax = (13350*0.1) + ((50800-13350)*0.15) + ((131200-50800)*0.25) +((income-131200)*0.28)
    elif (income-416700)<=0:
        tax = (13350*0.1) + ((50800-13350)*0.15) + ((131200-50800)*0.25) + ((212500-131200)*0.28) + ((income-212500)*0.33)
    elif (income-444500)<=0:
        tax = (13350*0.1) + ((50800-13350)*0.15) + ((131200-50800)*0.25) + ((212500-131200)*0.28) + ((416700-212500)*0.33) + ((income-416700)*0.35)
    else:
        tax = (13350*0.1) + ((50800-13350)*0.15) + ((131200-50800)*0.25) + ((212500-131200)*0.28) + ((416700-212500)*0.33) + ((444500-416700)*0.35) + ((income-444500)*0.396)

else:
    print('That is not a valid status')
print('The tax owed by this person (%s filing status) with %d income is %d' % (status,income,int(tax)),'\nOUTPUT %d' % (int(tax)))
percent = round(float((tax/income)*100),2)
print('The percent of income paid in taxes is %f' % (percent), '\nOUTPUT %f' % (percent))