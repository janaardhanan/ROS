#!/usr/bin/env python3

from __future__ import print_function

from trial_service.srv import SumProduct,SumProductResponse
import rospy

def add(req):
    sum= req.A+req.B
    prod= req.A*req.B
    print("Sum= %s, Product= %s" %(sum, prod))
    return SumProductResponse(Sum= sum, Product= prod)

def server():
    rospy.init_node('pyserver')
    s= rospy.Service('SumProduct', SumProduct, add)
    print("Server SumProduct is ready")
    rospy.spin()

if __name__== "__main__":
    server()