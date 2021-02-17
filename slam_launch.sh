#!/bin/bash
source /home/toni/Documents/source_linux/ros_ws/oslam/devel/setup.bash

BAGPATH='/home/toni/Downloads/OS2_32G_ROSbag/OS2_32G_1024x20_sample.bag' #own path
CONFIGPATH='/home/toni/Downloads/OS2_32G_ROSbag/OS2_32G_1024x20.json' #own path

CARTOCONF='/home/toni/Documents/source_linux/ros_ws/oslam/src/ouster_slam' #own path

roslaunch ouster_slam os_slam.launch \
                             udp_hostname:=127.0.0.1 \
                             replay:=true \
                             bag_filename:=${BAGPATH}\
                             metadata:=${CONFIGPATH}\
                             carto_conf:=${CARTOCONF}