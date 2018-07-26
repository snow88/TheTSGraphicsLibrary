/* BUILT AND OWNED BY TUHINA SINGH; AVAILABLE FOR USE AT: github.com/snow88/TheTSGraphicsLibrary */

#include<iostream>
#include<graphics.h>
#include<math.h>
#include<utility> 
using namespace std;


//BASICS

void fullcirclemidpt (int xcentre, int ycentre, int R)
{
    int x=0, y=R, d=1-R;
    while(x<=y)
    {
        putpixel(x+xcentre, y+ycentre, WHITE);
        putpixel(-x+xcentre, y+ycentre, WHITE);
        putpixel(x+xcentre, -y+ycentre, WHITE);
        putpixel(-x+xcentre, -y+ycentre, WHITE);
        putpixel(y+xcentre, x+ycentre, WHITE);
        putpixel(-y+xcentre, x+ycentre, WHITE);
        putpixel(y+xcentre, -x+ycentre, WHITE);
        putpixel(-y+xcentre, -x+ycentre, WHITE);

        if(d<0)
            d+=2*x+3;
        else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}

void semicirclemidpt (int xc, int yc, int R, int type)
{
    int x=0, y=R, d=1-R;
    while(x<=y)
    {
        if(type==1){
			putpixel(-x+xc,-y+yc,WHITE);
             putpixel(-y+xc,-x+yc,WHITE);
         putpixel(x+xc,-y+yc,WHITE);
         putpixel(y+xc,-x+yc,WHITE);
        }
        if(type==2){
           putpixel(x+xc,y+yc,WHITE);
         putpixel(x+xc,-y+yc,WHITE);
          putpixel(y+xc,x+yc,WHITE);
         putpixel(y+xc,-x+yc,WHITE);
        }
        if(type==3){
                putpixel(x+xc,y+yc,WHITE);
        putpixel(y+xc,x+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
                putpixel(-y+xc,x+yc,WHITE);
         }
        if(type==4){
           putpixel(-y+xc,x+yc,WHITE);
          putpixel(-x+xc,-y+yc,WHITE);
            putpixel(-x+xc,y+yc,WHITE);
             putpixel(-y+xc,-x+yc,WHITE);
        }

        if(d<0)
            d+=2*x+3;
        else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}

void quartercirclemidpt(int xcentre, int ycentre, int R, int type)
{
    int x=0, y=R, d=1-R;
    while(x<=y)
    {
        if(type == 1){
            putpixel(x+xcentre, -y+ycentre, WHITE);
       putpixel(y+xcentre, -x+ycentre, WHITE);
        }
        if(type==2){
       putpixel(y+xcentre, x+ycentre, WHITE);
       putpixel(y+xcentre, -x+ycentre, WHITE);
        }
       if(type == 3){
            putpixel(x+xcentre, y+ycentre, WHITE);
       putpixel(y+xcentre, x+ycentre, WHITE);
       }
        if(type==4){
       putpixel(x+xcentre, y+ycentre, WHITE);
       putpixel(-x+xcentre, y+ycentre, WHITE);
       }
       if(type == 5){
           putpixel(-x+xcentre, y+ycentre, WHITE);
       putpixel(-y+xcentre, x+ycentre, WHITE);
       }
        if(type==6){
       putpixel(-y+xcentre, x+ycentre, WHITE);
       putpixel(-y+xcentre, -x+ycentre, WHITE);
       }
       if(type == 7){
            putpixel(-x+xcentre, -y+ycentre, WHITE);
       putpixel(-y+xcentre, -x+ycentre, WHITE);
       }
        if(type==8){
       putpixel(x+xcentre, -y+ycentre, WHITE);
       putpixel(-x+xcentre, -y+ycentre, WHITE);
       }

        if(d<0)
            d+=2*x+3;
        else{
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}

void myline (int x1, int y1, int x2, int y2, int lcolor)
{
    float x=x1;
    float y=y1;
    float dx = x2-x1;
    float dy = y2-y1;

    //vertical line
    if (dx==0)
    {
        if (dy>0)
        {
            while(y<=y2)
            {
                putpixel(x,y,lcolor);
                y++;
            }
        }
        else
        {
            while(y>=y2)
            {
                putpixel(x,y,lcolor);
                y--;
            }
        }
        return;
    }

    float m = dy/dx;

    if (m>=0 && x2>=x1 && y2>=y1)
    {
        if(abs((int)dy)<abs((int)dx))
        {
            putpixel(x,y,lcolor);
            while(x<=x2)
            {
                y+=m;
                x++;
                putpixel(x,y,lcolor);
            }
        }
        else
        {
            putpixel(x,y,lcolor);
            while(y<=y2)
            {
                x+=1/m;
                y++;
                putpixel(x,y,lcolor);
            }
        }
    }

    else if (m<0 && x2>x1 && y2<y1)
    {
        if(abs((int)dy)<abs((int)dx))
        {
            putpixel(x,y,lcolor);
            while(x<=x2)
            {
                y+=m;
                x++;
                putpixel(x,y,lcolor);
            }
        }
        else
        {
            putpixel(x,y,lcolor);
            while(y>=y2)
            {
                x-=1/m;
                y--;
                putpixel(x,y,lcolor);
            }
        }
    }

    else if (m<=0 && x2<=x1 && y2>=y1)
    {
        if(abs((int)dy)<abs((int)dx))
        {
            putpixel(x,y,lcolor);
            while(x>=x2)
            {
                y-=m;
                x--;
                putpixel(x,y,lcolor);
            }
        }
        else
        {
            putpixel(x,y,lcolor);
            while(y<=y2)
            {
                x+=1/m;
                y++;
                putpixel(x,y,lcolor);
            }
        }
    }

    else if (m>0 && x2<x1 && y2<y1)
    {
        if(abs((int)dy)<abs((int)dx))
        {
            putpixel(x,y,lcolor);
            while(x>=x2)
            {
                y-=m;
                x--;
                putpixel(x,y,lcolor);
            }
        }
        else
        {
            putpixel(x,y,lcolor);
            while(y>=y2)
            {
                x-=1/m;
                y--;
                putpixel(x,y,lcolor);
            }
        }
    }
}

void fullellipse(int xc, int yc, int a, int b)
{
    int x=a, y=0, d=(b*b/4)-a*b*b+a*a;
    while( b*b*abs(x)>= a*a*abs(y))
    {
        putpixel(x+xc,y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);

        if(d<0)
            d+=2*a*a*y+3*a*a;
        else{
            d+=2*b*b-2*x*b*b+2*a*a*y+3*a*a;
            x--;
        }
        y++;
    }
    d=b*b*(x-1)*(x-1)+a*a*(y+0.5)*(y+0.5)-a*a*b*b;
    while(x>=0)
    {
        putpixel(x+xc,y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);

        if (d<0)
        {
            d+=3*b*b-2*x*b*b+2*a*a+2*y*a*a;
            y++;
        }
        else
            d+=3*b*b-2*x*b*b;
        x--;
    }
}

void quartellipse(int xc, int yc, int a, int b, int type)
{
    int x=a, y=0, d=(b*b/4)-a*b*b+a*a;
    while( b*b*abs(x)>= a*a*abs(y))
    {
		if (type==2)
        putpixel(x+xc,y+yc,WHITE);
	    if (type==3)
        putpixel(-x+xc,y+yc,WHITE);
		if (type==4)
        putpixel(-x+xc,-y+yc,WHITE);
		if (type==1)
        putpixel(x+xc,-y+yc,WHITE);

        if(d<0)
            d+=2*a*a*y+3*a*a;
        else{
            d+=2*b*b-2*x*b*b+2*a*a*y+3*a*a;
            x--;
        }
        y++;
    }
    d=b*b*(x-1)*(x-1)+a*a*(y+0.5)*(y+0.5)-a*a*b*b;
    while(x>=0)
    {
		if (type==2)
        putpixel(x+xc,y+yc,WHITE);
	    if (type==3)
        putpixel(-x+xc,y+yc,WHITE);
	    if (type==4)
        putpixel(-x+xc,-y+yc,WHITE);
	    if (type==1)
        putpixel(x+xc,-y+yc,WHITE);

        if (d<0)
        {
            d+=3*b*b-2*x*b*b+2*a*a+2*y*a*a;
            y++;
        }
        else
            d+=3*b*b-2*x*b*b;
        x--;
    }
}

void parabola(int xc, int yc, int a, int height, int type)
{
int x=0;
int y=0;
int d = 1-2*a;
while (abs(x)<2*a)
{
 if (type==1) {
 putpixel(x+xc,-y+yc,WHITE);
 putpixel(-x+xc,-y+yc,WHITE);
 }
 if (type==4) {
 putpixel(-y+xc,x+yc,WHITE);
 putpixel(-y+xc,-x+yc,WHITE);
 }
 if (type==3) {
 putpixel(x+xc,y+yc,WHITE);
 putpixel(-x+xc,y+yc,WHITE);
 }
 if (type==2) {
 putpixel(y+xc,x+yc,WHITE);
 putpixel(y+xc,-x+yc,WHITE);
 }

 if(d<=0)
 {
  d+=3+2*x;
 }
 else
 {
  d+=3+2*x-4*a;
  y++;
 }
 x++;
}

d = (x+1/2)*(x+1/2) - 4*a*(y+1);
while(y<height)
{
 if (type==1) {
 putpixel(x+xc,-y+yc,WHITE);
 putpixel(-x+xc,-y+yc,WHITE);
 }
 if (type==4) {
 putpixel(-y+xc,x+yc,WHITE);
 putpixel(-y+xc,-x+yc,WHITE);
 }
 if (type==3) {
 putpixel(x+xc,y+yc,WHITE);
 putpixel(-x+xc,y+yc,WHITE);
 }
 if (type==2) {
 putpixel(y+xc,x+yc,WHITE);
 putpixel(y+xc,-x+yc,WHITE);
 }

 if(d<=0)
 {
  d+=2+2*x-4*a;
  x++;
 }
 else
 {
  d+=-4*a;
 }
 y++;
}

}




//3D

struct vertex
{
    float x;
    float y;
    float z;
};

draw_3dpoly(vertex temp[], int n, int edgemat[][20], int xc, int yc)
{
    for (int i=1; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (edgemat[i][j]==0)
                continue;
            line(temp[i].x+xc, temp[i].y+yc, temp[j].x+xc, temp[j].y+yc);
        }
    }
}

void sideview(vertex poly[], int n, int edgemat[][20], int xc, int yc)          //displace centre to xc,yc
{
    //yz plane
	vertex temp[20];
    for (int i=0; i<n; i++)
    {
        temp[i].x = poly[i].z;
        temp[i].y = poly[i].y;
    }
    draw_3dpoly(temp, n, edgemat, xc, yc);
}

void frontview(vertex poly[], int n, int edgemat[][20], int xc, int yc)
{
    //xy plane
	vertex temp[20];
    for (int i=0; i<n; i++)
    {
        temp[i].x = poly[i].x;
        temp[i].y = poly[i].y;
    }
    draw_3dpoly(temp, n, edgemat, xc, yc);
}

void topview(vertex poly[], int n, int edgemat[][20], int xc, int yc)
{
    //xz plane
	vertex temp[20];
    for (int i=0; i<n; i++)
    {
        temp[i].x = poly[i].x;
        temp[i].y = -poly[i].z;
    }
    draw_3dpoly(temp, n, edgemat, xc, yc);
}

void isometricview(vertex poly[], int n, int edgemat[][20], int xc, int yc)
{
	vertex temp[20];
    for (int i=0; i<n; i++)
    {
        temp[i].x = 0.707*poly[i].x - 0.707*poly[i].z;
        temp[i].y = -0.707*0.577*poly[i].x + 0.816*poly[i].y -0.577*0.707*poly[i].z;
    }
    draw_3dpoly(temp, n, edgemat, xc, yc);
}

void dimetricview(vertex poly[], int n, int edgemat[][20], int xc, int yc)
{
    //for 1:1:k
	vertex temp[20];
    float k=0.5;                     //k is always less than 1; change k here
    float costh1= sqrt(2-k*k)/sqrt(2);;
    float sinth1= k/sqrt(2);
    float costh2= sqrt(2)/sqrt(2+k*k);
    float sinth2= k/sqrt(2+k*k);;
    for (int i=0; i<n; i++)
    {
        temp[i].x = costh1*poly[i].x - sinth1*poly[i].z;
        temp[i].y = -sinth1*sinth2*poly[i].x + costh2*poly[i].y -sinth2*costh1*poly[i].z;
    }
    draw_3dpoly(temp, n, edgemat, xc, yc);
}

void perspectiveview(vertex poly[], int n, int edgemat[][20], int xc, int yc)
{
    //centre of projection; change cop here
	vertex temp[20];
    vertex cop;
    cop.x = 50;
    cop.y = -50;
    cop.z = -1000;
    for (int i=0; i<n; i++)
    {
        temp[i].x = ((poly[i].x*(-cop.z)) / ((-cop.z) + poly[i].z)) + (cop.x * poly[i].z/((-cop.z) + poly[i].z));
        temp[i].y = ((poly[i].y*(-cop.z)) / ((-cop.z) + poly[i].z)) + (cop.y * poly[i].z/((-cop.z) + poly[i].z));
    }
    draw_3dpoly(temp, n, edgemat, xc, yc);
}


//to use following 3 functions, define the polygon passed with centre at origin
void xrotateone(vertex poly[], int n, int edgemat[][20], int xc, int yc)   
{
	vertex temp[20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)    //rotates by 1 degree anticlockwise each time
		{
			cleardevice();
            for (int i=0; i<n; i++)
            {
                float x = poly[i].x;
                float y = poly[i].y;
                float z = poly[i].z;
                temp[i].x = x;
                temp[i].y = cos(thrad)*y - sin(thrad)*z;
                temp[i].z = sin(thrad)*y + cos(thrad)*z;
            }
            perspectiveview(temp, n, edgemat, xc, yc);
            delay(50);
	    }
    }
}

void yrotateone(vertex poly[], int n, int edgemat[][20], int xc, int yc)
{       
    vertex temp[20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
            for (int i=0; i<n; i++)
            {
                float x = poly[i].x;
                float y = poly[i].y;
                float z = poly[i].z;
                temp[i].x = cos(thrad)*x + sin(thrad)*z;
                temp[i].y = y;
                temp[i].z = -sin(thrad)*x + cos(thrad)*z;
            }
            perspectiveview(temp, n, edgemat, xc, yc);
            delay(50);
	    }
    }
}

void zrotateone(vertex poly[], int n, int edgemat[][20], int xc, int yc)
{
	vertex temp[20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
            for (int i=0; i<n; i++)
            {
                float x = poly[i].x;
                float y = poly[i].y;
                float z = poly[i].z;
                temp[i].x = cos(thrad)*x - sin(thrad)*y;
                temp[i].y = sin(thrad)*x + cos(thrad)*y;
                temp[i].z = z;
            }
            perspectiveview(temp, n, edgemat, xc, yc);
            delay(50);
	    }
    }
}

//to use following 4 functions, define all polygons passed with centres at origin
//and pass arrays xc and yc for displacement of centre of each polygon
void xrotatemultiple(int np, vertex polylist[][20], int n[], int edgemat[][20][20], int xc[], int yc[])
{         
	vertex temp[50][20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
                    temp[i][k].x = x;
                    temp[i][k].y = cos(thrad)*y - sin(thrad)*z;
                    temp[i][k].z = sin(thrad)*y + cos(thrad)*z;
                }
				perspectiveview(temp[i], n[i], edgemat[i], xc[i], yc[i]);
			}
            delay(50);
	    }
    }
}

