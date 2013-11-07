#ifndef __BEIZER_H
#define __BEIZER_H

class Bezier{
	
	public:
		struct Stack_node{
			
				//Stack_node(int pX, int pY, int pZ);
							
				Stack_node* next;
				double x;
				double y;
				double z;
		};
	
	
	private:		
		struct Stack{
								
				//Stack();
								
				int num_nodes;
				Stack_node* head;		
		};
		
		int sampleCurve();
		
		Stack_node* curr_node;
		
	public:
	
		double* sampledCurve;
		int numSamples;
	
		Bezier(double dt);
	
		void addPoint(double pX, double pY, double pZ);
		void drawCurve();
		int time_step;
		double sample_dist;
		Stack control_points;
};

void flythru(int);

#endif
