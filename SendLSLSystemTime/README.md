Copyright 2021 Massachusetts Institute of Technology.  See License.txt

# SendLSLSystemTime
Send the current computer clock time as a data stream.  Useful for synchronizing real time with LSL system time.   
Includes both the software and a compiled executable.  

## Useage
1. Install MCRInstaller from MathWorks for R2019b (https://www.mathworks.com/products/compiler/matlab-runtime.html)
2. Launch SendLSLSystemTime.exe.  This starts an LSL stream.

## Alternate Useage if Matlab is installed
1. Run sendLSLSystemTime.m in Matlab.  This starts an LSL stream.

## Development notes  
SendLSLSystemTime.m was adapted from  
https://github.com/labstreaminglayer/liblsl-Matlab/blob/master/examples/SendDataInChunks.m  
available under the MIT License.
