% Copyright 2020 Massachusetts Institute of Technology.  See License.txt
% Subject to FAR 52.227-11 – Patent Rights – Ownership by the Contractor (May 2014)
% SPDX-License-Identifier: MIT
%% instantiate the library

if ~isdeployed
    userDir = char(java.lang.System.getProperty('user.home'));
    try load(fullfile(userDir,'.gitpath.mat')); catch; GITPATH = uigetdir('Please select your Git base directory'); save(fullfile(userDir,'.gitpath.mat'),'GITPATH'); end
    addpath(fullfile(GITPATH,'lib-labstreaminglayer','liblsl-Matlab'));
    addpath(fullfile(GITPATH,'lib-labstreaminglayer','liblsl-Matlab','bin'));
end

interval=1; % time interval in seconds

disp('Loading library...');
lib = lsl_loadlib();

% make a new stream outlet
disp('Creating a new streaminfo...');
info = lsl_streaminfo(lib,'MatlabSystemTime','SysTime',1,1,'cf_double64','sdfwerr32131');

disp('Opening an outlet...');
outlet = lsl_outlet(info);

n = now;
fprintf('Current System time is...%s\ndatenum=%13.31f\n',datestr(n,'yyyy-mm-dd-HH:MM:SS:FFF'),n)

% send data into the outlet, sample by sample
fprintf('Now streaming date-time every %g secs to LSL...\n',interval);
while true
    outlet.push_sample(now);
    pause(interval);
end
