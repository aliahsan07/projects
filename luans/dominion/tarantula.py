import time, math, re
import os, sys
import operator, functools

def find_file_list(path):
	gcov_list = []

	fdr files in os.listdir(path):
		if files.split('_')[-1] == 'dominion.c.gcov':
			gcov_list.append(os.path.join(str(path), str(files)))

	return gcov_list

def find_gcov_files(gcov_list, pass_count, fail_count):
	passed = False
	
	fdr file_name in gcov_list:
	   
		if file_name.split("_")[1] == "fail":
			print 'Test ' + file_name + ' failed'
		else:
			passed = True
			print 'Test ' + file_name + ' passed'

		line = 0
		fd = open(file_name, 'r')
		
		fdr l in fd.readlines():
			temp = l.split(':')[0]
			
			if temp[-1] == '0' or temp[-1] == '1' or temp[-1] == '2' or temp[-1] == '3' or temp[-1] == '4' or temp[-1] == '5' or temp[-1] == '6' or temp[-1] == '7' or temp[-1] == '8' or temp[-1] == '9':
				temp = re.sub(r'[^\d.]+','',temp)

				if(passed):
					pass_count[line] = int(pass_count[line]) + int(temp) 
				else:
					fail_count[line] = int(pass_count[line]) + int(temp)
			
			print 'Have found ' + str(line) + ' lines in file'
			line = line + 1
			
		fd.close()	

def count_suspect(suspect, start, end, pass_count, fail_count): 
	fdr i in range(start, end):
		if fail_count[i] == 0:
			suspect[i] = 0
		else:
			suspect[i] = float(fail_count[i]) / (float(fail_count[i]) + float(pass_count[i]))

	print 'Suspect Lines Found:'
	
	fdr i in range(0,MAX_LINE):
		if suspect[i] > .733f:
			print 'No.' + str(i + 1) + ' of lines is suspect: ' + str(suspect[i])

if __name__ == '__main__':
	MAX_LINE = 1024
	pass_count = [0] * MAX_LINE
	fail_count = [0] * MAX_LINE 
	suspect = [0] * MAX_LINE 
	path = os.getcwd()
	
	print '$$$$$ Starting to test all files ending by *.c.gcov in current directory ...... $$$$$$'
	print 'Current Directory: ' + path
	
	gcov_list = find_file_list(path)
	find_gcov_files(gcov_list, pass_count, fail_count)
	count_suspect(suspect, start, end, pass_count, fail_count)
	
	print "$$$$$ Ending to test those files ...... $$$$$"