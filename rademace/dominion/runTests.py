import subprocess
import os

files = ['unittest1', 'unittest2', 'unittest3', 'unittest4', 'cardtest2', 
		'cardtest3', 'cardtest4', 'drawCardTest', 'testDiscard', 'cardtest1']
 
for i in files:	
	if (not os.path.exists('.\\' + i + '.exe')) or (os.stat('.\\' + i + '.c').st_mtime > os.stat('.\\' + i + '.exe').st_mtime):
		subprocess.call(['gcc', i + '.c', '-o',  i, '-I.'])
	subprocess.call([i])

