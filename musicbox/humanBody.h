
#ifndef HUMANBODY_H
#define HUMAN_H


//----------------------------------------------------------------------
// Humanbody
//----------------------------------------------------------------------


GLuint dancer_torso1(GLuint);
GLuint dancer_torso2();
GLuint dancer_torso3(GLuint);
GLuint dancer_neck();
GLuint dancer_head(GLuint, GLuint);
GLuint dancer_eye();
GLuint dancer_nose();
GLuint dancer_mouth();
GLuint dancer_greek_hat();
GLuint dancer_shoulder();
GLuint dancer_upper_arm(GLuint);
GLuint dancer_lower_arm(GLuint);
GLuint dancer_wrist();
GLuint dancer_elbow();
GLuint dancer_hip();
GLuint dancer_thigh(GLuint);
GLuint dancer_leg(GLuint);
GLuint dancer_knee();
GLuint dancer_ankle();
GLuint dancer_foot();
GLuint dancer_hand();



/* GLOBAL VARIABLES */
extern int rot_left_elbow;
extern int rot_right_elbow;

extern int rot_left_shoulder_x; // _* denotes the direction of rotation/tilt and not the axis of rotation
extern int rot_right_shoulder_x;
extern int rot_right_shoulder_y;
extern int rot_left_shoulder_y;
extern int rot_left_shoulder_z;
extern int rot_right_shoulder_z;

extern int rot_right_wrist_x;
extern int rot_right_wrist_y;
extern int rot_right_wrist_z;
extern int rot_left_wrist_x;
extern int rot_left_wrist_y;
extern int rot_left_wrist_z;


extern int rot_left_hip_x;
extern int rot_right_hip_x;
extern int rot_left_hip_y;
extern int rot_right_hip_y;
extern int rot_left_hip_z;
extern int rot_right_hip_z;

extern float mouthspeak;

extern int rot_neck_x;
extern int rot_neck_y;
extern int rot_neck_z;

extern int rotate_x;
extern int rotate_y;
extern int rotate_z;

extern int rot_right_knee;
extern int rot_left_knee;

extern int rot_left_ankle_x;
extern int rot_right_ankle_x;
extern int rot_left_ankle_y;
extern int rot_right_ankle_y;
extern int rot_left_ankle_z;
extern int rot_right_ankle_z;

extern int rot_torso2_x;
extern int rot_torso2_y;
extern int rot_torso2_z;

#endif
