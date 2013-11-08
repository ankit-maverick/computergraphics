#include <iostream>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>

#include "classes.h"
#include "humanBody.h"

using namespace std;

int num_keyframes = 0;
int num_interpolated = 0;
int num_kf_parameters = 48;
int playback_frame_no = 0;
int between_frames = 10;

// Interpolated values
    float eye_x_int[15000];
    float eye_y_int[15000];
    float eye_z_int[15000];
    float center_x_int[15000];
    float center_y_int[15000];
    float center_z_int[15000];
    bool light0_int[15000];
    bool light1_int[15000];
    int lid_angle_int[15000];
    float dancer_pos_int[15000];
    int rotate_x_int[15000];
    int rotate_y_int[15000];
    int rotate_z_int[15000];
    int rot_neck_x_int[15000];
    int rot_neck_y_int[15000];
    int rot_neck_z_int[15000];
    int rot_right_shoulder_x_int[15000];
    int rot_right_shoulder_y_int[15000];
    int rot_right_shoulder_z_int[15000];
    int rot_left_shoulder_x_int[15000];
    int rot_left_shoulder_y_int[15000];
    int rot_left_shoulder_z_int[15000];
    int rot_right_elbow_int[15000];
    int rot_left_elbow_int[15000];
    int rot_right_wrist_x_int[15000];
    int rot_left_wrist_x_int[15000];
    int rot_right_wrist_y_int[15000];
    int rot_left_wrist_y_int[15000];
    int rot_right_wrist_z_int[15000];
    int rot_left_wrist_z_int[15000];
    int rot_right_hip_x_int[15000];
    int rot_right_hip_y_int[15000];
    int rot_right_hip_z_int[15000];
    int rot_left_hip_x_int[15000];
    int rot_left_hip_y_int[15000];
    int rot_left_hip_z_int[15000];
    int rot_right_knee_int[15000];
    int rot_left_knee_int[15000];
    int rot_right_ankle_x_int[15000];
    int rot_left_ankle_x_int[15000];
    int rot_right_ankle_y_int[15000];
    int rot_left_ankle_y_int[15000];
    int rot_right_ankle_z_int[15000];
    int rot_left_ankle_z_int[15000];
    int rot_torso2_x_int[15000];
    int rot_torso2_y_int[15000];
    int rot_torso2_z_int[15000];
    float mouthspeak_int[15000];


bool isbool(string str){
    if (str == "1") return true;
    else return false;
}

// writing on a text file
int write_keyframe() {

    // Delimiter
    string dlmtr = ",";

    ofstream myfile ("keyframes.txt", std::ios_base::app);
    if (myfile.is_open())
    {
        myfile << eye_x <<  dlmtr << eye_y << dlmtr << eye_z << dlmtr << center_x << dlmtr << center_y << dlmtr << center_z << dlmtr << light0 << dlmtr << light1 << dlmtr << lid_angle << dlmtr << dancer_pos << dlmtr << rotate_x << dlmtr << rotate_y << dlmtr << rotate_z << dlmtr << rot_neck_x << dlmtr << rot_neck_y << dlmtr << rot_neck_z << dlmtr << rot_right_shoulder_x << dlmtr << rot_right_shoulder_y << dlmtr << rot_right_shoulder_z << dlmtr << rot_left_shoulder_x << dlmtr << rot_left_shoulder_y << dlmtr << rot_left_shoulder_z << dlmtr << rot_right_elbow << dlmtr << rot_left_elbow << dlmtr << rot_right_wrist_x << dlmtr << rot_right_wrist_y << dlmtr << rot_right_wrist_z << dlmtr << rot_left_wrist_x << dlmtr << rot_left_wrist_y << dlmtr << rot_left_wrist_z << dlmtr << rot_right_hip_x << dlmtr << rot_right_hip_y << dlmtr << rot_right_hip_z << dlmtr << rot_left_hip_x << dlmtr << rot_left_hip_y << dlmtr << rot_left_hip_z << dlmtr << rot_right_knee << dlmtr << rot_left_knee << dlmtr << rot_right_ankle_x << dlmtr << rot_right_ankle_y << dlmtr << rot_right_ankle_z << dlmtr << rot_left_ankle_x << dlmtr << rot_left_ankle_y << dlmtr << rot_left_ankle_z << dlmtr << rot_torso2_x << dlmtr << rot_torso2_y << dlmtr << rot_torso2_z << dlmtr << mouthspeak <<"\n";
        num_keyframes = num_keyframes + 1;
        myfile.close();
    }
    else cout << "Unable to open file";
    return 0;
}