void yrotatemultiple(int np, vertex polylist[][20], int n[], int edgemat[][20][20], int xc[], int yc[])
{       
    vertex temp[50][20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
                    temp[i][k].x = cos(thrad)*x + sin(thrad)*z;
                    temp[i][k].y = y;
                    temp[i][k].z = -sin(thrad)*x + cos(thrad)*z;
                }
				perspectiveview(temp[i], n[i], edgemat[i], xc[i], yc[i]);
			}
            delay(50);
	    }
    }
}

void zrotatemultiple(int np, vertex polylist[][20], int n[], int edgemat[][20][20], int xc[], int yc[])
{
	vertex temp[50][20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
                    temp[i][k].x = cos(thrad)*x - sin(thrad)*y;
                    temp[i][k].y = sin(thrad)*x + cos(thrad)*y;
                    temp[i][k].z = z;
                }
				perspectiveview(temp[i], n[i], edgemat[i], xc[i], yc[i]);
			}
            delay(50);
	    }
    }
}

//type=0 is for x-rotation ; type=1 is for y-rotation ; type=2 is for z-rotation
void rotatemultiple(int np, vertex polylist[][20], int n[], int edgemat[][20][20], int xc[], int yc[], int type[])                  
{
	vertex temp[50][20];      
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
					if (type[i]==0) {
                        temp[i][k].x = x;
                        temp[i][k].y = cos(thrad)*y - sin(thrad)*z;
                        temp[i][k].z = sin(thrad)*y + cos(thrad)*z;
					}
					if (type[i]==1) {
                        temp[i][k].x = cos(thrad)*x + sin(thrad)*z;
                        temp[i][k].y = y;
                        temp[i][k].z = -sin(thrad)*x + cos(thrad)*z;
					}
					if (type[i]==2) {
                        temp[i][k].x = cos(thrad)*x - sin(thrad)*y;
                        temp[i][k].y = sin(thrad)*x + cos(thrad)*y;
                        temp[i][k].z = z;
					}
                }
				perspectiveview(temp[i], n[i], edgemat[i], xc[i], yc[i]);
			}
            delay(50);
	    }
    }
}

