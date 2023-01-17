#include "ros/ros.h"
#include "trial_service/SumProduct.h"

bool add(trial_service::SumProduct::Request &req, trial_service::SumProduct::Response &res)
{
    res.Sum= req.A+req.B;
    res.Product= req.A*req.B;
    ROS_INFO("Request: x=%ld, y=%ld", (long int)req.A, (long int)req.B);
    ROS_INFO("sending Back Sum=%ld, Product=%ld", (long int)res.Sum, (long int)res.Product);
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "sum_sroduct_server");
    ros::NodeHandle nh;

    ros::ServiceServer service= nh.advertiseService("SumProduct", add);
    ros::spin();

    return 0;
}