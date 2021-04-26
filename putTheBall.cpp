//============================================================================
// Name        : putTheBall.cpp
// Author      : Allan S
// Version     : 1.0
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<conio.h>
#include<windows.h>
#include <graphics.h>
using namespace std;
const int width=20,height=20;
const int basX=0,basY=20;
int ballX=width/2,ballY=height/2;
int shootX=ballX,shootY=ballY;
int basXTemp = basX;
int shoot =0;
bool gameOver=false;
int score =0;
int life=3;
int sleep;
void draw() {


	system("cls");
	 cout<<"score:"<<score<<"     "<<"Life:"<<life<<endl;
	for (int i = 0; i < width; i++) {
		cout << "_";
	}
	cout << endl;
	for (int i = 0; i < height ; i++) {
		for (int j = 0; j < width; j++) {
			if ((j == 0&&j!=(ballX))||(j==0&&i!=(ballY)) ){
				cout << "|";
			}
			else if(shootY!=ballY&&j==shootX&&i==shootY){
				cout<<"O";
				shoot=1;
			}
			else if(i==ballY && j==ballX){
				cout<<"@";
			}
			else if(j==width-1){
			   	cout<<"|";
                }
			else{
			cout << " ";
			}
			if((i+1>(height/2) -2&&i+1<=(height/2)+4)&&j== width -1){
               switch(i+1){
               case (height/2-1):
				    cout<<"        "<<"w - Move Up"<<"     F - Shoot                 "<<"Rules are Simple:";
                   break;
               case (height/2):
                  cout<<"        "<<"s - Move Down"<<"                                    "<<"1)If you go out of the grid, Game Over";
                       break;
               case (height/2+1):
              		cout<<"        "<<"a - Move left"<<"                                    "<<"2)If you are out of life, Game Over";
                       break;
               case (height/2+2):
              			cout<<"        "<<"d - Move Right"<<"                                   "<<"3)Goals = 1 Level. Total Levels = 3. ";
               case (height/2+3):
            		   break;
               case (height/2+4):
            		   cout<<"      "<<"Note: Capslock must be disabled";
                       break;

               }

			}

	   }
		if(shoot==1){
			shootY++;
			shoot=0;
			if(shootY==20||shootY==21){
				cout<<endl;
				break;
			}
		}
		cout<<endl;
	}
	for (int i = 0; i <=width-1; i++) {
		if(i==basXTemp&&i!=0&&i!=width-1){
		if(shootX==basXTemp&&(shootY == basY||shootY==basY+1)){
			//cout<<endl<<"baseXTemp:"<<basXTemp<<"shootX:"<<shootX<<"shootY:"<<shootY<<"basY:"<<basY;
				score=score+50;
			  shootY=ballY;
			  shootX=ballX;
			  cout<<"U";
         cout<<endl<<endl<<endl<<endl<<"GOAL";

         Sleep(2000);
         return;
		 }
		else if((shootY==(basY+1) ||shootY==basY)&&shootX!=basXTemp){
			cout<<"U";
		      cout<<endl<<endl<<endl<<endl<<"Target Missed";
		      shootY=ballY;
		     	shootX=ballX;
		     	life= life -1;
		         Sleep(2000);
		         if(life==0){
		        	 cout<<endl<<"Out of life"<<endl;
		        	 Sleep(2000);
		        	 return;
		         }
		}
		else{
			cout<<"U";

		 }
		}
		else{
			cout<<" ";
		}
	}
	 //cout<<endl<<"baseXTemp:"<<basXTemp<<"shootX:"<<shootX<<"shootY:"<<shootY<<"basY:"<<basY;
	cout<<endl;
	if(basXTemp==19){
			basXTemp=0;
		}
	if(shootY>20)
		getch();
}

