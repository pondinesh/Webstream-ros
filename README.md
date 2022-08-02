# WEBCAMSTREAM IN ROS
---------------------

## Contents
-----------

- [Introduction](#introduction)
- [Installation](#installation)

  > [ROS-NOETIC](#ros-noetic) 
  
  > [OpenCV](#opencv)
  
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

![Thank You, Github](data:image/jpeg;base64,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)

