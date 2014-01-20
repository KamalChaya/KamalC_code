#!/usr/bin/python

#Kamal Chaya
#chayak@onid.orst.edu
#CS311-400
#Homework 2

import os, sys, getopt

try:
	opts, args = getopt.getopt(sys.argv[1:], "t:c:", ["term=", "class="])
except getopt.GetoptError as e:
	print "Correct Usage: question2.py -t <term here> -c <class name here>\n"
	print "OR for long form:\n"
	print "question2.py --term <term here> --class <class name here>\n"
	sys.exit(2)

for opt, arg in opts:
	if opt in ("-t", "--term"):
		term = arg
	if opt in ("-c", "--class"):
		course = arg

#Make the needed folders for given term&course
#First change into the home directory  
os.chdir(os.environ['HOME'])
os.mkdir(term)
os.chdir(term)
os.getcwd()
os.mkdir(course)
os.chdir(course)
os.getcwd()
os.mkdir("assignments")
os.mkdir("examples")
os.mkdir("exams")
os.mkdir("lecture_notes")
os.mkdir("submissions")

#Make symlinks
os.symlink("/usr/local/classes/eecs/" + term + "/" + course + "/src/README", "README")
os.symlink("/usr/local/classes/eecs/" + term + "/" + course + "/src", "src_class")