//to use following 3 functions, define all polygon vertices with actual locations on screen
//to simulate plane flips, use with minimal z values of vertices
void xrotateplane(int np, vertex polylist[][20], int n[], int edgemat[][20][20])
{                                                                                        
	vertex temp[50][20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
                    temp[i][k].x = x;
                    temp[i][k].y = cos(thrad)*(y-230) - sin(thrad)*z + 230;
                    temp[i][k].z = sin(thrad)*(y-230) + cos(thrad)*z;
                }
				perspectiveview(temp[i], n[i], edgemat[i], 0, 0);
			}
            delay(50);
	    }
    }
}

void yrotateplane(int np, vertex polylist[][20], int n[], int edgemat[][20][20])
{
	vertex temp[50][20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
                    temp[i][k].x = cos(thrad)*(x-320) + sin(thrad)*z + 320;
                    temp[i][k].y = y;
                    temp[i][k].z = -sin(thrad)*(x-320) + cos(thrad)*z;
                }
				perspectiveview(temp[i], n[i], edgemat[i], 0, 0);
			}
            delay(50);
	    }
    }
}

void zrotateplane(int np, vertex polylist[][20], int n[], int edgemat[][20][20])
{
	vertex temp[50][20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
                    temp[i][k].x = cos(thrad)*(x-320) - sin(thrad)*(y-230) + 320;
                    temp[i][k].y = sin(thrad)*(x-320) + cos(thrad)*(y-230) + 230;
                    temp[i][k].z = z;
                }
				perspectiveview(temp[i], n[i], edgemat[i], 0, 0);
			}
            delay(50);
	    }
    }
}