// clearing the text file
void clear_keyframes(){
    ofstream myfile;
    myfile.open ("keyframes.txt", std::ofstream::out | std::ofstream::trunc);
    num_keyframes = 0;
    myfile.close();
}




// playback : update the params and glutPostRedisplay
void playback(int temp){
    // update parameters
    eye_x = eye_x_int[playback_frame_no];
    eye_y = eye_y_int[playback_frame_no];
    eye_z = eye_z_int[playback_frame_no];
    center_x = center_x_int[playback_frame_no];
    center_y = center_y_int[playback_frame_no];
    center_z = center_z_int[playback_frame_no];
    light0 = light0_int[playback_frame_no];
    light1 = light1_int[playback_frame_no];
    lid_angle = lid_angle_int[playback_frame_no];
    dancer_pos = dancer_pos_int[playback_frame_no];
    rotate_x = rotate_x_int[playback_frame_no];
    rotate_y = rotate_y_int[playback_frame_no];
    rotate_z = rotate_z_int[playback_frame_no];
    rot_neck_x =rot_neck_x_int[playback_frame_no];
    rot_neck_y = rot_neck_y_int[playback_frame_no];
    rot_neck_z = rot_neck_z_int[playback_frame_no];
    rot_right_shoulder_x = rot_right_shoulder_x_int[playback_frame_no];
    rot_right_shoulder_y = rot_right_shoulder_y_int[playback_frame_no];
    rot_right_shoulder_z = rot_right_shoulder_z_int[playback_frame_no];
    rot_left_shoulder_x = rot_left_shoulder_x_int[playback_frame_no];
    rot_left_shoulder_y = rot_left_shoulder_y_int[playback_frame_no];
    rot_left_shoulder_z = rot_left_shoulder_z_int[playback_frame_no];
    rot_right_elbow = rot_right_elbow_int[playback_frame_no];
    rot_left_elbow =rot_left_elbow_int[playback_frame_no];
    rot_right_wrist_x = rot_right_wrist_x_int[playback_frame_no];
    rot_left_wrist_x = rot_left_wrist_x_int[playback_frame_no];
    rot_right_wrist_y = rot_right_wrist_y_int[playback_frame_no];
    rot_left_wrist_y = rot_left_wrist_y_int[playback_frame_no];
    rot_right_wrist_z = rot_right_wrist_z_int[playback_frame_no];
    rot_left_wrist_z = rot_left_wrist_z_int[playback_frame_no];
    rot_right_hip_x = rot_right_hip_x_int[playback_frame_no];
    rot_right_hip_y = rot_right_hip_y_int[playback_frame_no];
    rot_right_hip_z = rot_right_hip_z_int[playback_frame_no];
    rot_left_hip_x = rot_left_hip_x_int[playback_frame_no];
    rot_left_hip_y = rot_left_hip_y_int[playback_frame_no];
    rot_left_hip_z = rot_left_hip_z_int[playback_frame_no];
    rot_right_knee = rot_right_knee_int[playback_frame_no];
    rot_left_knee = rot_left_knee_int[playback_frame_no];
    rot_right_ankle_x = rot_right_ankle_x_int[playback_frame_no];
    rot_left_ankle_x = rot_left_ankle_x_int[playback_frame_no];
    rot_right_ankle_y = rot_right_ankle_y_int[playback_frame_no];
    rot_left_ankle_y = rot_left_ankle_y_int[playback_frame_no];
    rot_right_ankle_z = rot_right_ankle_z_int[playback_frame_no];
    rot_left_ankle_z = rot_left_ankle_z_int[playback_frame_no];
    rot_torso2_x = rot_torso2_x_int[playback_frame_no];
    rot_torso2_y = rot_torso2_y_int[playback_frame_no];
    rot_torso2_z = rot_torso2_z_int[playback_frame_no];
    mouthspeak = mouthspeak_int[playback_frame_no];

    cerr << "Playback Frame no : " <<  playback_frame_no<<endl;
    glutPostRedisplay();

    playback_frame_no++;

    if (playback_frame_no < num_interpolated){
        glutTimerFunc(50, playback, 0);
    }

}



