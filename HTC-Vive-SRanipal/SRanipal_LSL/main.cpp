// Copyright 2020 Massachusetts Institute of Technology.  
// Subject to FAR 52.227-11 – Patent Rights – Ownership by the Contractor (May 2014)
// SPDX-License-Identifier: MIT
// See License.txt

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <thread>
#include "SRanipal.h"
#include "SRanipal_Eye.h"
#include "SRanipal_Lip.h"
#include "SRanipal_Enums.h"
#include "lsl_cpp.h"
#include <iostream>
#include <string>
#pragma comment (lib, "SRanipal.lib")
using namespace ViveSR;
using namespace std;


std::thread *t = nullptr;
bool EnableEye = false;
bool EnableLip = false;
bool looping = false;
void streaming() {

	string name, type;
	type = "EyeTracking";
	name = "ViveProEye";
	int NumChannels=26;
	float sample[26];

	const char* channels[] = { "validL","validR","gazeoriginL_X","gazeoriginL_Y","gazeoriginL_Z","gazeoriginR_X","gazeoriginR_Y","gazeoriginR_Z","gazeL_X","gazeL_Y","gazeL_Z","gazeR_X","gazeR_Y","gazeR_Z","pupilL","pupilR", "eye_opennessL","eye_opennessR","pupilLSensorPosL_X","pupilLSensorPosL_Y" ,"pupilLSensorPosL_Z" ,"pupilLSensorPosR_X" ,"pupilLSensorPosR_Y","pupilLSensorPosR_Z","convergence_distance_mm","convergence_distance_validity" };
	const char* units[] = { "bool","bool","mm","mm","mm","mm","mm","mm","mm","mm","mm","mm","mm","mm" ,"mm","mm","mm","mm", "mm","mm", "mm","mm", "mm","mm", "mm","bool"};

	// LSL
			// make a new stream_info (100 Hz)
	lsl::stream_info info(name, type, 26, 250, lsl::cf_float32, string(name) += type);

	// add some description fields
	info.desc().append_child_value("manufacturer", "ViveProEye");
	lsl::xml_element chns = info.desc().append_child("channels");
	for (int k = 0; k < NumChannels; k++)
		chns.append_child("channel")
		.append_child_value("label", channels[k])
		.append_child_value("unit", units[k])
		.append_child_value("type", "eyetracking");

	// make a new outlet
	lsl::stream_outlet outlet(info);

	// send data forever
	cout << "Now sending data... " << endl;
	// END LSL



	ViveSR::anipal::Eye::EyeData eye_data;
	ViveSR::anipal::Lip::LipData lip_data;
    char lip_image[800 * 400];
	lip_data.image = lip_image;

	int result = ViveSR::Error::WORK;
	while (looping) {
		if (EnableEye) {
			int result = ViveSR::anipal::Eye::GetEyeData(&eye_data);
			if (result == ViveSR::Error::WORK) {

				bool validL = eye_data.verbose_data.left.eye_data_validata_bit_mask;
				bool validR = eye_data.verbose_data.right.eye_data_validata_bit_mask;

				float* gazeoriginL = eye_data.verbose_data.left.gaze_origin_mm.elem_;
				float* gazeoriginR = eye_data.verbose_data.right.gaze_origin_mm.elem_;

				float *gazeL = eye_data.verbose_data.left.gaze_direction_normalized.elem_;
				float* gazeR = eye_data.verbose_data.right.gaze_direction_normalized.elem_;
							   
				float pupilL = eye_data.verbose_data.left.pupil_diameter_mm;
				float pupilR = eye_data.verbose_data.right.pupil_diameter_mm;

				float eye_opennessL = eye_data.verbose_data.left.eye_openness;
				float eye_opennessR = eye_data.verbose_data.right.eye_openness;
				
				float* pupilLSensorPos = eye_data.verbose_data.left.pupil_position_in_sensor_area.elem_;
				float* pupilRSensorPos = eye_data.verbose_data.right.pupil_position_in_sensor_area.elem_;

				float convergence_distance_mm = eye_data.verbose_data.combined.convergence_distance_mm;
				bool  convergence_distance_validity = eye_data.verbose_data.combined.convergence_distance_validity;


		
				sample[0] = validL;
				sample[1] = validR;

				sample[2] = gazeoriginL[0];
				sample[3] = gazeoriginL[1];
				sample[4] = gazeoriginL[2];
				sample[5] = gazeoriginR[0];
				sample[6] = gazeoriginR[1];
				sample[7] = gazeoriginR[2];

				sample[8] = gazeL[0];
				sample[9] = gazeL[1];
				sample[10] = gazeL[2];
				sample[11] = gazeR[0];
				sample[12] = gazeR[1];
				sample[13] = gazeR[2];

				sample[14] = pupilL;
				sample[15] = pupilR;

				sample[16] = eye_opennessL;
				sample[17] = eye_opennessR;

				sample[19] = pupilLSensorPos[0];
				sample[20] = pupilLSensorPos[1];
				sample[21] = pupilLSensorPos[2];
				sample[22] = pupilRSensorPos[0];
				sample[23] = pupilRSensorPos[1];
				sample[23] = pupilRSensorPos[2];

				sample[25] = convergence_distance_mm;
				sample[26] = convergence_distance_validity;





				// send the sample
				outlet.push_sample(sample);
				


				printf("[Eye] Gaze: %.2f %.2f %.2f %.2f %.2f %.2f\n", gazeL[0], gazeL[1], gazeL[2], gazeR[0], gazeR[1], gazeR[2]);
			}
		}
        if (EnableLip) {
			result = ViveSR::anipal::Lip::GetLipData(&lip_data);
			if (result == ViveSR::Error::WORK) {
				float *weightings = lip_data.prediction_data.blend_shape_weight;
				printf("[Lip] frame: %d, time: %d, weightings %.2f\n", lip_data.frame_sequence, lip_data.timestamp, weightings[0]);
			}
		}
	}
}

