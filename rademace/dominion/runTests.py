import subprocess
import os

files = [('unittest1', 'unit1'), ('unittest2', 'unit2'), ('unittest3', 'unit3'),
		('unittest4', 'unit4'), ('cardtest1', 'card1'), ('cardtest2', 'card2'),
		('cardtest3', 'card3'), ('cardtest4', 'card4'),
		('drawCardTest', 'drawCardTest'), ('discardTest', 'discardTest')]
 
for i in files:	
	if (not os.path.exists('.\\' + i[0] + '.exe')) or (os.stat('.\\' + i[0] + '.c').st_mtime > os.stat('.\\' + i[0] + '.exe').st_mtime):
		subprocess.call(['make', i[1]])

print '\n'

for i in files:			
	subprocess.call([i[0]])


