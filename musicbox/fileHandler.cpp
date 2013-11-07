#include <iostream>
#include <fstream>
#include <string>

#include "classes.h"
#include "humanBody.h"

using namespace std;



// writing on a text file
int write_keyframe() {

    // Delimiter
    string dlmtr = ",";
    ofstream myfile ("keyframes.txt", std::ios_base::app);
    if (myfile.is_open())
    {
        myfile << eye_x <<  dlmtr << eye_y << dlmtr << eye_z << dlmtr << center_x << dlmtr << center_y << dlmtr << center_z << dlmtr << light0 << dlmtr << light1 << dlmtr << lid_angle << dlmtr << dancer_pos << dlmtr << rot_neck_x << dlmtr << rot_neck_y << dlmtr << rot_right_shoulder_x << dlmtr << rot_right_shoulder_z << dlmtr << rot_left_shoulder_x << dlmtr << rot_left_shoulder_z << dlmtr << rot_right_elbow << dlmtr << rot_left_elbow << dlmtr << rot_right_wrist << dlmtr << rot_left_wrist << dlmtr << rot_right_hip_x << dlmtr << rot_right_hip_z << dlmtr << rot_left_hip_x << dlmtr << rot_left_hip_z << dlmtr << rot_right_knee << dlmtr << rot_left_knee << dlmtr << rot_right_ankle << dlmtr << rot_left_ankle << dlmtr << rot_torso2_x << dlmtr << rot_torso2_y << dlmtr << mouth_speak <<"\n";
        myfile.close();
    }
    else cout << "Unable to open file";
    return 0;
}



// clearing the text file
void clear_keyframes(){
    ofstream myfile;
    myfile.open ("keyframes.txt", std::ofstream::out | std::ofstream::trunc);
    myfile.close();
}



// reading a text file
int read_keyframes() {
  string line;
  ifstream myfile ("keyframes.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}


// playback : update the params and glutPostRedisplay
// interpolate : read keyframes.txt and 

/*
int main(){

    write_keyframe();
    write_keyframe();

    return 0;
}
*/
