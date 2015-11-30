from random import sample
import random

net = raw_input("Enter number of nets:")
print "Number of nets are "+net
nets = int(net)

elementnum = raw_input("Enter number of elements:")
print "Number of elements are "+elementnum
elements = int(elementnum)

print "Wait for the message prompt."

elements_in_row = []
elements_to_enter = []

#Netlist file
netlist = open("Netlist.txt", "w")

for rows in xrange(0, nets+1):
	
	#Number of elements in each net.
	number = random.randint(2,elements)

	#Non repeating array.
	elements_in_row = sample(xrange(elements), number)

	# Convert the data to string.
	elements_to_enter = str(elements_in_row)

	#Write the data into file.
	netlist.writelines(elements_to_enter)

	elements_in_row = []
	elements_to_enter = []

netlist.close()
print "Now, open the file."
	
		