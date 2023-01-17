#include "ros/ros.h"
#include "trial_service/SumProduct.h"
#include "trial_service/Diff.h"

bool add(trial_service::SumProduct::Request &req, trial_service::SumProduct::Response &res)
{
    res.Sum= req.A+req.B;
    res.Product= req.A*req.B;
    ROS_INFO("Request: x=%ld, y=%ld", (long int)req.A, (long int)req.B);
    ROS_INFO("sending Back Sum=%ld, Product=%ld", (long int)res.Sum, (long int)res.Product);
    return true;
}

bool sub(trial_service::Diff::Request &req, trial_service::Diff::Response &res)
{
    long int diff= (req.P>req.Q)?req.P-req.Q: req.Q-req.P;
    res.Diff= diff;
    ROS_INFO("Request: P=%ld, Q=%ld", (long int)req.P, (long int)req.Q);
    ROS_INFO("Difference= %ld", diff);
    return true;    
}

int main(int argc, char **argv){
    ros::init(argc, argv, "cpp_server");
    ros::NodeHandle nh;

    ros::ServiceServer service= nh.advertiseService("SumProduct", add);
    ros::ServiceServer service2= nh.advertiseService("Diff", sub);
    ros::spin();

    return 0;
}