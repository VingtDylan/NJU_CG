#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float x1,y1,x2,y2;
	//scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	x1=138,y1=141,x2=281,y2=319;
	float dx=x2-x1;
    float dy=y2-y1;
    float steps;
    float xIncrement,yIncrement,xstart=x1,ystart=y1;
    if(fabsf(dx)>fabsf(dy))
        steps=static_cast<int>(fabsf(dx));
    else
        steps=static_cast<int>(fabsf(dy));
    xIncrement=static_cast<float>((dx)/steps);
    yIncrement=static_cast<float>((dy)/steps);
    for(int k=0;k<steps;k++){
        //Generate_point(static_cast<int>(roundf(xstart+0.5f)),static_cast<int>(roundf(ystart+0.5f)),id);
        int tmpx=xstart+0.5;
        //cout<<"{"<<(int)ystart<<"}&"<<"{"<<(int)tmpx<<"}&"<<"{"<<xstart<<"}&"<<"{"<<xstart-tmpx<<"}\\\\"<<endl;
		//cout<<"\\hline"<<endl; 
		cout<<(int)ystart<<tmpx<<xstart<<xstart-tmpx<<endl;
		xstart+=xIncrement;
        ystart+=yIncrement;
    }
}
