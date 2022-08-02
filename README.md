# WEBCAMSTREAM IN ROS
---------------------

## Contents
-----------

- [Introduction](#introduction)
- [Installation](#installation)
  - [ROS-NOETIC](#ros-noetic)
  - [OpenCV](#opencv)
- [Initialize](#initialize)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

<br><br>

## Introduction
---------------

Publishing a Webcam Stream in publisher node and Subscribe a stream using subscriber node and display the stream.

<br><br>

## Installation
---------------

### ROS-NOETIC

For running this package, you must install the ROS-noetic with OpenCV.
if you installed previously ignore this step!<br>
Installation of ROS-Noetic steps are given below. [ROS-Noetic](http://wiki.ros.org/noetic/Installation/Ubuntu/)<br>
(This Procedure is only ubuntu 20.04, because ROS-noetic is supported on 20.04)
<br><br>

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

<br><br>

### OpenCV

Installation of Opencv steps are given below. [OpenCV](https://docs.opencv.org/4.x/d2/de6/tutorial_py_setup_in_ubuntu.html)
<br><br>
#### OpenCV Installation

```bash
sudo apt-get install python3-opencv
```

#### OpenCV-contrib Installation

```bash
pip install opencv-contrib-python==3.4.4.19
```

<br><br>

## Initialize
-------------
 
### Creating Your Workspace

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

<br><br>

## Usage
--------

There are two types of publisher and subscriber in this package. They are,
  - [Python](#python)<br>
  - [Cpp](#cpp)

### Python

```bash
roslaunch Webstream-ros webcam_py.launch
```

### Cpp

```bash
roslaunch Webstream-ros webcam_cpp.launch
```

<br><br>
## Contributing
---------------

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.<br>
<br>
Doubt and Questioning are most encouraged.

<br><br>

## License
----------

Webstream-ros is primarily package under the terms of "both the MIT license and the Apache License (Version 2.0)", with portions covered by various BSD-like licenses.
<br><br>
See,
- [LICENSE-APACHE](http://www.apache.org/licenses/LICENSE-2.0),
- [LICENSE-MIT](https://choosealicense.com/licenses/mit/)
