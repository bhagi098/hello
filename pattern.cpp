/*
ASSIGNMENT NO:5
Roll_No:71
Batch_NO:4
TITLE:Write C++/Java program to draw the following pattern using any Line drawing algorithms.
*/
#include<graphics.h>
#include<iostream>
using namespace std;

class pt
{
	protected :
		int xco,yco,color;
		public:
			pt()
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
class dline : public pt
{
	private :
		int x2,y2;
	public:
		dline():pt()
		{
			x2=0;
			y2=0;
		}
		void setline(int x,int y,int xx,int yy)
		{
			pt::setco(x,y);
			x2=xx;
			y2=yy;
		}
		void draw(int colour)
		{
			float x,y,dx,dy,length;
			int i;
			pt::setcolor(colour);
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			if(dx>=dy)
				length=dx;
			else
				length=dy;
			dx=(x2-xco)/length;
			dy=(y2-yco)/length;
			x=xco;
			y=yco;
			i=1;
			while(i<=length)
			{
				pt::setco(x,y);
				pt::draw();
				x=x+dx;
				y=y+dy;
				i=i+1;
			}
			pt::setco(x,y);
			pt::draw();
		}
};
void drawfig(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int n)
{
	int m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y;
	dline l1;
	l1.setline(ax,ay,bx,by);
	l1.draw(15);
		
	l1.setline(bx,by,cx,cy);
	l1.draw(15);
	
	l1.setline(cx,cy,dx,dy);
	l1.draw(15);

	l1.setline(dx,dy,ax,ay);
	l1.draw(15);

	
	m1x=(ax+bx)/2;
	m1y=(ay+by)/2;
	m2x=(bx+cx)/2;
	m2y=(by+cy)/2;
	m3x=(cx+dx)/2;
	m3y=(cy+dy)/2;
	m4x=(dx+ax)/2;
	m4y=(dy+ay)/2;

	n--;
	if(n!=0)
		drawfig(m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y,n)  ;
}
int main()
{
	int gd=DETECT,gm=VGAMAX;
	int x1,x2,y1,y2;
	pt p1;

	dline l;
	cout<<"\nEnter two end points of line";
	cout<<"\nEnter the value of Left Bottom x1::";
	cin>>x1;
	cout<<"\nEnter the value of Left Bottom y1::";
	cin>>y1;
	cout<<"\nEnter the value of Right Top x2::";
	cin>>x2;
	cout<<"\nEnter the value of Right Top y2::";
	cin>>y2;
	initgraph(&gd,&gm,NULL);
	
	drawfig(x1,y1,x1,y2,x2,y2,x2,y1,3);
	
	getch();
	closegraph();
	return 0;
}
/*OUTPUT
linux16@ubuntu16:~/roll70$ g++ ass5.cpp -lgraph
linux16@ubuntu16:~/roll70$ ./a.out

Enter two end points of line
Enter the value of Left Bottom x1::90

Enter the value of Left Bottom y1::100

Enter the value of Right Top x2::150

Enter the value of Right Top y2::200
*/