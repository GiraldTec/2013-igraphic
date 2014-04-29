#include "DiscoParcial.h"


DiscoParcial::DiscoParcial(void){
	innerRadius=0.5;
	outerRadius=1.0;
	slices=10;
	rings=5;
	startAngle = 0.0;
	sweepAngle = 180.0;
}

DiscoParcial::DiscoParcial(GLdouble i,GLdouble o,GLint s,GLint r,GLdouble sA,GLdouble sW){
	innerRadius=i;
	outerRadius=o;
	slices=s;
	rings=r;
	startAngle = sA;
	sweepAngle = sW;
}
