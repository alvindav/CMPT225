#!/usr/bin/env python
import subprocess

print ("Running test 1... ")
subprocess.call("./dqtest1 > dq1.gt",shell=True)
print ("Running test 2... ")
subprocess.call("./dqtest2 > dq2.gt",shell=True)
print ("Running test 3... ")
subprocess.call("./dqtest3 > dq3.gt",shell=True)
print ("Running test 4... ")
subprocess.call("./dqtest4 > dq4.gt",shell=True)
print ("Creating test 7... ")
subprocess.call("./dqtest7 > dq7.gt",shell=True)
