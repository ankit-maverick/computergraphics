#include "classes.h"
#include "humanBody.h"


void keyHandler(unsigned char key, int x, int y){
 
 	if (key == 27)
   	exit(0);

	else if (key == '1'){
         rot_neck_x -= 5;
         if (rot_neck_x < -90)
             rot_neck_x = -90;

     }

     else if (key == '2'){
         rot_neck_x += 5;
         if (rot_neck_x > 90)
             rot_neck_x = 90;

     }

     else if (key == '3'){
         rot_neck_y -= 5;
         if (rot_neck_y < -90)
             rot_neck_y = -90;

     }

     else if (key == '4'){
         rot_neck_y += 5;
         if (rot_neck_y > 90)
             rot_neck_y = 90;

     }

     else if (key == '3'){
         rot_neck_z -= 5;
         if (rot_neck_z < -90)
             rot_neck_z = -90;

     }

     else if (key == '4'){
         rot_neck_z += 5;
         if (rot_neck_z > 90)
             rot_neck_z = 90;

     }

    else if (key == '1'){
         rotate_x -= 5;
         if (rotate_x < -90)
             rotate_x = -90;

     }

     else if (key == '2'){
         rotate_x += 5;
         if (rotate_x > 90)
             rotate_x = 90;

     }

     else if (key == '3'){
         rotate_y -= 5;
         if (rotate_y < -90)
             rotate_y = -90;

     }

     else if (key == '4'){
         rotate_y += 5;
         if (rotate_y > 90)
             rotate_y = 90;

     }

     else if (key == '3'){
         rotate_z -= 5;
         if (rotate_z < -90)
             rotate_z = -90;

     }

     else if (key == '4'){
         rotate_z += 5;
         if (rotate_z > 90)
             rotate_z = 90;

     }

     else if (key == 'c'){
         rot_left_elbow -= 5;
         if (rot_left_elbow < 0)
             rot_left_elbow = 0;
     }

     else if (key == 'v'){
         rot_left_elbow += 5;
         if (rot_left_elbow > 165)
             rot_left_elbow = 165;
     }


     else if (key == 'z'){
         rot_right_elbow -= 5;
         if (rot_right_elbow < 0)
             rot_right_elbow = 0;
     }

     else if (key == 'x'){
         rot_right_elbow += 5;
         if (rot_right_elbow > 165)
             rot_right_elbow = 165;
     }

     else if (key == 'q'){
         rot_right_shoulder_x -= 5;
         if (rot_right_shoulder_x < 0)
             rot_right_shoulder_x = 0;
     }


     else if (key == 'w'){
         rot_right_shoulder_x += 5;
         if (rot_right_shoulder_x > 355)
             rot_right_shoulder_x = 355;
     }

     else if (key == 'q'){
         rot_right_shoulder_y -= 5;
         if (rot_right_shoulder_y < 0)
             rot_right_shoulder_y = 0;
     }


     else if (key == 'w'){
         rot_right_shoulder_y += 5;
         if (rot_right_shoulder_y > 355)
             rot_right_shoulder_y = 355;
     }


     else if (key == 'a'){
         rot_right_shoulder_z -= 5;
         if (rot_right_shoulder_z < -180)
             rot_right_shoulder_z = -180;
     }


     else if (key == 's'){
         rot_right_shoulder_z += 5;
         if (rot_right_shoulder_z > 180)
             rot_right_shoulder_z = 180;

     }

     else if (key == 'e'){
         rot_left_shoulder_x -= 5;
         if (rot_left_shoulder_x < 0)
             rot_left_shoulder_x = 0;
     }


     else if (key == 'r'){
         rot_left_shoulder_x += 5;
         if (rot_left_shoulder_x > 355)
             rot_left_shoulder_x = 355;
     }

     else if (key == 'e'){
         rot_left_shoulder_y -= 5;
         if (rot_left_shoulder_y < 0)
             rot_left_shoulder_y = 0;
     }


     else if (key == 'r'){
         rot_left_shoulder_y += 5;
         if (rot_left_shoulder_y > 355)
             rot_left_shoulder_y = 355;
     }


     else if (key == 'd'){
         rot_left_shoulder_z -= 5;
         if (rot_left_shoulder_z < -180)
             rot_left_shoulder_z = -180;
     }


     else if (key == 'f'){
         rot_left_shoulder_z += 5;
         if (rot_left_shoulder_z > 180)
             rot_left_shoulder_z = 180;

     }


     else if (key == 't'){
         rot_right_hip_x -= 5;
         if (rot_right_hip_x < -60)
             rot_right_hip_x = -60;
     }


     else if (key == 'y'){
         rot_right_hip_x += 5;
         if (rot_right_hip_x > 60)
             rot_right_hip_x = 60;
     }

     else if (key == 't'){
         rot_right_hip_y -= 5;
         if (rot_right_hip_y < -60)
             rot_right_hip_y = -60;
     }


     else if (key == 'y'){
         rot_right_hip_y += 5;
         if (rot_right_hip_y > 60)
             rot_right_hip_y = 60;
     }

     else if (key == 'g'){
         rot_right_hip_z -= 5;
         if (rot_right_hip_z < -60)
             rot_right_hip_z = -60;
     }


     else if (key == 'h'){
         rot_right_hip_z += 5;
         if (rot_right_hip_z > 60)
             rot_right_hip_z = 60;

     }

     else if (key == 'u'){
         rot_left_hip_x -= 5;
         if (rot_left_hip_x < -60)
             rot_left_hip_x = -60;
     }


     else if (key == 'i'){
         rot_left_hip_x += 5;
         if (rot_left_hip_x > 60)
             rot_left_hip_x = 60;
     }

     else if (key == 'u'){
         rot_left_hip_y -= 5;
         if (rot_left_hip_y < -60)
             rot_left_hip_y = -60;
     }


     else if (key == 'i'){
         rot_left_hip_y += 5;
         if (rot_left_hip_y > 60)
             rot_left_hip_y = 60;
     }


     else if (key == 'j'){
         rot_left_hip_z -= 5;
         if (rot_left_hip_z < -60)
             rot_left_hip_z = -60;
     }


     else if (key == 'k'){
         rot_left_hip_z += 5;
         if (rot_left_hip_z > 60)
             rot_left_hip_z = 60;

     }


     else if (key == 'b'){
         rot_right_knee += 5;
         if (rot_right_knee > 165)
             rot_right_knee = 165;

     }

     else if (key == 'n'){
         rot_right_knee -= 5;
         if (rot_right_knee < 0)
             rot_right_knee = 0;
     }

     else if (key == 'm'){
         rot_left_knee += 5;
         if (rot_left_knee > 165)
             rot_left_knee = 165;

     }

     else if (key == ','){
         rot_left_knee -= 5;
         if (rot_left_knee < 0)
             rot_left_knee = 0;
     }

     // Right Ankle
     else if (key == '5'){
         rot_right_ankle_x += 5;
         if (rot_right_ankle_x > 65)
             rot_right_ankle_x = 65;

     }

     else if (key == '6'){
         rot_right_ankle_x -= 5;
         if (rot_right_ankle_x < 0)
             rot_right_ankle_x = 0;
     }

     else if (key == '5'){
         rot_right_ankle_y += 5;
         if (rot_right_ankle_y > 65)
             rot_right_ankle_y = 65;

     }

     else if (key == '6'){
         rot_right_ankle_y -= 5;
         if (rot_right_ankle_y < 0)
             rot_right_ankle_y = 0;
     }

     else if (key == '5'){
         rot_right_ankle_z += 5;
         if (rot_right_ankle_z > 65)
             rot_right_ankle_z = 65;

     }

     else if (key == '6'){
         rot_right_ankle_z -= 5;
         if (rot_right_ankle_z < 0)
             rot_right_ankle_z = 0;
     }


     // Left Ankle
     else if (key == '7'){
         rot_left_ankle_x += 5;
         if (rot_left_ankle_x > 65)
             rot_left_ankle_x = 65;

     }

     else if (key == '8'){
         rot_left_ankle_x -= 5;
         if (rot_left_ankle_x < 0)
             rot_left_ankle_x = 0;
     }

     else if (key == '7'){
         rot_left_ankle_y += 5;
         if (rot_left_ankle_y > 65)
             rot_left_ankle_y = 65;

     }

     else if (key == '8'){
         rot_left_ankle_y -= 5;
         if (rot_left_ankle_y < 0)
             rot_left_ankle_y = 0;
     }

     else if (key == '7'){
         rot_left_ankle_z += 5;
         if (rot_left_ankle_z > 65)
             rot_left_ankle_z = 65;

     }

     else if (key == '8'){
         rot_left_ankle_z -= 5;
         if (rot_left_ankle_z < 0)
             rot_left_ankle_z = 0;
     }



     else if (key == 'o'){
         rot_right_wrist_x += 5;
         if (rot_right_wrist_x > 65)
             rot_right_wrist_x = 65;

     }

     else if (key == 'p'){
         rot_right_wrist_x -= 5;
         if (rot_right_wrist_x < -30)
             rot_right_wrist_x = -30;
     }

     else if (key == 'o'){
         rot_right_wrist_y += 5;
         if (rot_right_wrist_y > 65)
             rot_right_wrist_y = 65;

     }

     else if (key == 'p'){
         rot_right_wrist_y -= 5;
         if (rot_right_wrist_y < -30)
             rot_right_wrist_y = -30;
     }

     else if (key == 'o'){
         rot_right_wrist_z += 5;
         if (rot_right_wrist_z > 65)
             rot_right_wrist_z = 65;

     }

     else if (key == 'p'){
         rot_right_wrist_z -= 5;
         if (rot_right_wrist_z < -30)
             rot_right_wrist_z = -30;
     }


     else if (key == '['){
         rot_left_wrist_x += 5;
         if (rot_left_wrist_x > 30)
             rot_left_wrist_x = 30;

     }

     else if (key == ']'){
         rot_left_wrist_x -= 5;
         if (rot_left_wrist_x < -60)
             rot_left_wrist_x = -60;
     }

     else if (key == '['){
         rot_left_wrist_y += 5;
         if (rot_left_wrist_y > 30)
             rot_left_wrist_y = 30;

     }

     else if (key == ']'){
         rot_left_wrist_y -= 5;
         if (rot_left_wrist_y < -60)
             rot_left_wrist_y = -60;
     }

     else if (key == '['){
         rot_left_wrist_z += 5;
         if (rot_left_wrist_z > 30)
             rot_left_wrist_z = 30;

     }

     else if (key == ']'){
         rot_left_wrist_z -= 5;
         if (rot_left_wrist_z < -60)
             rot_left_wrist_z = -60;
     }


     else if (key == 'l'){
         rot_torso2_x += 5;
         if (rot_torso2_x > 50)
             rot_torso2_x = 50;

     }

     else if (key == ';'){
         rot_torso2_x -= 5;
         if (rot_torso2_x < -50)
             rot_torso2_x = -50;
     }

     // Left Ankle
     else if (key == '.'){
         rot_torso2_y += 5;
         if (rot_torso2_y > 45)
             rot_torso2_y = 45;

     }

     else if (key == '/'){
         rot_torso2_y -= 5;
         if (rot_torso2_y < -45)
             rot_torso2_y = -45;
     }

     else if (key == '.'){
         rot_torso2_z += 5;
         if (rot_torso2_z > 45)
             rot_torso2_z = 45;

     }

     else if (key == '/'){
         rot_torso2_z -= 5;
         if (rot_torso2_z < -45)
             rot_torso2_z = -45;
     }



     else if (key == '0'){
         cerr << mouthspeak << endl;
         if (mouthspeak > 0.004){
             mouthspeak = -0.005;
             cerr << mouthspeak << endl;
         }
         
         else if (mouthspeak < -0.004)
             mouthspeak = 0.005;
     }


	else if (key == '-'){
		if(lid_angle>-150)
			lid_angle = lid_angle - 5;
	}
	
	
	else if (key == '='){
		if(lid_angle<0 && dancer_pos<0.2)
			lid_angle = lid_angle + 5;
	}
	
	else if (key == '('){
		if(lid_angle<-80){
			dancer_pos+=0.04;
		}
	}
	
	else if (key == ')'){
		if(dancer_pos>0){
			dancer_pos-=0.04;
		}
	}

    else if(key == 'H'){
        light0 = 1; //Start adding points
        cerr << "Wall-mounted light on" <<endl;
        glEnable(GL_LIGHT0);
    }
    
    else if(key == 'J'){
        light0 = 0; //Stop adding points
        glDisable(GL_LIGHT0);
        cerr << "Wall-mounted light off" <<endl;
    }

    else if(key == 'K'){
        light1 = 1;
        cerr << "Table-Lamp on" <<endl;
        glEnable(GL_LIGHT1);
    }
    
    else if(key == 'L'){
        light1 = 0;
        cerr << "Table-Lamp off" <<endl;
        glDisable(GL_LIGHT1);
    }

    else if(key == '?'){
        curve.drawCurve();
    }
 
    else if(key == '*'){
        cerr << "Starting Camera Flythrough " << endl;
        flythru(0);
    }
 
    else if(key == 'S'){
        cerr << "Saved the current keyframe." << endl;
        write_keyframe();
    }

    else if(key == 'C'){
        cerr << "Cleared keyframes.txt file." << endl;
        clear_keyframes();
    }

    else if(key == 'R'){
        cerr << "Read keyframes.txt file." << endl;
        read_keyframes_and_playback();
    }
	glutPostRedisplay();
}
