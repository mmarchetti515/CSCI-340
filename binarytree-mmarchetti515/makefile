
#  Michael Marchetti
#  z1860574
#  CSCI 340 Data Struct Algorithm Analysis
#  Class # 1737-Section 0002-Component LEC
# 
#  I certify that this is my own work and where appropriate an extension
#  of the starter code provided for the assignment.
# 
#  Assignment 8
# 

# Compiler variables
CXX = g++
CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -g -I.

#idk something
all: binarytree

# Rules to compile source code files to object code
binarytree: binarytree.cc btree.h node.h
	$(CXX) $(CXXFLAGS) -o binarytree $^

# Pseudo-target to remove object code and executable files
clean:
	rm -f binarytree
