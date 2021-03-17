Copyright 2021 Massachusetts Institute of Technology.  See License.txt

# SRanipal_LSL
Send eyetracking and pupilometry from the HTC Vive VR headset using a lab-streaming-layer stream.  
Author: Christopher Smalt.  Christopher.Smalt@LL.mit.edu

## Useage
1. Agree to and download the necessary files as described in Build Instructions below.
2. Build and launch the exe.  This will create a lab-streaming-layer stream.


## Build Instructions
Built using SRanipal C SDK  1.1.0.1 in Visual Studio 2019  
For details about lab-streaming-layer see: https://github.com/sccn/labstreaminglayer

### To build:

1. Download the SRanipal_SDK_1.0.1.1_Eye.zip (any other version should do)
from https://developer.vive.com/resources/knowledgebase/vive-sranipal-sdk/.
In the zip-file, find the Eye\01_C\ subdirectory. It contains (among others)
the following directories:  bin\\, include\\, lib\\
1. Copy these folders (Eye\01_C\bin, Eye\01_C\include, Eye\01_C\lib), into this directory (lib-labstreaminglayer\HTC-Vive-SRanipal).
2. Download the latest release of LSL (https://github.com/sccn/liblsl/releases/tag/v1.14.0)  
2. Copy the needed files in SRanipal_LSL\missing_files.txt into the SRanipal_LSL directory.
3.  Build in Visual Studio.


### To use precompiled program:
1. Download the SRanipal_SDK_1.0.1.1_Eye.zip (any other version should do)
from https://developer.vive.com/resources/knowledgebase/vive-sranipal-sdk/.
2. Copy the SRanipal SDK files specified in x64\Release\missing_files.txt into the x64\Release directory.
3.  Download the latest release of LSL (https://github.com/sccn/liblsl/releases/tag/v1.14.0)  
4. Copy the LSL SDK files specified in x64\Release\missing_files.txt into the x64\Release directory.
5.  Run the x64\Release\SRanipal_LSL.exe

## System Requirements 
Source: Vive SDK documentation

To use Vive SRanipal SDK plugin, the following minimum software and hardware requirements should be met:

**Software requirements**  
Windows 8.1 or later (64-bit)  
SteamVR (October 14 release or later)   
SR_Runtime 0.8.0.0 or later  

**Hardware requirements**  
Vive HMD with Eye capability  

**Limitations**  
Support Windows 64-bit only   
