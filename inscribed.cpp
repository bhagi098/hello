#include<graphics.h> 
#include<iostream> 
using namespace std; 
class Pixel 
{ 
	protected: 
		int x1,y1; 
	public: 
		Pixel() 
		{ 
			x1=0; 
			y1=0; 
		} 
		void setCordinate(int x,int y) 
		{ 
			x1=x; 
			y1=y; 
		} 
}; 
class Point 
{ 
	protected: 
		int xco,yco,color; 
	public: 
		Point() 
		{ 
			xco=0; 
            	yco=0; 
            	color=15; 
		} 
		void setco(int x,int y) 
		{ 
            	xco=x; 
            	yco=y; 
        	} 
		void setcolor(int c) 
		{ 
			color=c; 
		} 
		void draw() 
		{ 
			putpixel(xco,yco,color); 
		} 
}; 
class dline: public Point 
{ 
	private: 
    		int x2,y2; 
     public: 
		dline():Point() 
		{ 
			x2=0,y2=0; 
		} 
		void setline(int x, int y, int xx, int yy) 
		{ 
			Point::setco(x,y); 
            	x2=xx; 
            	y2=yy; 
       	} 
	    	void drawl() 
        	{ 
			float x,y,dx,dy,e,temp; 
			int i,s1,s2,ex; 
			int xmax,xmid,ymax,ymid; 
			xmax = getmaxx(); 
			ymax = getmaxy(); 
			xmid = xmax /2; 
			ymid = ymax /2; 
			dx=abs(x2-xco); 
            	dy=abs(y2-yco); 
			x=xco; 
            	y=yco; 
            	Point::setco(x,y); 
            	Point::draw(); 
			if(x2 > xco) 
			{ 
				s1=1; 
            	} 
            	if(x2 < xco) 
            	{ 
              		s1=-1; 
            	} 
            	if(x2 == xco) 
            	{ 
               	s1=0; 
            	}	 
			if(y2 > yco) 
            	{ 
             		s2=1; 
           	} 
           	if(y2 < yco) 
           	{ 
           		s2=-1; 
           	} 
           	if(y2 == yco) 
            	{ 
               		s2=0; 
            	} 
            	if(dy > dx) 
            	{ 
               		temp = dx; 
               		dx = dy; 
               		dy = temp; 
               		ex = 1; 
            	} 
            	else 
            	{ 
               		ex=0; 
            	} 
			e=2*dy-dx; 
           	i=1; 
           	do 
           	{ 
				while(e>=0) 
               	{ 
					if(ex==1) 
          			{ 
						x = x + s1; 
                    	} 
                    	else 
                    	{ 
                    		y = y + s2; 
                    	} 
                    	e = e - 2*dx; 
				} 
				if(ex==1) 
                	{ 
					y = y + s2; 
               	} 
                	else 
				{ 
                    	x = x + s1; 
                	} 
				e = e + 2*dy; 
             		Point::setco(x,y); 
              		Point::draw(); 
                	i = i + 1; 
			}while(i<=dx); 
		} 
};     
class BrCircle:public Pixel 
{ 
	int r; 
	public: 
	BrCircle():Pixel() 
	{ 
		r=0; 
	} 
	void setr(int r1) 
	{ 
		r=r1; 
	} 
	void drawBrcircle() 
     { 
     	int i,x,y; 
     	float d; 
     	x=0, y=r; 
     	d = 3 -(2*r); 
		do 
		{ 
          	putpixel(x1+x, y1+y,15); 
          	putpixel(x1+y, y1+x,15); 
             	putpixel(x1+y, y1-x,15); 
       	     putpixel(x1+x, y1-y,15); 
          	putpixel(x1-x, y1-y,15); 
           	putpixel(x1-y, y1-x,15); 
           	putpixel(x1-y, y1+x,15); 
           	putpixel(x1-x, y1+y,15); 
           	if(d<=0) 
         		{ 
           		x = x + 1; 
            		d = d + (4*x) + 6; 
          	} 
          	else 
           	{ 
             		x = x + 1; 
              		y = y - 1; 
              		d = d + (4*x-4*y) + 10; 
           	} 
        	}while(x<=y); 
    } 
}; 
int main() 
{ 
	int gd=DETECT,gm; 
	initgraph(&gd,&gm,NULL); 
	int x1,y1,x2,y2; 
	int xmax,ymax,xmid,ymid; 
	int x,y,r; 
	char ch; 
	BrCircle b1; 
	Point p; 
    	dline dda; 
    	xmax=getmaxx(); 
	ymax=getmaxy(); 
	xmid=xmax/2; 
	ymid=ymax/2; 
	do 
	{ 
		cout<<"\n Enter x Value: "; cin>>x; 
		cout<<"\n Enter yValue: "; cin>>y; 
		cout<<"\n Enter radius: "; cin>>r; 
     	b1.setCordinate(x,y); 
     	b1.setr(r); 
     	b1.drawBrcircle(); 
        	cout<<"Do you want to draw another circle:"; 
        	cin>>ch; 
     }while(ch=='y'||ch=='Y');      
    	do 
    	{    
		cout<<"\nEnter the co-ordinates of the endpoints of line 		Below"; 
		cout<<"\nEnter x1: "; cin>>x1; 
       	cout<<"Enter y1: "; cin>>y1; 
        	cout<<"Enter x2: "; cin>>x2; 
        	cout<<"Enter y2: "; cin>>y2; 
        	dda.setline(x1,y1,x2,y2); 
        	dda.drawl(); 
        	cout<<"Do you want to draw More lines:"; 
        	cin>>ch; 
      }while(ch=='y'||ch=='Y'); 
      delay(3000); 
      getch(); 
      closegraph(); 
      return 0; 
} 
