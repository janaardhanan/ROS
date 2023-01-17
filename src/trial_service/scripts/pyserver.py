#!/usr/bin/env python3

from __future__ import print_function

from trial_service.srv import SumProduct,SumProductResponse
from trial_service.srv import Diff,DiffResponse
import rospy

def add(req):
    sum= req.A+req.B
    prod= req.A*req.B
    print("Sum= %s, Product= %s" %(sum, prod))
    return SumProductResponse(Sum= sum, Product= prod)

def sub(req):
    p= int(req.P)
    q= int(req.Q)
    diff= (p-q) if (p>q) else (q-p)
    print("Difference= ",diff)
    return DiffResponse(diff)

def server():
    rospy.init_node('pyserver')
    s1= rospy.Service('SumProduct', SumProduct, add)
    s2= rospy.Service('Diff', Diff, sub)
    print("Server SumProduct and Diff are ready")
    rospy.spin()

if __name__== "__main__":
    server()