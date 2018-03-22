#!/usr/bin/env python
import subprocess

passed = 0

print ("Generating output 1... ")
subprocess.call("./dqtest1 > ./Tests/dq1.gt",shell=True)
print ("Generating output 2... ")
subprocess.call("./dqtest2 > ./Tests/dq2.gt",shell=True)
print ("Generating output 3... ")
subprocess.call("./dqtest3 > ./Tests/dq3.gt",shell=True)
print ("Generating output 4... ")
subprocess.call("./dqtest4 > ./Tests/dq4.gt",shell=True)
print ("Generating output 7... ")
subprocess.call("./dqtest7 > ./Tests/dq7.gt",shell=True)


print ("Running test 1... ")
rt = subprocess.call("diff ./Tests/output1 ./Tests/dq1.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 2... ")
rt = subprocess.call("diff ./Tests/output2 ./Tests/dq2.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 3... ")
rt = subprocess.call("diff ./Tests/output3 ./Tests/dq3.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")

print ("Running test 4... ")
rt = subprocess.call("diff ./Tests/output4 ./Tests/dq4.gt",shell=True);
if rt == 0:
    passed += 1
    print ("passed")
else:
    print ("failed")


print ("Passed " + str(passed) + " of 4 tests")
