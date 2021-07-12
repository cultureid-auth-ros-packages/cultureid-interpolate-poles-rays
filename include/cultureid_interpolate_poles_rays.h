#ifndef CULTUREID_RFID_FOLLOWING_H
#define CULTUREID_RFID_FOLLOWING_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <limits>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"


class CIPR
{
  private:
    ros::NodeHandle nodehandle_;

    // List subscribers
    ros::Subscriber scan_sub_;

    // List publishers
    ros::Publisher scan_pub_;

    // List subscribed topics
    std::string base_scan_topic_;

    // List published topics
    std::string output_scan_topic_;

    // The indices of rays that sense poles
    std::vector<int> invalid_ids_;

    // The value that ranges get if their id is invalid
    // **CAUTION** Must match the value of regular rays that happen to be
    // invalid. For the ydlidar tg30 this value is 0
    float value_invalid_;

    // Either interpolate or just ignore the invalids
    bool do_interpolate_;


    // Functions
    void interpolateInvalidRaysInScan(const std::vector<float>& scan_in,
      std::vector<float>* scan_out);

    // List callbacks
    void scanCallback(const sensor_msgs::LaserScan::Ptr& scan_msg);

    // Init / helpers
    void loadInvalidIds();
    void loadParams();

    void test();


  public:
    CIPR(void);
    ~CIPR(void);
};

#endif
