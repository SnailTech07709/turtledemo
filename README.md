# turtledemo
cd turtledemo
catkin_make
#再开一个终端
roscore
rosrun turtlesim turtlesim_node
#cd到turtledemo文件夹根目录
#右键打开新终端
source ./devel/setup.bash
rosurun turtledemo turtlePub
