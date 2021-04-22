[![Generic badge](https://img.shields.io/badge/Maintained-No-green.svg)](https://shields.io/)
[![Generic badge](https://img.shields.io/badge/Software-Matlab,C-blue.svg)](https://shields.io/)
[![Generic badge](https://img.shields.io/badge/License-MIT-red.svg)](https://shields.io/)
[![DOI](https://zenodo.org/badge/348775436.svg)](https://zenodo.org/badge/latestdoi/348775436)

All software is Copyright 2021 Massachusetts Institute of Technology unless otherwise specified.  See License.md.

# Laboratory Streaming Layer Module Collection
A collection of research modules for Laboratory Streaming Layer (https://github.com/sccn/labstreaminglayer).
Each module can acclerate multi modal physiological research by augmenting the variety of waveforms a researcher can record with additional data and time synchronization capability.

## Contents

**SendLSLSsytemTime** (MIT License)  
Send the current computer clock time as a data stream.  Useful for synchronizing real time with LSL system time.   
Includes both the software and a compiled executable.  

**HTCVive** (MIT License but requires agreement with HTC SDK license for use)  
Collect eye tracking information from the HTC vive virtual reality headset.  Useful for virtual reality integration studies. 
Developed in part using the HTC vive SDK: https://developer.vive.com/resources/knowledgebase/vive-sranipal-sdk/  
The main.cpp file contains the principal code contributions.   

## Attribution Appreciated

Please use this DOI number reference, published on Zenodo, when citing the software: 

Bibtek  
```
@article{smalt2021LSL, 
title={mit-ll/Signal-Acquisition-Modules-for-Lab-Streaming-Layer: v1.0}, 
DOI={10.5281/zenodo.4612264}, abstractNote={<p>Initial release.</p>}, publisher={Zenodo}, 
author={Christopher Smalt and Hrishikesh Rao and Gregory Ciccarelli}, year={2021}, month={Mar}}
```

MLA  
```
Christopher Smalt, Hrishikesh Rao, & Gregory Ciccarelli. (2021, March 17). mit-ll/Signal-Acquisition-Modules-for-Lab-Streaming-Layer: v1.0 (Version v1.0). Zenodo. http://doi.org/10.5281/zenodo.4612264
```

## Disclaimer

DISTRIBUTION STATEMENT A. Approved for public release: distribution unlimited.

© 2021 MASSACHUSETTS INSTITUTE OF TECHNOLOGY

    Subject to FAR 52.227-11 – Patent Rights – Ownership by the Contractor (May 2014)
    SPDX-License-Identifier: MIT

This material is based upon work supported by the US Army Aeromedical Research Laboratory under Air Force Contract No. FA8702-15-D-0001. Any opinions, findings, conclusions or recommendations expressed in this material are those of the author(s) and do not necessarily reflect the views of the US Army.

The software/firmware is provided to you on an As-Is basis.