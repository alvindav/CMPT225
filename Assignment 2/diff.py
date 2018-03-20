#!/usr/bin/env python
import subprocess

passed = 0

print ("Running test 1... ")
rt = subprocess.call("diff ./output1 ./dq1.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 2... ")
rt = subprocess.call("diff ./output2 ./dq2.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 3... ")
rt = subprocess.call("diff ./output3 ./dq3.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 4... ")
rt = subprocess.call("diff ./output4 ./dq4.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")


print ("Passed " + str(passed) + " of 4 tests")
