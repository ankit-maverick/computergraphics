#include "classes.h"
#include "humanBody.h"



void drawBody(GLuint skin, GLuint hair, GLuint jeans, GLuint shirt){
	GLuint head = dancer_head(skin, hair);
    GLuint neck = dancer_neck();
    GLuint eye = dancer_eye();
    GLuint nose = dancer_nose();
    GLuint mouth = dancer_mouth();
    GLuint greek_hat = dancer_greek_hat();
    GLuint torso1 = dancer_torso1(shirt);
    GLuint torso2 = dancer_torso2();
    GLuint torso3 = dancer_torso3(shirt);
    GLuint hip = dancer_hip();
    GLuint thigh = dancer_thigh(jeans);
    GLuint knee = dancer_knee();
    GLuint ankle = dancer_ankle();
    GLuint leg = dancer_leg(skin);
    GLuint foot = dancer_foot();
    GLuint shoulder = dancer_shoulder();
    GLuint upper_arm = dancer_upper_arm(shirt);
    GLuint elbow = dancer_elbow();
    GLuint lower_arm = dancer_lower_arm(skin);
    GLuint wrist = dancer_wrist();
    GLuint hand = dancer_hand();

    glTranslatef(0.0, 0.25, 0.0);

    // Torso 3
    glPushMatrix();
        glTranslatef(0.0, -0.05, 0.0);
        glPushMatrix();
            glCallList(torso3);
        glPopMatrix();

        // Torso 2
        glPushMatrix();
            glRotatef(rot_torso2_z, 0.0, 0.0, 1.0);
            glRotatef(rot_torso2_x, 0.0, 1.0, 0.0);
            glRotatef(rot_torso2_y, 1.0, 0.0, 0.0);
            glPushMatrix();
                glCallList(torso2);
            glPopMatrix();

            // Torso 1
            glPushMatrix();
                glTranslatef(0.0, 0.35, 0.0);
                glPushMatrix();
                    glCallList(torso1);
                glPopMatrix();

                // Neck
                glPushMatrix();
                    glTranslatef(0.0, 0.03, 0.0);
                    glPushMatrix();
                        glCallList(neck);
                    glPopMatrix();

                    // Head
                    glPushMatrix();
                        glTranslatef(0.0, 0.17, 0.0);
                        glRotatef(rot_neck_z, 0.0, 0.0, 1.0);
                        glRotatef(rot_neck_x, 0.0, 1.0, 0.0);
                        glRotatef(rot_neck_y, 1.0, 0.0, 0.0);
                        glPushMatrix();
                            glCallList(head);
                        glPopMatrix();

                        // Right Eye
                        glPushMatrix();
                            glTranslatef(-0.05, 0.02, -0.1);
                            glCallList(eye);
                        glPopMatrix();

                        // Left Eye
                        glPushMatrix();
                            glTranslatef(0.05, 0.02, -0.1);
                            glCallList(eye);
                        glPopMatrix();

                        // Nose
                        glPushMatrix();
                            glTranslatef(0.0, -0.02, -0.1);
                            glCallList(nose);
                        glPopMatrix();

                        // Mouth
                        glPushMatrix();
                            glTranslatef(0.0, 0.0, mouthspeak);
                            glTranslatef(0.0, -0.07, -0.04);
                            glCallList(mouth);
                        glPopMatrix();

                        // Greek Hat
                        glPushMatrix();
                            glTranslatef(0.0, 0.14, -0.02);
                            glCallList(greek_hat);
                        glPopMatrix();

                    glPopMatrix();
                glPopMatrix();


                // Right Shoulder
                glPushMatrix();
                    glTranslatef(-0.23, -0.05, 0.0);
                    glRotatef(rot_right_shoulder_y, 0.0, 1.0, 0.0);
                    glRotatef(rot_right_shoulder_x, 0.0, 0.0, 1.0);
                    glRotatef(rot_right_shoulder_z, 1.0, 0.0, 0.0); 
                    glPushMatrix();
                        glCallList(shoulder);
                    glPopMatrix();
                    //Right Upper Arm
                    glPushMatrix();
                        glTranslatef(-0.015, 0.04, 0.0);                
                        glPushMatrix();
                            glCallList(upper_arm);
                        glPopMatrix();

                        // Right Elbow
                        glPushMatrix();
                            glTranslatef(0.0, -0.3, 0.0);
                            glRotatef(rot_right_elbow, 1.0, 0.0, 0.0);

                            glPushMatrix();
                                glCallList(elbow);
                            glPopMatrix();

                            // Right Lower Arm
                            glPushMatrix();
                                glTranslatef(0.0, 0.0, 0.0);
                                glPushMatrix();
                                    glCallList(lower_arm);
                                glPopMatrix();

                                // Right Wrist
                                glPushMatrix();
                                    glTranslatef(0.0, -0.35, 0.0);
                                    glRotatef(rot_right_wrist_x, 1.0, 0.0, 0.0);
                                    glRotatef(rot_right_wrist_y, 0.0, 1.0, 0.0);
                                    glRotatef(rot_right_wrist_z, 0.0, 0.0, 1.0);
                                    glPushMatrix();
                                        glCallList(wrist);
                                    glPopMatrix();

                                    // Right Hand
                                    glPushMatrix();
                                        glTranslatef(0.0, -0.05, 0.0);
                                        glCallList(hand);
                                    glPopMatrix();
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();


                // Left Shoulder
                glPushMatrix();
                    glTranslatef(0.23, -0.05, 0.0);
                    glRotatef(rot_left_shoulder_y, 0.0, 1.0, 0.0);
                    glRotatef(rot_left_shoulder_x, 0.0, 0.0, 1.0);
                    glRotatef(rot_left_shoulder_z, 1.0, 0.0, 0.0);
                    glPushMatrix();
                        glCallList(shoulder);
                    glPopMatrix();

                    // Left Upper Arm
                    glPushMatrix();
                        glTranslatef(0.015, 0.04, 0.0);
                        glPushMatrix();
                            glCallList(upper_arm);
                        glPopMatrix();

                        // Left Elbow
                        glPushMatrix();
                            glTranslatef(0.0, -0.3, 0.0);
                            glRotatef(rot_left_elbow, 1.0, 0.0, 0.0);
                            glPushMatrix();
                                glCallList(elbow);
                            glPopMatrix();

                            // Left Lower Arm
                            glPushMatrix();
                                glTranslatef(0.0, -0.0, 0.0);
                                glPushMatrix();
                                    glCallList(lower_arm);
                                glPopMatrix();

                                // Left Wrist
                                glPushMatrix();
                                    glTranslatef(0.0, -0.35, 0.0);
                                    glRotatef(rot_left_wrist_x, 1.0, 0.0, 0.0);
                                    glRotatef(rot_left_wrist_y, 0.0, 1.0, 0.0);
                                    glRotatef(rot_left_wrist_z, 0.0, 0.0, 1.0);
                                    glPushMatrix();
                                        glCallList(wrist);
                                    glPopMatrix();

                                    // Left Hand
                                    glPushMatrix();
                                        glTranslatef(0.0, -0.05, 0.0);
                                        glCallList(hand);
                                    glPopMatrix();
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

                glPushMatrix();
                    //Right Hip
                    glTranslatef(-0.1, -0.28, 0.0);
                    glRotatef(rot_right_hip_y, 0.0, 1.0, 0.0);
                    glRotatef(rot_right_hip_x, 0.0, 0.0, 1.0);
                    glRotatef(rot_right_hip_z, 1.0, 0.0, 0.0);
                    glPushMatrix();
                        glCallList(hip);
                    glPopMatrix();
                    // Right Thigh
                    glTranslatef(0.0, -0.03, 0.0);
                    glPushMatrix();
                        glCallList(thigh);
                    glPopMatrix();
            
                    // Right Knee
                    glPushMatrix();
                        glTranslatef(0.0, -0.35, 0.0);
                        glRotatef(-rot_right_knee, 1.0, 0.0, 0.0);
                        glPushMatrix();
                            glCallList(knee);
                        glPopMatrix();

                        // Right leg
                        glPushMatrix();
                            glTranslatef(0.0, -0.0, 0.0);
    
                            glPushMatrix();
                                glCallList(leg);
                            glPopMatrix();

                            // Right Ankle
                            glPushMatrix();
                                glTranslatef(0.0, -0.4, 0.0);
                                glRotatef(-rot_right_ankle_x, 1.0, 0.0, 0.0);
                                glRotatef(rot_right_ankle_y, 0.0, 1.0, 0.0);
                                glRotatef(rot_right_ankle_z, 0.0, 0.0, 1.0);
                                glPushMatrix();
                                    glCallList(ankle);
                                glPopMatrix();

                                // Right Foot
                                glPushMatrix();
                                    glTranslatef(0.0, 0.0, -0.05);
                                    glCallList(foot);
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();



                glPushMatrix();
                    // Left Hip
                    glTranslatef(0.1, -0.28, 0.0);
                    glRotatef(rot_left_hip_y, 0.0, 1.0, 0.0);
                    glRotatef(rot_left_hip_x, 0.0, 0.0, 1.0);
                    glRotatef(rot_left_hip_z, 1.0, 0.0, 0.0);
                    glCallList(hip);

                    // Left Thigh
                    glTranslatef(0.0, -0.03, 0.0);
                    glPushMatrix();
                        glCallList(thigh);
                    glPopMatrix();

                    // Left Knee
                    glPushMatrix();
                        glTranslatef(0.0, -0.35, 0.0);
                        glRotatef(-rot_left_knee, 1.0, 0.0, 0.0);
                        glPushMatrix();
                            glCallList(knee);
                        glPopMatrix();

                        // Left leg
                        glPushMatrix();
                            glTranslatef(0.0, -0.0, 0.0);
                            glPushMatrix();
                                glCallList(leg);
                            glPopMatrix();

                            // Left Ankle
                            glPushMatrix();
                                glTranslatef(0.0, -0.4, 0.0);
                                glRotatef(-rot_left_ankle_x, 1.0, 0.0, 0.0);
                                glRotatef(rot_left_ankle_y, 0.0, 1.0, 0.0);
                                glRotatef(rot_left_ankle_z, 0.0, 0.0, 1.0);
                                glPushMatrix();
                                    glCallList(ankle);
                                glPopMatrix();

                                // Left Foot
                                glPushMatrix();
                                    glTranslatef(0.0, 0.0, -0.05);
                                    glCallList(foot);
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();

    glPopMatrix();
}
