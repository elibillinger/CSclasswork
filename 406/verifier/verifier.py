def read_file():
    """
    Read in a File (can be changed later) to a 2d list to keep values together
    reading the file as output.txt

    Reads our input to check that the output hits all of values that we wanted to be computed
    """
    file1 = "output.txt"
    file2 = "input.txt"
    with open(file1) as output_file:
        first_line = output_file.readline()
        output_len.append(int(first_line))
        for line in output_file:
            addition_operations.append([int(i) for i in line.split()])
    # Check if first value is equal to number of operations if it is not print statement
    with open(file2) as input_file:
        first_line = input_file.readline() # don't need first line
        line = input_file.readline()
        inputs = [int(num) for num in line.split(' ')]
        return inputs


def verify_values(operations):
    """
    Verifier goes through the 2d list and checks to see if value is in values set
    if both operands are in the set it adds them togehter and adds the solution to the values set
    it then checks if the solution is one of the required numbers in the input if it is it removes it
    from the input values list

    At end check if input value list is empty if it is not then one of the required numbers in the input
    was not computed with the output and it sets the verify to false
    Also checks if number of operations given matches actual number of operations
    """
    valid_test = True
    for operation in operations:
        counter = 0
        solution = 0
        for value in operation:
            # check if values are in the set of values that have been computed so far it not set valid to false
            if counter < 2:
                if value in values:
                    counter += 1
                    solution += value
                else:
                    valid_test = False
            if counter == 2: # if both values are verified then add to set of values that can be used
                values.add(solution)
                # Check if solution is in the input list and if it is then remove it
                if solution in input_values:
                    input_values.remove(solution)
    # check if input_values is empty if not then set valid to false
    if input_values:
        valid_test = False
    if len(addition_operations) not in output_len:
        valid_test = False
    return valid_test


output_len = []
values = {1}
addition_operations = []
input_values = read_file()
print(verify_values(addition_operations))

# Returns False if the value in first line is not equal to the actual number of operations given
# If more than 2 operands are given on a line it ignores them and continues on to the next line
