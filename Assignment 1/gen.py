#!/usr/bin/env python
import subprocess

print ("Running test 1... ")
subprocess.call("./gscheck < 1.in > 1.gt",shell=True)
print ("Running test 1a... ")
subprocess.call("./gscheck < 1a.in > 1a.gt",shell=True)
print ("Running test 2... ")
subprocess.call("./gscheck < 2.in > 2.gt",shell=True)
print ("Running test 2a... ")
subprocess.call("./gscheck < 2a.in > 2a.gt",shell=True)
print ("Running test 3... ")
subprocess.call("./gscheck < 3.in > 3.gt",shell=True)
print ("Running test 3a... ")
subprocess.call("./gscheck < 3a.in > 3a.gt",shell=True)
print ("Running test 4... ")
subprocess.call("./gscheck < 4.in > 4.gt",shell=True)
print ("Running test 4a... ")
subprocess.call("./gscheck < 4a.in > 4a.gt",shell=True)
print ("Running test 5... ")
subprocess.call("./gscheck < 5.in > 5.gt",shell=True)
print ("Running test 5a... ")
subprocess.call("./gscheck < 5a.in > 5a.gt",shell=True)