//CURVES

//define vertex.z=0, where z is not required, before passing
void beizer(vertex p0, vertex p1, vertex p2, vertex p3, int xc, int yc)
{
    float x, y;                                                            
    for (float t=0; t<=1; t=t+0.001)
    {
        float e = -t*t*t + 3*t*t - 3*t + 1;
        float f = 3*t*t*t - 6*t*t + 3*t;
        float g = -3*t*t*t + 3*t*t;
        float h = t*t*t;

        x = e*p0.x + f*p1.x + g*p2.x + h*p3.x;
        y = e*p0.y + f*p1.y + g*p2.y + h*p3.y;

        putpixel(x+xc, y+yc, WHITE);
    }
}

void bspline(vertex p0, vertex p1, vertex p2, vertex p3, int xc, int yc)
{
    float x, y;
    for (float t=0; t<=1; t=t+0.001)
    {
        float e = -t*t*t + 3*t*t - 3*t + 1;
        float f = 3*t*t*t - 6*t*t + 4;
        float g = -3*t*t*t + 3*t*t + 3*t + 1;
        float h = t*t*t;

        x = (e*p0.x + f*p1.x + g*p2.x + h*p3.x) / 6;
        y = (e*p0.y + f*p1.y + g*p2.y + h*p3.y) / 6;

        putpixel(x+xc, y+yc, WHITE);
    }

    //follwing 4 lines mark the Control Points on screen; can comment out if required
    putpixel(p0.x, p0.y, WHITE);
    putpixel(p1.x, p1.y, WHITE);
    putpixel(p2.x, p2.y, WHITE);
    putpixel(p3.x, p3.y, WHITE);
}

void hermite(vertex p0, vertex p3, vertex r0, vertex r3, int xc, int yc)         //r0,r3 represent slopes at points p0,p3
{
    float x, y;
    for (float t=0; t<=1; t=t+0.001)
    {
        float e = 2*t*t*t - 3*t*t + 1;
        float f = -2*t*t*t + 3*t*t;
        float g = t*t*t - 2*t*t + t;
        float h = t*t*t - t*t;

        x = e*p0.x + f*p3.x + g*r0.x + h*r3.x;
        y = e*p0.y + f*p3.y + g*r0.y + h*r3.y;

        putpixel(x+xc, y+yc, WHITE);
    }
}

void zsignrotate(vertex signlist[][10], int nseg)
{
	for (int i=0; i<nseg; i++)
	{
		beizer(signlist[i][0], signlist[i][1], signlist[i][2], signlist[i][3], 0, 0);
	}
	vertex temp[50][20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<nseg; i++)
			{
                for (int k=0; k<4; k++)
                {
                    float x = signlist[i][k].x;
                    float y = signlist[i][k].y;
                    float z = signlist[i][k].z;
                    temp[i][k].x = cos(thrad)*(x-320) - sin(thrad)*(y-230) + 320;
                    temp[i][k].y = sin(thrad)*(x-320) + cos(thrad)*(y-230) + 230;
                    temp[i][k].z = z;
                }
				beizer(temp[i][0], temp[i][1], temp[i][2], temp[i][3], 0, 0);
			}
            delay(50);
	    }
    }
}




//MAGNIFICATION

void magnifywind()
{
    for (int i=0; i<580; i+=5)
    {
        cleardevice();
        mysign();                                    //replace this line with code for whatever image to be drawn on screen
        rectangle(i, 20, i+50, 200);
        for (int x=i; x<=i+50; x++)
        {
            for (int y=20; y<=200; y++)
            {
                if (getpixel(x,y) == WHITE)
                {
                    putpixel(2.5*x, 1.2*y+230, WHITE);
                }
            }
        }
        delay(100);
    }
}

void magnifyrotatemultiple(int np, vertex polylist[][20], int n[], int edgemat[][20][20], int xc[], int yc[], int type[])
{                                                            
	vertex temp[50][20];  
    int w=0;	
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
					if (type[i]==0) {
                        temp[i][k].x = x;
                        temp[i][k].y = cos(thrad)*y - sin(thrad)*z;
                        temp[i][k].z = sin(thrad)*y + cos(thrad)*z;
					}
					if (type[i]==1) {
                        temp[i][k].x = cos(thrad)*x + sin(thrad)*z;
                        temp[i][k].y = y;
                        temp[i][k].z = -sin(thrad)*x + cos(thrad)*z;
					}
					if (type[i]==2) {
                        temp[i][k].x = cos(thrad)*x - sin(thrad)*y;
                        temp[i][k].y = sin(thrad)*x + cos(thrad)*y;
                        temp[i][k].z = z;
					}
                }
				perspectiveview(temp[i], n[i], edgemat[i], xc[i], yc[i]);
			}
			rectangle(w, 50, w+50, 200);                        //adjust window size (to adjust the magnification amount) here
            for (int x=w; x<=w+50; x++)
            {
            for (int y=50; y<=200; y++)
            {
                if (getpixel(x,y) == WHITE)
                {
                    putpixel(2*x, 1.8*y+150, WHITE);
                }
            }
            }
			w+=5;
			if (w>580)
				w=0;
            delay(50);
	    }
    }
}




//SURFACES

draw_surfaces(vertex temp[], int surfaces[][10], int ns, bool visible[], int surfacecolors[], int xc, int yc)
{
    int m, n, i, j;
	int colorpoly[50];
	int ctr = -1;
    for (i=0; i<ns; i++)
    {
		ctr = -1;
        if (visible[i] == true)
        {
            for (j=0; surfaces[i][j+1]!=-1; j++)
            {
                m = surfaces[i][j];
                n = surfaces[i][j+1];
                line(temp[m].x+xc, temp[m].y+yc, temp[n].x+xc, temp[n].y+yc);
				ctr++;
				colorpoly[ctr] = (int) temp[m].x + xc;
				ctr++;
				colorpoly[ctr] = (int) temp[m].y + yc;
            }
            m = surfaces[i][j];
            n = surfaces[i][0];
            line(temp[m].x+xc, temp[m].y+yc, temp[n].x+xc, temp[n].y+yc);
			ctr++;
			colorpoly[ctr] = (int) temp[m].x + xc;
			ctr++;
			colorpoly[ctr] = (int) temp[m].y + yc;
			setfillstyle(SOLID_FILL, surfacecolors[i]);
			fillpoly((ctr+1)/2, colorpoly);
        }
    }
}

