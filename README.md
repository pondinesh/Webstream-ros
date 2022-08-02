# WEBCAMSTREAM IN ROS
=====================

## Contents
-----------

.. contents::
   :local:

## Introduction
---------------

Publishing a Webcam Stream in publisher node and Subscribe a stream using subscriber node and display the stream.

## ROS-NOETIC & OpenCV Installation
-----------------------------------

For running this package, you must install the ROS-noetic with OpenCV.
if you had installed previously ignore this step!
Installation of ROS-Noetic steps are given below. [ROS-Noetic](http://wiki.ros.org/noetic/Installation/Ubuntu/)
(This Procedure is only ubuntu 20.04, because ROS-noetic is supported on 20.04)

#### Setup your sources.list

```bash
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
```

#### Set up your keys

```bash
sudo apt install curl
```

```bash
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
```

#### Installation

```bash
sudo apt update
```

```bash
sudo apt install ros-noetic-desktop-full
```

#### Environment setup

```bash
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
```

```bash
source ~/.bashrc
```

#### Dependencies for building packages

```bash
sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
```

#### Initialize rosdep

```bash
sudo apt install python3-rosdep
```

```bash
sudo rosdep init
```

```bash
rosdep update
```

Installation of ROS-Noetic steps are given below. [OpenCV](https://docs.opencv.org/4.x/d2/de6/tutorial_py_setup_in_ubuntu.html)

#### OpenCV Installation

```bash
sudo apt-get install python3-opencv
```

#### OpenCV-contrib Installation

```bash
pip install opencv-contrib-python==3.4.4.19
```

### Creating Your Workspace
---------------------------

If you had created the Workspace previously, then ignore this step!
Creating a Workspace steps are given below. [Worksapce](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)

```bash
mkdir -p ~/<Your-Workspace-name>/src
```

```bash
cd ~/<Your-Workspace-name>/
```

```bash
catkin_make
```

```bash
source devel/setup.bash
```

### Installation of package in Workspace
----------------------------------------

```bash
cd src/
```

```bash
git clone https://github.com/pondinesh/Webstream-ros.git
```

```bash
cd ~/<Your-Workspace-name>/
```

```bash
catkin_make
```

```bash
source devel/setup.bash
```

## Usage
--------

There are two types of publisher and subscriber in our package. They are,
	.. Python
	.. C++

### Pyhton

```bash
roslaunch Webstream-ros webcam_py.launch
```

### C++

```bash
roslaunch Webstream-ros webcam_cpp.launch
```

## Contributing
---------------

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Doubt and Questioning are most encouraged.

## License
----------

[MIT](https://choosealicense.com/licenses/mit/)
