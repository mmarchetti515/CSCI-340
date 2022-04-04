
#  Michael Marchetti
#  z1860574
#  CSCI 340 Data Struct Algorithm Analysis
#  Class # 1737-Section 0002-Component LEC
# 
#  I certify that this is my own work and where appropriate an extension
#  of the starter code provided for the assignment.
# 
#  Assignment 7
# 

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Rule to link object code files to create executable file
wordscanner: wordscanner.o
	$(CXX) $(CXXFLAGS) -o wordscanner $^

# Rules to compile source code files to object code
wordscanner.o: wordscanner.cc wordscanner.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f all *.o