void perspectiveviewsurfaces(vertex poly[], int nv, int surfaces[][10], int ns, bool visible[], int surfacecolors[], int xc, int yc)
{
	vertex temp[20];
    vertex cop;
    cop.x = 50;
    cop.y = -50;
    cop.z = -1000000000;
    for (int i=0; i<nv; i++)
    {
        temp[i].x = ((poly[i].x*(-cop.z)) / ((-cop.z) + poly[i].z)) + (cop.x * poly[i].z/((-cop.z) + poly[i].z));
        temp[i].y = ((poly[i].y*(-cop.z)) / ((-cop.z) + poly[i].z)) + (cop.y * poly[i].z/((-cop.z) + poly[i].z));
    }
    draw_surfaces(temp, surfaces, ns, visible, surfacecolors, xc, yc);
}

void hiddensurface(vertex poly[], int nv, int surfaces[][10], int ns, bool visible[])
{
    vertex centroid = {0,0,0}; 
    for (int k=0; k<nv; k++)
    {
        centroid.x +=  poly[k].x;
        centroid.y +=  poly[k].y;
        centroid.z +=  poly[k].z;
    }
    centroid.x /= nv;
    centroid.y /= nv;
    centroid.z /= nv;

    vertex normals[10];
    vertex means[10];
    for (int i=0; i<ns; i++)
    {
        int v1 = surfaces[i][0];
        int v2 = surfaces[i][1];
        int v3 = surfaces[i][2];

        vertex v1v2 = {poly[v2].x-poly[v1].x, poly[v2].y-poly[v1].y, poly[v2].z-poly[v1].z};
        vertex v1v3 = {poly[v3].x-poly[v1].x, poly[v3].y-poly[v1].y, poly[v3].z-poly[v1].z};
        normals[i] = {v1v2.y*v1v3.z - v1v2.z*v1v3.y, v1v2.z*v1v3.x - v1v2.x*v1v3.z, v1v2.x*v1v3.y - v1v2.y*v1v3.x};

        vertex centroidv1 = {poly[v1].x-centroid.x, poly[v1].y-centroid.y, poly[v1].z-centroid.z};
        int dotprod = centroidv1.x*normals[i].x + centroidv1.y*normals[i].y + centroidv1.z*normals[i].z;
        if (dotprod<0) 
        {
            normals[i].x = -normals[i].x;
            normals[i].y = -normals[i].y;
            normals[i].z = -normals[i].z;
        }
        
        means[i] = {0,0,0};
        int m=0;
        for( ; surfaces[i][m]!=-1; m++)
        {
            means[i].x += poly[surfaces[i][m]].x;
            means[i].y += poly[surfaces[i][m]].y;
            means[i].z += poly[surfaces[i][m]].z;
        }
        means[i].x /= m;
        means[i].y /= m;
        means[i].z /= m;

        vertex light = {0,0,500};                   //light must be outside figure, adjust value of z accordingly here
        vertex light_vector = {means[i].x-light.x, means[i].y-light.y, means[i].z-light.z};

        dotprod = light_vector.x*normals[i].x + light_vector.y*normals[i].y + light_vector.z*normals[i].z;
        if (dotprod>=0)  
            visible[i] = false;
        else
            visible[i] = true;
    }
}

hiddensurfacerotatemultiple(int np, vertex polylist[][20], int n[], int surfaces[][10][10], int ns[], bool visible[][10], int surfacecolors[][10], int xc[], int yc[], int type[])
{
	vertex temp[50][20];     	
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
					if (type[i]==0) {
                        temp[i][k].x = x;
                        temp[i][k].y = cos(thrad)*y - sin(thrad)*z;
                        temp[i][k].z = sin(thrad)*y + cos(thrad)*z;
					}
					if (type[i]==1) {
                        temp[i][k].x = cos(thrad)*x + sin(thrad)*z;
                        temp[i][k].y = y;
                        temp[i][k].z = -sin(thrad)*x + cos(thrad)*z;
					}
					if (type[i]==2) {
                        temp[i][k].x = cos(thrad)*x - sin(thrad)*y;
                        temp[i][k].y = sin(thrad)*x + cos(thrad)*y;
                        temp[i][k].z = z;
					}
                }
				hiddensurface(temp[i], n[i], surfaces[i], ns[i], visible[i]);
				perspectiveviewsurfaces(temp[i], n[i], surfaces[i], ns[i], visible[i], surfacecolors[i], xc[i], yc[i]);
			}
            delay(50);
	    }
    }
}

float polyzmin(vertex poly[], int n)
{
	float zm = 10000;
	for (int i=0; i<n; i++)
	{
		if (poly[i].z<zm)
			zm = poly[i].z;
	}
	return zm;
}

void sortbyzmin(int np, vertex polylist[][20], int n[], int sortedlist[])
{
	int ctr=-1;
	int tag[20];
	for (int i=0; i<np; i++)
	{
		tag[i]=0;
	}
	for (int i=0; i<np; i++)
	{
		int pos=-1;
		int zmin = 10000;
		for (int j=0; j<np; j++)
		{
			if (tag[j]==0 && polyzmin(polylist[j],n[j])<zmin)
			{
				pos=j;
				zmin = polyzmin(polylist[j],n[j]);
			}
		}
		ctr++;
		sortedlist[ctr] = pos;
		tag[pos] = 1;
	}
}

