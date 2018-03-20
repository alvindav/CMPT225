#!/usr/bin/env python
import subprocess

passed = 0

print ("Generating output 1...")
subprocess.call("./gscheck < ./Inputs/1.in > 1.gt",shell=True)
print ("Generating output 1a... ")
subprocess.call("./gscheck < ./Inputs/1a.in > 1a.gt",shell=True)
print ("Generating output 2... ")
subprocess.call("./gscheck < ./Inputs/2.in > 2.gt",shell=True)
print ("Generating output 2a... ")
subprocess.call("./gscheck < ./Inputs/2a.in > 2a.gt",shell=True)
print ("Generating output 3... ")
subprocess.call("./gscheck < ./Inputs/3.in > 3.gt",shell=True)
print ("Generating output 3a... ")
subprocess.call("./gscheck < ./Inputs/3a.in > 3a.gt",shell=True)
print ("Generating output 4... ")
subprocess.call("./gscheck < ./Inputs/4.in > 4.gt",shell=True)
print ("Generating output 4a... ")
subprocess.call("./gscheck < ./Inputs/4a.in > 4a.gt",shell=True)
print ("Generating output 5... ")
subprocess.call("./gscheck < ./Inputs/5.in > 5.gt",shell=True)
print ("Generating output 5a... ")
subprocess.call("./gscheck < ./Inputs/5a.in > 5a.gt",shell=True)

print ("Running test 1... ")
rt = subprocess.call("diff ./Outputs/1.out 1.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 2... ")
rt = subprocess.call("diff ./Outputs/2.out 2.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 3... ")
rt = subprocess.call("diff ./Outputs/3.out 3.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 4... ")
rt = subprocess.call("diff ./Outputs/4.out 4.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 1a... ")
rt = subprocess.call("diff ./Outputs/1a.out 1a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 2a... ")
rt = subprocess.call("diff ./Outputs/2a.out 2a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 3a... ")
rt = subprocess.call("diff ./Outputs/3a.out 3a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 4a... ")
rt = subprocess.call("diff ./Outputs/4a.out 4a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 5... ")
rt = subprocess.call("diff ./Outputs/5.out 5.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 5a... ")
rt = subprocess.call("diff ./Outputs/5a.out 5a.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")


print ("Passed " + str(passed) + " of 10 tests")
