#!/usr/bin/python

#Kamal Chaya
#chayak@onid.orst.edu
#CS311-400
#Homework 2

import urllib2, sys

#get the URL of the website to download, and the name of the file
# that it should be saved as from the cmd line args 
#THe first arg is the url, the second is filename
url = sys.argv[1]
filename = sys.argv[2]

#If the url given does not have http://www. at the beggining, prepend it
if url[0:12] != "http://www." and url[0:4] != "www.":
    url = "http://www." + url

#if the url has the www. at the beggining but NOT the http:, prepend it
if url[0:7] != "http://":
    url = "http://" + url
  
#open url
response = urllib2.urlopen(url)

#open file to write
fh = open(filename, "w")

#read from the opened url and write to the file
fh.write(response.read())
fh.close()

 