void hiddensurfacexrotateplane(int np, vertex polylist[][20], int n[], int surfaces[][10][10], int ns[], bool visible[][10], int surfacecolors[][10])   
{
	vertex temp[50][20];
	int sortedlist[50];
	sortbyzmin(np, polylist, n, sortedlist);
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[sortedlist[i]]; k++)
                {
                    float x = polylist[sortedlist[i]][k].x;
                    float y = polylist[sortedlist[i]][k].y;
                    float z = polylist[sortedlist[i]][k].z;
                    temp[sortedlist[i]][k].x = x;
                    temp[sortedlist[i]][k].y = cos(thrad)*(y-230) - sin(thrad)*z + 230;
                    temp[sortedlist[i]][k].z = sin(thrad)*(y-230) + cos(thrad)*z;
                }
				hiddensurface(temp[sortedlist[i]], n[sortedlist[i]], surfaces[sortedlist[i]], ns[sortedlist[i]], visible[sortedlist[i]]);
				perspectiveviewsurfaces(temp[sortedlist[i]], n[sortedlist[i]], surfaces[sortedlist[i]], ns[sortedlist[i]], visible[sortedlist[i]], surfacecolors[sortedlist[i]], 0, 0);
			}
            delay(50);
			sortbyzmin(np, temp, n, sortedlist);
	    }
    }
}

void hiddensurfaceyrotateplane(int np, vertex polylist[][20], int n[], int surfaces[][10][10], int ns[], bool visible[][10], int surfacecolors[][10])   
{
	vertex temp[50][20];
	int sortedlist[50];
	sortbyzmin(np, polylist, n, sortedlist);
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[sortedlist[i]]; k++)
                {
                    float x = polylist[sortedlist[i]][k].x;
                    float y = polylist[sortedlist[i]][k].y;
                    float z = polylist[sortedlist[i]][k].z;
                    temp[sortedlist[i]][k].x = cos(thrad)*(x-320) + sin(thrad)*z + 320;
                    temp[sortedlist[i]][k].y = y;
                    temp[sortedlist[i]][k].z = -sin(thrad)*(x-320) + cos(thrad)*z;
                }
				hiddensurface(temp[sortedlist[i]], n[sortedlist[i]], surfaces[sortedlist[i]], ns[sortedlist[i]], visible[sortedlist[i]]);
				perspectiveviewsurfaces(temp[sortedlist[i]], n[sortedlist[i]], surfaces[sortedlist[i]], ns[sortedlist[i]], visible[sortedlist[i]], surfacecolors[sortedlist[i]], 0, 0);
			}
            delay(50);
			sortbyzmin(np, temp, n, sortedlist);
	    }
    }
}

void hiddensurfacezrotateplane(int np, vertex polylist[][20], int n[], int surfaces[][10][10], int ns[], bool visible[][10], int surfacecolors[][10])   
{
	vertex temp[50][20];
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
                    temp[i][k].x = cos(thrad)*(x-320) - sin(thrad)*(y-230) + 320;
                    temp[i][k].y = sin(thrad)*(x-320) + cos(thrad)*(y-230) + 230;
                    temp[i][k].z = z;
                }
				hiddensurface(temp[i], n[i], surfaces[i], ns[i], visible[i]);
				perspectiveviewsurfaces(temp[i], n[i], surfaces[i], ns[i], visible[i], surfacecolors[i], 0, 0);
			}
            delay(50);
	    }
    }
}

void hiddensurfacemagnifyrotatemultiple(int np, vertex polylist[][20], int n[], int surfaces[][10][10], int ns[], bool visible[][10], int surfacecolors[][10], int xc[], int yc[], int type[])
{
	vertex temp[50][20];   
    int w=0;  	
    while(true)
    {
		for (float thrad = 3.14/180; thrad <= 2*3.14 ; thrad+=0.01)
		{
			cleardevice();
			for (int i=0; i<np; i++)
			{
                for (int k=0; k<n[i]; k++)
                {
                    float x = polylist[i][k].x;
                    float y = polylist[i][k].y;
                    float z = polylist[i][k].z;
					if (type[i]==0) {
                        temp[i][k].x = x;
                        temp[i][k].y = cos(thrad)*y - sin(thrad)*z;
                        temp[i][k].z = sin(thrad)*y + cos(thrad)*z;
					}
					if (type[i]==1) {
                        temp[i][k].x = cos(thrad)*x + sin(thrad)*z;
                        temp[i][k].y = y;
                        temp[i][k].z = -sin(thrad)*x + cos(thrad)*z;
					}
					if (type[i]==2) {
                        temp[i][k].x = cos(thrad)*x - sin(thrad)*y;
                        temp[i][k].y = sin(thrad)*x + cos(thrad)*y;
                        temp[i][k].z = z;
					}
                }
				hiddensurface(temp[i], n[i], surfaces[i], ns[i], visible[i]);
				perspectiveviewsurfaces(temp[i], n[i], surfaces[i], ns[i], visible[i], surfacecolors[i], xc[i], yc[i]);
			}
			rectangle(w, 50, w+50, 200);                   //adjust window size (i.e. magnification amount) here
            for (int x=w; x<=w+50; x++)
            {
            for (int y=50; y<=200; y++)
            {
				int c = getpixel(x,y);
                if (c != BLACK)
                {
                    putpixel(2*x, 1.8*y+150, c);
                }
            }
            }
			w+=5;
			if (w>580)
				w=0;
            delay(50);
	    }
    }
}




//2-D UTILITIES

void draw_poly(vertex vlist[], int n)
{
    for (int i=0; i<n; i++)
        line(vlist[i].x, vlist[i].y, vlist[(i+1)%n].x, vlist[(i+1)%n].y);
}

int in_out(float x, float y, int x1, int y1, int x2, int y2)
{
    float p = (y-y1)*(x2-x1) - (x-x1)*(y2-y1);
    if (p<0)
        return 0;
    return 1; 
}

void intersection_line(float &x, float &y, float x1, float y1, float x2, float y2, int xa, int ya, int xb, int yb)
{
    if (x2==x1)
    {
        float m2 = (yb-ya) / (xb-xa);
        x = x1;
        y = ya - m2*(xa-x1);
    }
    else if (xb==xa)
    {
        float m1 = (y2-y1) / (x2-x1);
        x = xa;
        y = y1 + m1*(xa-x1);
    }
    else
    {
        float m1 = (y2-y1) / (x2-x1); 
        float m2 = (yb-ya) / (xb-xa);
        x = (ya-y1 + m1*x1 - m2*xa) / (m1-m2);
        y = (m1*m2*(xa-x1) + m2*y1 - m1*ya) / (m2-m1);
    }
}

