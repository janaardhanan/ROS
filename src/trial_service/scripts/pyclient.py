#!/usr/bin/env python3

from __future__ import print_function

import sys
import rospy
from trial_service.srv import SumProduct


def client(x,y):
    print("Waiting for service SumProduct")
    rospy.wait_for_service('SumProduct')
    print("Service Available")
    try:
        sp= rospy.ServiceProxy('SumProduct', SumProduct)
        resp1= sp(x,y)
        return (resp1.Sum, resp1.Product)
    except rospy.ServiceExceptionas as e:
        print("Service call failed: ",e)

    return ("a","b")



if __name__ == "__main__":
    if len(sys.argv)==3:
        x= int(sys.argv[1])
        y= int(sys.argv[2])
    else:
        print("%s [x y]"%sys.argv[0])
        sys.exit(1)
    print("Requesting sum and product of %s, %s"%(x,y))
    sum, product= client(x,y)
    print("Sum is ", sum, " and product is ", product)
