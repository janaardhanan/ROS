#!/usr/bin/env python3

from __future__ import print_function

import sys
import rospy
from trial_service.srv import Diff


def client(x,y):
    print("Waiting for service Diff")
    rospy.wait_for_service('Diff')
    try:
        sp= rospy.ServiceProxy('Diff', Diff)
        resp1= sp(x,y)
        return (resp1.Diff)
    except rospy.ServiceExceptionas as e:
        print("Service call failed: ",e)


if __name__ == "__main__":
    if len(sys.argv)==3:
        x= int(sys.argv[1])
        y= int(sys.argv[2])
    else:
        print("%s [x y]"%sys.argv[0])
        sys.exit(1)
    print("Requesting sum and product of %s, %s"%(x,y))
    diff= client(x,y)
    print("Difference= ", diff)
