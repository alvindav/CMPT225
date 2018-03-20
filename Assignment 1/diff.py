#!/usr/bin/env python
import subprocess

passed = 0

print ("Running test 1... ")
rt = subprocess.call("diff 1.out 1.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 2... ")
rt = subprocess.call("diff 2.out 2.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 3... ")
rt = subprocess.call("diff 3.out 3.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 4... ")
rt = subprocess.call("diff 4.out 4.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 1a... ")
rt = subprocess.call("diff 1a.out 1a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 2a... ")
rt = subprocess.call("diff 2a.out 2a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 3a... ")
rt = subprocess.call("diff 3a.out 3a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 4a... ")
rt = subprocess.call("diff 4a.out 4a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 5... ")
rt = subprocess.call("diff 5.out 5.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 5a... ")
rt = subprocess.call("diff 5a.out 5a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")


print ("Passed " + str(passed) + " of 10 tests")