void input(){
	if(shootY==ballY){
	if(_kbhit()){
		switch(_getch()){
		case 'w':
			ballY--;
			shootY=ballY;
			break;
		case 'a':
			ballX--;
			shootX=ballX;
			break;
		case 's':
			ballY++;
			shootY=ballY;
			break;
		case 'd':
			ballX++;
			shootX=ballX;
		    break;
		case 'f':
			shootY=ballY+1;
			break;
		case 'x':
			gameOver = true;
			break;
		}
		//cout<<endl<<"ballX:"<<ballX<<"ballY:"<<ballY<<endl;
	 }
	if(ballX<0||ballX>20||ballY<0){
		cout<<endl<<"You went off the grid"<<endl;
		Sleep(2000);
		gameOver = true;
	 }
	}
}

void logic(){

}

int main() {
	//PlaySound("music.bat.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	 int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	 int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	    // a graphics driver from disk
	    initwindow(screenWidth,screenHeight,"",-3,-3);

	    // location of text
	    float x = screenWidth/3;
	    int y = screenHeight/2.5;
        int fontStyle=2;
	    setcolor(fontStyle);
	    // font style

	    // font direction
	    int direction = 0;

	    // font size
	    int font_size = 20;

	    // for setting text style
	    settextstyle(fontStyle, direction, font_size);

	    //for printing text in graphics window
	    outtextxy(x, y, "AllanGameranx Presents");
        Sleep(2000);
        x = screenWidth/3.3;
        y = screenHeight/2.5;
	    fontStyle=10;
	    setcolor(fontStyle);
	    font_size= 10;
	    settextstyle(fontStyle, direction, font_size);
	    outtextxy(x,y,"Put the Ball");
	    Sleep(2000);
	    x = screenWidth/3;
	           y = screenHeight/1.8;
	   	    fontStyle=2;
	   	    setcolor(fontStyle);
	   	    font_size= 10;
	   	    settextstyle(fontStyle, direction, font_size);
	   	    outtextxy(x,y,"Press any key to continue");
	    getch();
	    closegraph();
    again:
	int count=0;
	int option;
	int minus;
    cout<<endl<<"Choose Difficulty:"<<endl<<"  "<<"1. Ultra Noobs"<<"     2.Noobs  "<<"     3. Death Confirmed";
    cout<<endl<<"    Enter your Option:";
    cin>>option;
    switch(option){
    case 1:
    	sleep=100;
    	minus=25;
    	break;
    case 2:
    	sleep = 50;
    	minus = 12;
    	break;
    case 3:
    	sleep = 10;
    	minus = 3;
    	break;
    default:
    	cout<<endl<<"Incorrect option. Please Enter again."<<endl;
    	goto again;
    }
	while(gameOver!=true&&life!=0){
    draw();
    input();
    logic();
    basXTemp++;
    if((score%150==count||score%300==count-1||score%450==count-2)&&score!=0){
    	 initwindow(screenWidth,screenHeight,"",-3,-3);

    		   x = screenWidth/3;
    		   	    y = screenHeight/2.5;
    			    setcolor(fontStyle);
    			    font_size = 40;

    			    // for setting text style
    			    settextstyle(fontStyle, direction, font_size);

    			    //for printing text in graphics window
    			    outtextxy(x, y, "Next Level");
    		        Sleep(2000);
    		        closegraph();
    	sleep=sleep-minus;
    	count++;
    }
    if(score==600){
    	 initwindow(screenWidth,screenHeight,"",-3,-3);

    	    		   x = screenWidth/3;
    	    		   	    y = screenHeight/2.5;
    	    			    setcolor(fontStyle);
    	    			    font_size = 40;

    	    			    // for setting text style
    	    			    settextstyle(fontStyle, direction, font_size);

    	    			    //for printing text in graphics window
    	    			    outtextxy(x, y, "Winner Winner Chicken Dinner");
    	    		        Sleep(2000);
    	    		        return 0;
    	    		        closegraph();
    }
    Sleep(sleep);
	}
	   initwindow(screenWidth,screenHeight,"",-3,-3);

	   x = screenWidth/3;
	   	    y = screenHeight/2.5;
		    setcolor(fontStyle);
		    font_size = 20;

		    // for setting text style
		    settextstyle(fontStyle, direction, font_size);

		    //for printing text in graphics window
		    outtextxy(x, y, "Game Over");
	        Sleep(2000);
	        closegraph();
	_getch();
	return 0;
}
