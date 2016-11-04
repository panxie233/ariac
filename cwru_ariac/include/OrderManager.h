//
// Created by shipei on 11/1/16.
//

#ifndef CWRU_ARIAC_ORDERMANAGER_H
#define CWRU_ARIAC_ORDERMANAGER_H

#include <AriacBase.h>

class OrderManager: public AriacBase {
public:
    OrderManager(ros::NodeHandle nodeHandle);

    vector<osrf_gear::Goal> orders;

    bool startCompetition();
    bool submitOrder(int AGV, osrf_gear::Kit kit);
    bool isCompetitionEnd() {
        return (competitionState == "done");
    }
    double getCurrentScore() {
        return score;
    }

    double scoreFunction(double TT);

private:
    ros::NodeHandle nh_;
    ros::Time startTime;
    ros::Subscriber orderSubscriber;
    ros::Subscriber scoreSubscriber;
    ros::Subscriber competitionStateSubscriber;
    ros::ServiceClient AGV1Client;
    ros::ServiceClient AGV2Client;
    string competitionState;
    double score;
    void orderCallback(const osrf_gear::Goal::ConstPtr & goal_msg);
    void scoreCallback(const std_msgs::Float32::ConstPtr & msg);
    void competitionStateCallback(const std_msgs::String::ConstPtr & msg);
};


#endif //CWRU_ARIAC_ORDERMANAGER_H
