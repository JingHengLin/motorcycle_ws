#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source ${DIR}/../../devel/setup.bash
My_Gazebo_Model_Path="$( cd "${DIR}/../models" && pwd )"
export GAZEBO_MODEL_PATH=$My_Gazebo_Model_Path:
alias add_model="ls ${My_Gazebo_Model_Path} && rosrun fira_gz add_model"