// reading a text file
int read_keyframes_and_playback() {


    string kf_parameters[num_keyframes][num_kf_parameters];

    ifstream myfile ("keyframes.txt");
    if (myfile.is_open()){
        for(int i=0; i<num_keyframes; i++){
            for(int j=0; j<num_kf_parameters; j++){
                if (j==num_kf_parameters-1){
                    getline(myfile, kf_parameters[i][j]);
                }
                else{
                    getline(myfile, kf_parameters[i][j], ',');
                }
            }
        }

        myfile.close();
    }
    else {cout << "Unable to open file";} 

    /*
    int count = 0;
    for (int t= 0; t<num_keyframes; t++)
    {
    for(int u = 0; u <num_kf_parameters; u++)
    {
    cerr << t<< " "<< u<< "    "<<kf_parameters[t][u] << "   " << count<< endl;
    count++;
    }
    }
    */

    // Initialize arrays for storing keyframe variables
    float eye_x_kf[num_keyframes];
    float eye_y_kf[num_keyframes];
    float eye_z_kf[num_keyframes];
    float center_x_kf[num_keyframes];
    float center_y_kf[num_keyframes];
    float center_z_kf[num_keyframes];
    bool light0_kf[num_keyframes];
    bool light1_kf[num_keyframes];
    int lid_angle_kf[num_keyframes];
    float dancer_pos_kf[num_keyframes];
    int rotate_x_kf[num_keyframes];
    int rotate_y_kf[num_keyframes];
    int rotate_z_kf[num_keyframes];
    int rot_neck_x_kf[num_keyframes];
    int rot_neck_y_kf[num_keyframes];
    int rot_neck_z_kf[num_keyframes];
    int rot_right_shoulder_x_kf[num_keyframes];
    int rot_right_shoulder_y_kf[num_keyframes];
    int rot_right_shoulder_z_kf[num_keyframes];
    int rot_left_shoulder_x_kf[num_keyframes];
    int rot_left_shoulder_y_kf[num_keyframes];
    int rot_left_shoulder_z_kf[num_keyframes];
    int rot_right_elbow_kf[num_keyframes];
    int rot_left_elbow_kf[num_keyframes];
    int rot_right_wrist_x_kf[num_keyframes];
    int rot_right_wrist_y_kf[num_keyframes];
    int rot_right_wrist_z_kf[num_keyframes];
    int rot_left_wrist_x_kf[num_keyframes];
    int rot_left_wrist_y_kf[num_keyframes];
    int rot_left_wrist_z_kf[num_keyframes];
    int rot_right_hip_x_kf[num_keyframes];
    int rot_right_hip_y_kf[num_keyframes];
    int rot_right_hip_z_kf[num_keyframes];
    int rot_left_hip_x_kf[num_keyframes];
    int rot_left_hip_y_kf[num_keyframes];
    int rot_left_hip_z_kf[num_keyframes];
    int rot_right_knee_kf[num_keyframes];
    int rot_left_knee_kf[num_keyframes];
    int rot_right_ankle_x_kf[num_keyframes];
    int rot_right_ankle_y_kf[num_keyframes];
    int rot_right_ankle_z_kf[num_keyframes];
    int rot_left_ankle_x_kf[num_keyframes];
    int rot_left_ankle_y_kf[num_keyframes];
    int rot_left_ankle_z_kf[num_keyframes];
    int rot_torso2_x_kf[num_keyframes];
    int rot_torso2_y_kf[num_keyframes];
    int rot_torso2_z_kf[num_keyframes];
    float mouthspeak_kf[num_keyframes];

    for(int p=0; p<num_kf_parameters; p++){
        //cerr << "p : " << p << endl;
        if (p==0){
            for(int q=0; q<num_keyframes; q++){
                eye_x_kf[q] = atof(kf_parameters[q][p].c_str());
            }
        }
        else if (p==1){
            for(int q=0; q<num_keyframes; q++){
                eye_y_kf[q] = atof(kf_parameters[q][p].c_str());
            }
        }
        else if (p==2){
            for(int q=0; q<num_keyframes; q++){
                eye_z_kf[q] = atof(kf_parameters[q][p].c_str());
            }
        }
        else if (p==3){
            for(int q=0; q<num_keyframes; q++){
                center_x_kf[q] = atof(kf_parameters[q][p].c_str());
            }
        }
        else if (p==4){
            for(int q=0; q<num_keyframes; q++){
                center_y_kf[q] = atof(kf_parameters[q][p].c_str());
            }
        }
        else if (p==5){
            for(int q=0; q<num_keyframes; q++){
                center_z_kf[q] = atof(kf_parameters[q][p].c_str());
            }
        }
        else if (p==6){
            for(int q=0; q<num_keyframes; q++){
                light0_kf[q] = isbool(kf_parameters[q][p]);
            }
        }
        else if (p==7){
            for(int q=0; q<num_keyframes; q++){
                light1_kf[q] = isbool(kf_parameters[q][p]);
            }
        }
        else if (p==8){
            for(int q=0; q<num_keyframes; q++){
                lid_angle_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==9){
            for(int q=0; q<num_keyframes; q++){
                dancer_pos_kf[q] = atof(kf_parameters[q][p].c_str());
            }
        }
        else if (p==10){
            for(int q=0; q<num_keyframes; q++){
                rotate_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==11){
            for(int q=0; q<num_keyframes; q++){
                rotate_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==12){
            for(int q=0; q<num_keyframes; q++){
                rotate_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==13){
            for(int q=0; q<num_keyframes; q++){
                rot_neck_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==14){
            for(int q=0; q<num_keyframes; q++){
                rot_neck_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==15){
            for(int q=0; q<num_keyframes; q++){
                rot_neck_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==16){
            for(int q=0; q<num_keyframes; q++){
                rot_right_shoulder_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==17){
            for(int q=0; q<num_keyframes; q++){
                rot_right_shoulder_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==18){
            for(int q=0; q<num_keyframes; q++){
                rot_right_shoulder_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==19){
            for(int q=0; q<num_keyframes; q++){
                rot_left_shoulder_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==20){
            for(int q=0; q<num_keyframes; q++){
                rot_left_shoulder_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==21){
            for(int q=0; q<num_keyframes; q++){
                rot_left_shoulder_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==22){
            for(int q=0; q<num_keyframes; q++){
                rot_right_elbow_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==23){
            for(int q=0; q<num_keyframes; q++){
                rot_left_elbow_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==24){
            for(int q=0; q<num_keyframes; q++){
                rot_right_wrist_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==25){
            for(int q=0; q<num_keyframes; q++){
                rot_right_wrist_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==26){
            for(int q=0; q<num_keyframes; q++){
                rot_right_wrist_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==27){
            for(int q=0; q<num_keyframes; q++){
                rot_left_wrist_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==28){
            for(int q=0; q<num_keyframes; q++){
                rot_left_wrist_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==29){
            for(int q=0; q<num_keyframes; q++){
                rot_left_wrist_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==30){
            for(int q=0; q<num_keyframes; q++){
                rot_right_hip_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==31){
            for(int q=0; q<num_keyframes; q++){
                rot_right_hip_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==32){
            for(int q=0; q<num_keyframes; q++){
                rot_right_hip_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==33){
            for(int q=0; q<num_keyframes; q++){
                rot_left_hip_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==34){
            for(int q=0; q<num_keyframes; q++){
                rot_left_hip_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==35){
            for(int q=0; q<num_keyframes; q++){
                rot_left_hip_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==36){
            for(int q=0; q<num_keyframes; q++){
                rot_right_knee_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==37){
            for(int q=0; q<num_keyframes; q++){
                rot_left_knee_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==38){
            for(int q=0; q<num_keyframes; q++){
                rot_right_ankle_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==39){
            for(int q=0; q<num_keyframes; q++){
                rot_right_ankle_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==40){
            for(int q=0; q<num_keyframes; q++){
                rot_right_ankle_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==41){
            for(int q=0; q<num_keyframes; q++){
                rot_left_ankle_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==42){
            for(int q=0; q<num_keyframes; q++){
                rot_left_ankle_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==43){
            for(int q=0; q<num_keyframes; q++){
                rot_left_ankle_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==44){
            for(int q=0; q<num_keyframes; q++){
                rot_torso2_x_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==45){
            for(int q=0; q<num_keyframes; q++){
                rot_torso2_y_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==46){
            for(int q=0; q<num_keyframes; q++){
                rot_torso2_z_kf[q] = atoi(kf_parameters[q][p].c_str());
            }
        }
        else if (p==47){
            for(int q=0; q<num_keyframes; q++){
                mouthspeak_kf[q] = atof(kf_parameters[q][p].c_str());
            }
        }
    }


    // Initialize arrays for storing interpolated keyframe values
    num_interpolated = (num_keyframes - 1)*between_frames + 1;

    // Interpolate and store each variable
    for(int g=0; g<num_keyframes-1;g++){
        float dx = (eye_x_kf[g+1] - eye_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            eye_x_int[g*between_frames + h] = eye_x_kf[g] + h*dx;
            //cerr << g*between_frames + h << "  " << eye_x_int[g*between_frames + h] << endl;
        }
        eye_x_int[num_interpolated-1] = eye_x_kf[num_keyframes-1];

    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (eye_y_kf[g+1] - eye_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            eye_y_int[g*between_frames + h] = eye_y_kf[g] + h*dx;
        }
        eye_y_int[num_interpolated-1] = eye_y_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (eye_z_kf[g+1] - eye_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            eye_z_int[g*between_frames + h] = eye_z_kf[g] + h*dx;
        }
        eye_z_int[num_interpolated-1] = eye_z_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (center_x_kf[g+1] - center_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            center_x_int[g*between_frames + h] = center_x_kf[g] + h*dx;
        }
        center_x_int[num_interpolated-1] = center_x_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (center_y_kf[g+1] - center_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            center_y_int[g*between_frames + h] = center_y_kf[g] + h*dx;
        }
        center_y_int[num_interpolated-1] = center_y_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (center_z_kf[g+1] - center_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            center_z_int[g*between_frames + h] = center_z_kf[g] + h*dx;
        }
        center_z_int[num_interpolated-1] = center_z_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        //float dx = (center_z_kf[g+1] - center_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            light0_int[g*between_frames + h] = light0_kf[g];
            cerr << g*between_frames + h << "  " << light0_int[g*between_frames + h] << endl;
        }
        light0_int[num_interpolated-1] = light0_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        //float dx = (center_z_kf[g+1] - center_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            light1_int[g*between_frames + h] = light1_kf[g];
        }
        light1_int[num_interpolated-1] = light1_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (lid_angle_kf[g+1] - lid_angle_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = lid_angle_kf[g] + h*dx;
            lid_angle_int[g*between_frames + h] = (int)int_val;
        }
        lid_angle_int[num_interpolated-1] = lid_angle_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (dancer_pos_kf[g+1] - dancer_pos_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            dancer_pos_int[g*between_frames + h] = dancer_pos_kf[g] + h*dx;
        }
        dancer_pos_int[num_interpolated-1] = dancer_pos_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rotate_x_kf[g+1] - rotate_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rotate_x_kf[g] + h*dx;
            rotate_x_int[g*between_frames + h] = (int)int_val;
        }
        rotate_x_int[num_interpolated-1] = rotate_x_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rotate_y_kf[g+1] - rotate_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rotate_y_kf[g] + h*dx;
            rotate_y_int[g*between_frames + h] = (int)int_val;
        }
        rotate_y_int[num_interpolated-1] = rotate_y_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rotate_z_kf[g+1] - rotate_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rotate_z_kf[g] + h*dx;
            rotate_z_int[g*between_frames + h] = (int)int_val;
        }
        rotate_z_int[num_interpolated-1] = rotate_z_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_neck_x_kf[g+1] - rot_neck_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_neck_x_kf[g] + h*dx;
            rot_neck_x_int[g*between_frames + h] = (int)int_val;
        }
        rot_neck_x_int[num_interpolated-1] = rot_neck_x_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_neck_y_kf[g+1] - rot_neck_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_neck_y_kf[g] + h*dx;
            rot_neck_y_int[g*between_frames + h] = (int)int_val;
        }
        rot_neck_y_int[num_interpolated-1] = rot_neck_y_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_neck_z_kf[g+1] - rot_neck_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_neck_z_kf[g] + h*dx;
            rot_neck_z_int[g*between_frames + h] = (int)int_val;
        }
        rot_neck_z_int[num_interpolated-1] = rot_neck_z_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_shoulder_x_kf[g+1] - rot_right_shoulder_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_shoulder_x_kf[g] + h*dx;
            rot_right_shoulder_x_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_shoulder_x_int[num_interpolated-1] = rot_right_shoulder_x_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_shoulder_y_kf[g+1] - rot_right_shoulder_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_shoulder_y_kf[g] + h*dx;
            rot_right_shoulder_y_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_shoulder_y_int[num_interpolated-1] = rot_right_shoulder_y_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_shoulder_z_kf[g+1] - rot_right_shoulder_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_shoulder_z_kf[g] + h*dx;
            rot_right_shoulder_z_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_shoulder_z_int[num_interpolated-1] = rot_right_shoulder_z_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_shoulder_x_kf[g+1] - rot_left_shoulder_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_shoulder_x_kf[g] + h*dx;
            rot_left_shoulder_x_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_shoulder_x_int[num_interpolated-1] = rot_left_shoulder_x_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_shoulder_y_kf[g+1] - rot_left_shoulder_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_shoulder_y_kf[g] + h*dx;
            rot_left_shoulder_y_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_shoulder_y_int[num_interpolated-1] = rot_left_shoulder_y_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_shoulder_z_kf[g+1] - rot_left_shoulder_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_shoulder_z_kf[g] + h*dx;
            rot_left_shoulder_z_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_shoulder_z_int[num_interpolated-1] = rot_left_shoulder_z_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_elbow_kf[g+1] - rot_right_elbow_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_elbow_kf[g] + h*dx;
            rot_right_elbow_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_elbow_int[num_interpolated-1] = rot_right_elbow_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_elbow_kf[g+1] - rot_left_elbow_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_elbow_kf[g] + h*dx;
            rot_left_elbow_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_elbow_int[num_interpolated-1] = rot_left_elbow_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_hip_x_kf[g+1] - rot_right_hip_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_hip_x_kf[g] + h*dx;
            rot_right_hip_x_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_hip_x_int[num_interpolated-1] = rot_right_hip_x_kf[num_keyframes-1];
    }



    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_hip_y_kf[g+1] - rot_right_hip_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_hip_y_kf[g] + h*dx;
            rot_right_hip_y_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_hip_y_int[num_interpolated-1] = rot_right_hip_y_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_hip_z_kf[g+1] - rot_right_hip_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_hip_z_kf[g] + h*dx;
            rot_right_hip_z_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_hip_z_int[num_interpolated-1] = rot_right_hip_z_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_hip_x_kf[g+1] - rot_left_hip_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_hip_x_kf[g] + h*dx;
            rot_left_hip_x_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_hip_x_int[num_interpolated-1] = rot_left_hip_x_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_hip_y_kf[g+1] - rot_left_hip_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_hip_y_kf[g] + h*dx;
            rot_left_hip_y_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_hip_y_int[num_interpolated-1] = rot_left_hip_y_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_hip_z_kf[g+1] - rot_left_hip_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_hip_z_kf[g] + h*dx;
            rot_left_hip_z_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_hip_z_int[num_interpolated-1] = rot_left_hip_z_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_knee_kf[g+1] - rot_right_knee_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_knee_kf[g] + h*dx;
            rot_right_knee_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_knee_int[num_interpolated-1] = rot_right_knee_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_knee_kf[g+1] - rot_left_knee_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_knee_kf[g] + h*dx;
            rot_left_knee_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_knee_int[num_interpolated-1] = rot_left_knee_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_ankle_x_kf[g+1] - rot_right_ankle_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_ankle_x_kf[g] + h*dx;
            rot_right_ankle_x_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_ankle_x_int[num_interpolated-1] = rot_right_ankle_x_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_ankle_y_kf[g+1] - rot_right_ankle_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_ankle_y_kf[g] + h*dx;
            rot_right_ankle_y_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_ankle_y_int[num_interpolated-1] = rot_right_ankle_y_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_right_ankle_z_kf[g+1] - rot_right_ankle_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_right_ankle_z_kf[g] + h*dx;
            rot_right_ankle_z_int[g*between_frames + h] = (int)int_val;
        }
        rot_right_ankle_z_int[num_interpolated-1] = rot_right_ankle_z_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_ankle_x_kf[g+1] - rot_left_ankle_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_ankle_x_kf[g] + h*dx;
            rot_left_ankle_x_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_ankle_x_int[num_interpolated-1] = rot_left_ankle_x_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_ankle_y_kf[g+1] - rot_left_ankle_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_ankle_y_kf[g] + h*dx;
            rot_left_ankle_y_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_ankle_y_int[num_interpolated-1] = rot_left_ankle_y_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_left_ankle_z_kf[g+1] - rot_left_ankle_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_left_ankle_z_kf[g] + h*dx;
            rot_left_ankle_z_int[g*between_frames + h] = (int)int_val;
        }
        rot_left_ankle_z_int[num_interpolated-1] = rot_left_ankle_z_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_torso2_x_kf[g+1] - rot_torso2_x_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_torso2_x_kf[g] + h*dx;
            rot_torso2_x_int[g*between_frames + h] = (int)int_val;
        }
        rot_torso2_x_int[num_interpolated-1] = rot_torso2_x_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_torso2_y_kf[g+1] - rot_torso2_y_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_torso2_y_kf[g] + h*dx;
            rot_torso2_y_int[g*between_frames + h] = (int)int_val;
        }
        rot_torso2_y_int[num_interpolated-1] = rot_torso2_y_kf[num_keyframes-1];
    }

    for(int g=0; g<num_keyframes-1;g++){
        float dx = (rot_torso2_z_kf[g+1] - rot_torso2_z_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = rot_torso2_z_kf[g] + h*dx;
            rot_torso2_z_int[g*between_frames + h] = (int)int_val;
        }
        rot_torso2_z_int[num_interpolated-1] = rot_torso2_z_kf[num_keyframes-1];
    }


    for(int g=0; g<num_keyframes-1;g++){
        float dx = (mouthspeak_kf[g+1] - mouthspeak_kf[g]) / between_frames;
        for(int h=0; h<=between_frames; h++){
            float int_val = mouthspeak_kf[g] + h*dx;
            mouthspeak_int[g*between_frames + h] = (int)int_val;
        }
        mouthspeak_int[num_interpolated-1] = mouthspeak_kf[num_keyframes-1];
    }



    // Call Playback
    playback(0);


  return 0;
}


// interpolate : read keyframes.txt and 
/*
void playback(){

    // Initialize arrays for storing keyframe variables

    // Read the values from keyframes.txt
    // Initialize arrays for storing interpolated keyframe variables
    // Interpolate and store each variable
    // Update global variables with GlutTimerFunc
}
*/
/*
int main(){

    write_keyframe();
    write_keyframe();

    return 0;
}
*/