void intersection_lineseg(float &x, float &y, int x1, int y1, int x2, int y2, int xa, int ya, int xb, int yb)
{
    x = -1;
    y = -1;
    if (x2==x1 && xb==xa)
        return;
    else if (x2==x1)
    {
        float m2 = (yb-ya) / (float) (xb-xa);
        x = x1;
        y = ya - m2*(xa-x1);
    }
    else if (xb==xa)
    {
        float m1 = (y2-y1) / (float) (x2-x1);
        x = xa;
        y = y1 + m1*(xa-x1);
    }
    else
    {
        float m1 = (y2-y1) / (float) (x2-x1);
        float m2 = (yb-ya) / (float) (xb-xa);
        if (m1==m2)
            return;
        x = (ya-y1 + m1*x1 - m2*xa) / (m1-m2);
        y = (m1*m2*(xa-x1) + m2*y1 - m1*ya) / (m2-m1);
    }

    if ((x1>=x2 && (x<x2||x>x1)) || (x2>=x1 && (x>x2||x<x1)) || (y1>=y2 && (y<y2||y>y1)) || (y2>=y1 && (y>y2||y<y1))
            || (xa>=xb && (x<xb||x>xa)) || (xb>=xa && (x>xb||x<xa)) || (ya>=yb && (y<yb||y>ya)) || (yb>=ya && (y>yb||y<ya)))
    {
        x = -1;
        y = -1;
    }
}




//2D CLIPPING

