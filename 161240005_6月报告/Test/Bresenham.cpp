#include<iostream>
#include<cmath>
using namespace std;

int main(){
	float x1,y1,x2,y2;
	//scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	x1=138,y1=141,x2=281,y2=319;
	float xstart=x1,ystart=y1;
    float dx=fabsf(x2-x1);
    float dy=fabsf(y2-y1);
    float k=dy/dx;
    int xIncrement=x2>x1 ? 1 : (x2<x1 ? -1 : 0);
    int yIncrement=y2>y1 ? 1 : (y2<y1 ? -1 : 0);
    bool interchange=false;
    if(dy>dx){
        float temp=dx;
        dx=dy;
        dy=temp;
        interchange=true;
    }
    float p=2*dy-dx;
    for(int i=0;i<dx;i++){
        //Generate_point(static_cast<int>(roundf(xstart)),static_cast<int>(roundf(ystart)),id);
        float tmpx=(ystart-y1)/k+x1;
		//cout<<ystart<<" "<<xstart<<" "<<tmpx<<" "<<xstart-tmpx<<endl;
		cout<<"{"<<ystart<<"}&{"<<xstart<<"}&{"<<tmpx<<"}&{"<<xstart-tmpx<<"}\\\\"<<endl;
		cout<<"\\hline"<<endl;
        if(p>=0){
            if(!interchange)
                ystart+=yIncrement;
            else
                xstart+=xIncrement;
            p-=2*dx;
        }
        if(!interchange)
            xstart+=xIncrement;
        else
            ystart+=yIncrement;
        p+=2*dy;
    }
}
