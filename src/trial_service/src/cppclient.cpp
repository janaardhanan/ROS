#include "ros/ros.h"
#include "trial_service/SumProduct.h"
#include <cstdlib>

int main(int argc, char **argv){
    ros::init(argc, argv, "sum_product_client");
    if (argc!=3){
        ROS_INFO("incorrect usage. use sum_product_client X Y");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<trial_service::SumProduct>("SumProduct");
    trial_service::SumProduct srv;
    srv.request.A= atoll(argv[1]);
    srv.request.B= atoll(argv[2]);

    if(client.call(srv)){
        ROS_INFO("Sum: %ld, Product: %ld", (long int)srv.response.Sum, (long int)srv.response.Product);
    }
    else{
        ROS_ERROR("Failed to call service SumProduct");
        return 1;
    }

    return 0;
}