void wa_clip(vertex cw[40], int n_cw, vertex sp[40], int n_sp)
{                                                    
    vertex tempcw[40], tempsp[40];
    int tag_sp[40], tag_cw[40], trav_sp[40], trav_cw[40];
    float x,y;
    int entry_list[10];
    int e=-1;

    int kc=-1;
    for (int i=0; i<n_cw; i++)
    {
        vertex tempi[20][2];  
        int ti = -1;
        for (int j=0; j<n_sp; j++)
        {
            intersection_lineseg(x, y, cw[i].x, cw[i].y, cw[(i+1)%n_cw].x, cw[(i+1)%n_cw].y,
                                 sp[j].x, sp[j].y, sp[(j+1)%n_sp].x, sp[(j+1)%n_sp].y);
            if (x==-1)
                continue;
            ti++;
            tempi[ti][0].x = x;
            tempi[ti][0].y = y;
            int p1 = in_out(sp[j].x, sp[j].y, cw[i].x, cw[i].y, cw[(i+1)%n_cw].x, cw[(i+1)%n_cw].y);
            int p2 = in_out(sp[(j+1)%n_sp].x, sp[(j+1)%n_sp].y, cw[i].x, cw[i].y, cw[(i+1)%n_cw].x, cw[(i+1)%n_cw].y);
            if (p1==1 && p2==0)
                tempi[ti][1].x = 1;    
            else
                tempi[ti][1].x = 0;
        }
        if (ti!=-1)
        {
            if (cw[(i+1)%n_cw].x > cw[i].x)
            {
                int min_idx;
                for (int k=0; k<ti; k++)
                {
                    min_idx = k;
                    for (int m=k+1; m<ti+1; m++)
                    {
                        if (tempi[m][0].x < tempi[min_idx][0].x)
                            min_idx=m;
                    }
                    float temp = tempi[min_idx][0].x;
                    tempi[min_idx][0].x = tempi[k][0].x;
                    tempi[k][0].x = temp;
                    temp = tempi[min_idx][0].y;
                    tempi[min_idx][0].y = tempi[k][0].y;
                    tempi[k][0].y = temp;
                    temp = tempi[min_idx][1].x;
                    tempi[min_idx][1].x = tempi[k][1].x;
                    tempi[k][1].x = temp;
                }
            }
            else if (cw[(i+1)%n_cw].x < cw[i].x)
            {
                int max_idx;
                for (int k=0; k<ti; k++)
                {
                    max_idx = k;
                    for (int m=k+1; m<ti+1; m++)
                    {
                        if (tempi[m][0].x > tempi[max_idx][0].x)
                            max_idx=m;
                    }
                    float temp = tempi[max_idx][0].x;
                    tempi[max_idx][0].x = tempi[k][0].x;
                    tempi[k][0].x = temp;
                    temp = tempi[max_idx][0].y;
                    tempi[max_idx][0].y = tempi[k][0].y;
                    tempi[k][0].y = temp;
                    temp = tempi[max_idx][1].x;
                    tempi[max_idx][1].x = tempi[k][1].x;
                    tempi[k][1].x = temp;
                }
            }
            else if (cw[(i+1)%n_cw].y > cw[i].y)
            {
                int min_idx;
                for (int k=0; k<ti; k++)
                {
                    min_idx = k;
                    for (int m=k+1; m<ti+1; m++)
                    {
                        if (tempi[m][0].y < tempi[min_idx][0].y)
                            min_idx=m;
                    }
                    float temp = tempi[min_idx][0].x;
                    tempi[min_idx][0].x = tempi[k][0].x;
                    tempi[k][0].x = temp;
                    temp = tempi[min_idx][0].y;
                    tempi[min_idx][0].y = tempi[k][0].y;
                    tempi[k][0].y = temp;
                    temp = tempi[min_idx][1].x;
                    tempi[min_idx][1].x = tempi[k][1].x;
                    tempi[k][1].x = temp;
                }

            }
            else
            {
                int max_idx;
                for (int k=0; k<ti; k++)
                {
                    max_idx = k;
                    for (int m=k+1; m<ti+1; m++)
                    {
                        if (tempi[m][0].y > tempi[max_idx][0].y)
                            max_idx=m;
                    }
                    float temp = tempi[max_idx][0].x;
                    tempi[max_idx][0].x = tempi[k][0].x;
                    tempi[k][0].x = temp;
                    temp = tempi[max_idx][0].y;
                    tempi[max_idx][0].y = tempi[k][0].y;
                    tempi[k][0].y = temp;
                    temp = tempi[max_idx][1].x;
                    tempi[max_idx][1].x = tempi[k][1].x;
                    tempi[k][1].x = temp;
                }
            }

            for (int k=0; k<=ti; k++)
            {
                kc++;
                tempcw[kc].x = tempi[k][0].x;
                tempcw[kc].y = tempi[k][0].y;
                tag_cw[kc] = tempi[k][1].x;
                trav_cw[kc] = 0;
            }
        }

        kc++;
        tempcw[kc].x = cw[(i+1)%n_cw].x;
        tempcw[kc].y = cw[(i+1)%n_cw].y;
        tag_cw[kc] = -1;
        trav_cw[kc] = 0;
    }

    int ks=-1;
    for (int i=0; i<n_sp; i++)
    {
        vertex tempi[20][2];
        int ti = -1;
        for (int j=0; j<n_cw; j++)
        {
            intersection_lineseg(x, y, cw[j].x, cw[j].y, cw[(j+1)%n_cw].x, cw[(j+1)%n_cw].y,
                                 sp[i].x, sp[i].y, sp[(i+1)%n_sp].x, sp[(i+1)%n_sp].y);
            if (x==-1)
                continue;
            ti++;
            tempi[ti][0].x = x;
            tempi[ti][0].y = y;
            int p1 = in_out(sp[i].x, sp[i].y, cw[j].x, cw[j].y, cw[(j+1)%n_cw].x, cw[(j+1)%n_cw].y);
            int p2 = in_out(sp[(i+1)%n_sp].x, sp[(i+1)%n_sp].y, cw[j].x, cw[j].y, cw[(j+1)%n_cw].x, cw[(j+1)%n_cw].y);
            if (p1==1 && p2==0) {
                tempi[ti][1].x = 0;
                }   
            else {
                tempi[ti][1].x = 1;
            }
        }

        if (ti!=-1)
        {
            if (sp[(i+1)%n_sp].x > sp[i].x)
            {
                int min_idx;
                for (int k=0; k<ti; k++)
                {
                    min_idx = k;
                    for (int m=k+1; m<ti+1; m++)
                    {
                        if (tempi[m][0].x < tempi[min_idx][0].x)
                            min_idx=m;
                    }
                    float temp = tempi[min_idx][0].x;
                    tempi[min_idx][0].x = tempi[k][0].x;
                    tempi[k][0].x = temp;
                    temp = tempi[min_idx][0].y;
                    tempi[min_idx][0].y = tempi[k][0].y;
                    tempi[k][0].y = temp;
                    temp = tempi[min_idx][1].x;
                    tempi[min_idx][1].x = tempi[k][1].x;
                    tempi[k][1].x = temp;
                }
            }
            else if (sp[(i+1)%n_sp].x < sp[i].x)
            {
                int max_idx;
                for (int k=0; k<ti; k++)
                {
                    max_idx = k;
                    for (int m=k+1; m<ti+1; m++)
                    {
                        if (tempi[m][0].x > tempi[max_idx][0].x)
                            max_idx=m;
                    }
                    float temp = tempi[max_idx][0].x;
                    tempi[max_idx][0].x = tempi[k][0].x;
                    tempi[k][0].x = temp;
                    temp = tempi[max_idx][0].y;
                    tempi[max_idx][0].y = tempi[k][0].y;
                    tempi[k][0].y = temp;
                    temp = tempi[max_idx][1].x;
                    tempi[max_idx][1].x = tempi[k][1].x;
                    tempi[k][1].x = temp;
                }
            }
            else if (sp[(i+1)%n_sp].y > sp[i].y)
            {
                int min_idx;
                for (int k=0; k<ti; k++)
                {
                    min_idx = k;
                    for (int m=k+1; m<ti+1; m++)
                    {
                        if (tempi[m][0].y < tempi[min_idx][0].y)
                            min_idx=m;
                    }
                    float temp = tempi[min_idx][0].x;
                    tempi[min_idx][0].x = tempi[k][0].x;
                    tempi[k][0].x = temp;
                    temp = tempi[min_idx][0].y;
                    tempi[min_idx][0].y = tempi[k][0].y;
                    tempi[k][0].y = temp;
                    temp = tempi[min_idx][1].x;
                    tempi[min_idx][1].x = tempi[k][1].x;
                    tempi[k][1].x = temp;
                }

            }
            else
            {
                int max_idx;
                for (int k=0; k<ti; k++)
                {
                    max_idx = k;
                    for (int m=k+1; m<ti+1; m++)
                    {
                        if (tempi[m][0].y > tempi[max_idx][0].y)
                            max_idx=m;
                    }
                    float temp = tempi[max_idx][0].x;
                    tempi[max_idx][0].x = tempi[k][0].x;
                    tempi[k][0].x = temp;
                    temp = tempi[max_idx][0].y;
                    tempi[max_idx][0].y = tempi[k][0].y;
                    tempi[k][0].y = temp;
                    temp = tempi[max_idx][1].x;
                    tempi[max_idx][1].x = tempi[k][1].x;
                    tempi[k][1].x = temp;
                }
            }

            for (int k=0; k<=ti; k++)
            {
                ks++;
                tempsp[ks].x = tempi[k][0].x;
                tempsp[ks].y = tempi[k][0].y;
                tag_sp[ks] = tempi[k][1].x;
                if (tag_sp[ks]==1) {
                    e++;
                    entry_list[e] = ks;
                }
                trav_sp[ks] = 0;
            }
        }

        ks++;
        tempsp[ks].x = sp[(i+1)%n_sp].x;
        tempsp[ks].y = sp[(i+1)%n_sp].y;
        tag_sp[ks] = -1;
        trav_sp[ks] = 0;
    }

    n_cw = kc+1;
    n_sp = ks+1;

    for (int i=0; i<=e; i++)
    {
        bool done = false;
        int j = entry_list[i];
        while(!done)
        {
            if (trav_sp[j] == 1)
                done = true;
            else if (tag_sp[j] == 1 || tag_sp[j] == -1)
            {
                line(tempsp[j].x, tempsp[j].y, tempsp[(j+1)%n_sp].x, tempsp[(j+1)%n_sp].y);
                trav_sp[j] = 1;
                j++;
            }
            else if (tag_sp[j] == 0)
            {
                trav_sp[j] = 1;
                for (int k=0; k<n_cw; k++)
                {
                    if (tempcw[k].x==tempsp[j].x && tempcw[k].y==tempsp[j].y)
                    {
                        j = k;
                        break;
                    }
                }

                swap(tempcw, tempsp);
                swap(tag_cw, tag_sp);
                swap(trav_cw, trav_sp);

                int n = n_cw;
                n_cw = n_sp;
                n_sp = n_cw;
            }
        }
    }
	draw_poly(cw, n_cw);
}



/* BUILT AND OWNED BY TUHINA SINGH; AVAILABLE FOR USE AT: github.com/snow88/TheTSGraphicsLibrary */
