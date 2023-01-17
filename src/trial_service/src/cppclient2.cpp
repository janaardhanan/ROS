#include "ros/ros.h"
#include "trial_service/Diff.h"
#include <cstdlib>

int main(int argc, char **argv){
    ros::init(argc, argv, "diff_client");
    if (argc!=3){
        ROS_INFO("incorrect usage. use diff_client X Y");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<trial_service::Diff>("Diff");
    trial_service::Diff srv;
    srv.request.P= atoll(argv[1]);
    srv.request.Q= atoll(argv[2]);

    if(client.call(srv)){
        ROS_INFO("Diff: %ld", (long int)srv.response.Diff);
    }
    else{
        ROS_ERROR("Failed to call service Diff");
        return 1;
    }

    return 0;
}