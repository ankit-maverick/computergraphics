#include "bezier.h"
#include "classes.h"

void updateLookat();

int factorial(int n){
	if(n==1 || n==0){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
}

int comb(int n, int i){
	return factorial(n)/(factorial(n-i)*factorial(i));
}

Bezier::Bezier(double dt){
	sample_dist =dt;
	control_points.num_nodes=0;
	control_points.head=NULL;
	time_step=0;
	//control_points = Stack();
	
}

void Bezier::addPoint(double pX, double pY, double pZ){

	if(control_points.num_nodes==0){
		control_points.head = new Stack_node;
		curr_node = control_points.head;
	}
	else{
		curr_node->next = new Stack_node;
		curr_node = curr_node->next;
	}
	curr_node->x=pX;
	curr_node->y=pY;
	curr_node->z=pZ;
	control_points.num_nodes++;
	
	//cout << pX << "\t" << pY << "\t" << pZ << "\n";

	
}

int Bezier::sampleCurve(){
	//Copy points to array for easy access
	int n = control_points.num_nodes;
	double* controlPoints = new double[n*3];
	Stack_node* tempNode = control_points.head;
	
	for(int i=0; i<n; i++){
		controlPoints[i*3] = tempNode->x;
		//cout << controlPoints[i*3] << "\n";
		controlPoints[i*3 + 1] = tempNode->y;
		//cout << controlPoints[i*3+1] << "\n";
		controlPoints[i*3 + 2] = tempNode->z;
		//cout << controlPoints[i*3+2] << "\n";
	
		tempNode = tempNode->next;
	}
	
	//Store sampled curve in array
	int numSamples = (1/sample_dist);
	sampledCurve = new double[numSamples*3];
	

	//Intermediate samples
	for(float t=sample_dist; t<1; t+=sample_dist){
		int sampleNum = t/sample_dist;
		double pX=0, pY=0, pZ=0;
		
		for(int i=0; i<n; ++i){
			
			pX += comb(n-1, i)*pow(t,i)*pow(1-t,n-1-i)*controlPoints[i*3];
			pY += comb(n-1, i)*pow(t,i)*pow(1-t,n-1-i)*controlPoints[i*3 + 1];
			pZ += comb(n-1, i)*pow(t,i)*pow(1-t,n-1-i)*controlPoints[i*3 + 2];
			//cout << "t : "<< t << "  Basis weight : " << comb(n-1, i)*pow(t,i)*pow(1-t,n-1-i) <<endl;
		}

		sampledCurve[sampleNum*3] = pX;
		sampledCurve[sampleNum*3 + 1] = pY;
		sampledCurve[sampleNum*3 + 2] = pZ;
		
	}
	
	//First sample
	sampledCurve[0] = controlPoints[0];
	sampledCurve[1] = controlPoints[1];
	sampledCurve[2] = controlPoints[2];
	
	//Last sample
	sampledCurve[(numSamples-1)*3] = controlPoints[(n-1)*3];
	sampledCurve[(numSamples-1)*3 + 1] = controlPoints[(n-1)*3 + 1];
	sampledCurve[(numSamples-1)*3 + 2] = controlPoints[(n-1)*3 + 2];
	for (int j = 0; j<=numSamples - 1; j++){
		cout << j <<" : " << sampledCurve[j*3] << "\t" << sampledCurve[j*3 + 1] << "\t" << sampledCurve[j*3 + 1] << endl;
	}
	return numSamples;
}

void Bezier::drawCurve(){
	numSamples = sampleCurve();	
}
	
	
void flythru(int temp){
	eye_x = curve.sampledCurve[curve.time_step*3];
	eye_y = curve.sampledCurve[curve.time_step*3+1];
	eye_z = curve.sampledCurve[curve.time_step*3+2];
	center_x = curve.sampledCurve[(curve.time_step+1)*3];
	center_y = curve.sampledCurve[(curve.time_step+1)*3 + 1];
	center_z = curve.sampledCurve[(curve.time_step+1)*3 + 2];

	int step = 4;
	if (curve.time_step % step == 0){
		write_keyframe();
	}
	glMatrixMode(GL_MODELVIEW);
						
	glutPostRedisplay();
	
	curve.time_step++;
	
	if(curve.time_step<curve.numSamples - 1)
		glutTimerFunc(100, flythru, 0);
	
}
	
