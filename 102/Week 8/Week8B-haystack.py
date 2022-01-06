# Eli Billinger
# CSCI 102 - Section C
# Week 8 - Part B
string_s = input('Enter a DNA string s:\ns> ')
string_t = input('Enter a substring \nt> ')
locations = []


num_substr = string_s.count(string_t)
print('The total number of substrings found is %d\nOUTPUT %d' % (num_substr,num_substr))

for i in range(len(string_s)):
    if string_s[i:i+len(string_t)] == string_t:
        locations.append(i + 1)

print('The locations fo these substrings in s are: ',' '.join(map(str,locations)),'\nOUTPUT',' '.join(map(str,locations)))