int main() {
	printf("SRanipal Sample\n\nPlease refer the below hotkey list to try apis.\n");
	printf("[`] Exit this program.\n");
	printf("[0] Release all anipal engines.\n");
	printf("[1] Initial Eye engine\n");
    printf("[2] Initial Lip engine\n");
	printf("[3] Launch a thread to query data.\n");
	printf("[4] Stop the thread.\n");
	
	if(!ViveSR::anipal::Eye::IsViveProEye()){
		printf("\n\nthis device does not have eye-tracker, please change your HMD\n");
		return 0;
	}
	char str = 0;
	int error, handle = NULL;
	while (true) {
		if (str != '\n' && str != EOF) { printf("\nwait for key event :"); }
		str = getchar();
		if (str == '`') break;
		else if (str == '0') {
			error = ViveSR::anipal::Release(ViveSR::anipal::Eye::ANIPAL_TYPE_EYE);
			printf("Successfully release all anipal engines.\n");
			EnableEye = false;
		}
		else if (str == '1') {
			error = ViveSR::anipal::Initial(ViveSR::anipal::Eye::ANIPAL_TYPE_EYE, NULL);
			if (error == ViveSR::Error::WORK) { EnableEye = true; printf("Successfully initialize Eye engine.\n"); }
			else if (error == ViveSR::Error::RUNTIME_NOT_FOUND) printf("please follows SRanipal SDK guide to install SR_Runtime first\n");
			else printf("Fail to initialize Eye engine. please refer the code %d of ViveSR::Error.\n", error);
		}
        else if (str == '2') {
			error = ViveSR::anipal::Initial(ViveSR::anipal::Lip::ANIPAL_TYPE_LIP, NULL);
			if (error == ViveSR::Error::WORK) { EnableLip = true; printf("Successfully initialize Lip engine.\n"); }
			else if (error == ViveSR::Error::RUNTIME_NOT_FOUND) printf("please follows SRanipal SDK guide to install SR_Runtime first\n");
			else printf("Fail to initialize Lip engine. please refer the code %d of ViveSR::Error.\n", error);
		}
        else if (str == '3') {
            if (t == nullptr) {
                t = new std::thread(streaming);
                if (t)   looping = true;
            }
        }
        else if (str == '4') {
            looping = false;
            if (t == nullptr) continue;
            t->join();
            delete t;
            t = nullptr;
        } 
	}
	ViveSR::anipal::Release(ViveSR::anipal::Eye::ANIPAL_TYPE_EYE);
    ViveSR::anipal::Release(ViveSR::anipal::Lip::ANIPAL_TYPE_LIP);
}
 
