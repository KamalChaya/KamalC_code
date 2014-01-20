#!/usr/bin/python
#Kamal Chaya
#chayak@onid.orst.edu
#CS311-400
#Homework2

import subprocess

cmd = subprocess.Popen(['who', '-b', '-d', '-l', '-p', '-r', '-T', '-t', '-u'])
print cmd
