import os
import subprocess

os.chdir("./difftest")
os.system("make clean")
os.system("make testdominion")
os.system("testdominion gameResults.out")
os.chdir("..")
os.system("make clean")
os.system("make testdominion")
os.system("testdominion gameResults.out")
os.system("diff --side-by-side --left-column gameResults.out ./difftest/gameResults.out >> testdominion.out")
