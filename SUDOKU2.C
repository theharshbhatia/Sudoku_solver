#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>
#include<time.h>

int a[9][9],b[9][9];

void gotoxy(int x,int y);

void main2();

void main1();

void solve(int a[9][9]);

void movement(int,int);

struct node
{
	int data;
	struct node *nxt,*dwn;

}*start,*end,*tmp;

struct rhd
{
	int r;
	struct rhd *dwn;
	struct node *lnkr;

}*startr[9],*endr,*tmpr;

struct chd
{
	int c;
	struct chd *right;
	struct node *linkc;

}*startc[9],*endc,*tmpc;

void table();

struct length
{
	int rl,cl;

}len[9];

int n,f;

struct node* create_LL()
{
	int i;
	start=NULL;

	for(i=0;i<=len[n].cl;i++)
	{
		tmp=(struct node*)malloc(sizeof(struct node));
		tmp->nxt=NULL;
		tmp->data=0;
		if(start==NULL)
		{
			start=tmp;
			end=tmp;
		}
		else
		{
			end->nxt=tmp;
			end=tmp;
		}
	}
	return(start);

}

void create_row()
{
	int j;
	startr[n]=NULL;

	for(j=0;j<=len[n].rl;j++)
	{
		tmpr=(struct rhd*)malloc(sizeof(struct rhd));
		tmpr->r=j;
		tmpr->lnkr=create_LL();
		tmpr->dwn=NULL;
		if(startr[n]==NULL)
		{
			startr[n]=tmpr;
			endr=tmpr;
		}
		else
		{
			endr->dwn=tmpr;
			endr=tmpr;
		}
	}

}

void create_col()
{
	int k;
	startc[n]=NULL;

	for(k=0;k<=len[n].cl;k++)
	{
		tmpc=(struct chd*)malloc(sizeof(struct chd));
		tmpc->c=k;
		tmpc->right=NULL;
		if(startc[n]==NULL)
		{
			startc[n]=tmpc;
			endc=tmpc;
		}
		else
		{
			endc->right=tmpc;
			endc=tmpc;
		}
	}

}

void link()
{
	struct node *x;
	struct chd *y;
	x=startr[n]->lnkr;
	y=startc[n];

	while(y!=NULL)
	{
		y->linkc=x;
		x=x->nxt;
		y=y->right;
	}

}

void link_LL()
{
	struct node *x,*y;
	struct rhd *z;
	z=startr[n];

	while(z->dwn!=NULL)
	{
		x=z->lnkr;
		y=z->dwn->lnkr;

		while(x!=NULL)
		{
			x->dwn=y;
			x=x->nxt;
			y=y->nxt;
			y->dwn=NULL;
		}
		z=z->dwn;
	}

}

struct node * add()
{
	int i;
	n=2;

	for(i=0;i<=len[n].cl;i++)
	{
		tmp=(struct node*)malloc(sizeof(struct node));
		tmp->nxt=NULL;
		tmp->data=0;
		if(start==NULL)
		{
			start=tmp;
			end=tmp;
		}
		else
		{
			end->nxt=tmp;
			end=tmp;
		}
	}
	return(start);

}

void intro()
{
	char e;
	int x,y,d,n;
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"F:\\TC\\BGI");
	settextstyle(4,0,5);
	setcolor(1);

	setbkcolor(9);
	outtextxy(100,10,"\n\t\t\t\tSudoku (format n Rules)\n\n");
	gotoxy(6,7);
	printf("   A sudoku puzzle consists of 81square placed in a square (9x9) formation. These 81 squares are furthe subdivided (three-dimentionally) into three\n combination of nine squares each namely :-\n");
	printf("\t(i) Horizontally into 9 'Files'\n");
	printf("\t(ii) vertically into 9 'Ranks'\n");
	printf("\t(iii) into 9 (3x3)'House' (mini boxes)\n");
	printf("\n	Each Grid (of 9 square) is Home to one set of nine single digits (1-2-3-4-5-6-7-8 and 9)\n\n\tNo digit appears twice within the same 'File' 'Rank' and 'House'(grid).");
	printf("\n\n\tIn short, the Rule is every 'File',every 'Rank' and every (3x3)  'House' contains digits 1 to 9.");
	settextstyle(11,0,3);
	setcolor(15);
	outtextxy(180,400,"Press 'B' to go back to main menu");
	e=getch();
	if(e==98)
	{
		main2();
	}

	//getch();
	//restorecrtmode();
	//closegraph();

}

void title()
{
	int x,y,d,n,i,j;
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"F:\\TC\\BGI");
	setcolor(1);
	setbkcolor(9);

	rectangle (99,299,541,321);
	rectangle (10,10,625,470);
	rectangle (15,15,620,465);
//setcolor(4);
	floodfill(12,11,1);

	settextstyle(8,0,2);
	outtextxy(100,270,"Loading Please wait . . .");

	for(j=0;j<440;j=j+40)
	{
		setcolor(j-3);
		settextstyle(4,0,9);
		outtextxy(95,20,"SU-DOKU");
//rectangle(100,300,540,330);
		setcolor(12);
		for(i=0;i<400;i++)
		{
			line(100+i,300,100+i,320);
			delay(1);
		}
		setcolor(8);
		bar(100,350,100+j+40,380);
		bar(100,300,540,320);
		gotoxy(40,270);

		printf("%d %",(j/4));

	}
	//getch();
	//restorecrtmode();
	//closegraph();

}


void option()
{
	char e;
	int x,y,d,n;
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"F:\\TC\\BGI");
	settextstyle(4,0,5);
	setcolor(1);

	setbkcolor(9);
	outtextxy(230,10,"Controls");
	settextstyle(8,0,3);
	setcolor(6);
	outtextxy(100,70,"keys");
	outtextxy(400,70,"functions");
	printf("\n\n\n\n\n\n");
	printf("\n\n\t'W' \t\t\t move to one up of respective box");
	printf("\n\n\t'S' \t\t\t move to one dwn of respective box");
	printf("\n\n\t'D' \t\t\t move to one right of respective box");
	printf("\n\n\t'A' \t\t\t move to one left of respective box");
	printf("\n\n\t'Z' button \t\t\t\t Enter");
	printf("\n\n\t'X' button \t\t\t\t Solution of Sudoku");
	printf("\n\n\t'Y' button \t\t\t\t Exit");
	printf("\n\n\n\n\n\t\t       Press 'B' to go back to main menu");
	e=getch();
	if(e==98)
	{
		main2();
	}
	//getch();
	//restorecrtmode();
	//closegraph();

}

void dt(int cn,int rn,int b)
{
	int i,j;
	struct rhd *x;
	struct chd *y;
	struct node *z;

	x=startr[n];
	y=startc[n];

	//printf("Enter the row number\t");
	//scanf("%d",&rn);
	//printf("Enter the column number\t");
	//scanf("%d",&cn);

	while(x->r!=rn)
		x=x->dwn;
	z=x->lnkr;

	while(y->c!=cn)
	{
		y=y->right;
		z=z->nxt;
	}
	//printf("Enter the value\t");
	//scanf("%d",&
	z->data=b;

}


void mn()
{
	struct rhd *p;
	int i;

	for(i=0;i<1;i++)
	{
		n=i;
		len[n].rl=8;
		len[n].cl=8;

		create_row();
		create_col();
		link();
		link_LL();

		/*p=startr[n];
		while(p!=NULL)
		{
			struct node *q;
			struct chd *t;
			t=startc[n];
			q=p->lnkr;
			while(q!=NULL)
			{
				printf("Row %d Column %d Data %d\n",p->r,t->c,q->data);
				q=q->nxt;
				t=t->right;
			}
			t=startc[n];
			p=p->dwn;
		}*/
	getch();
	}

}

void traverse()
{       struct node *q;
	struct chd *t;
	struct rhd *p;
	int x,y,d,n,i,j,r,a[9],b[9],cx[9],cy[9],g[9][9],w=40,l,m;
	int gm,gd=DETECT;
	char e;
	clrscr();
	initgraph(&gd,&gm,"F:\\TC\\BGI");
	settextstyle(5,0,4);
	setbkcolor(8);
	setcolor(15);
	settextstyle(4,0,4);
	outtextxy(250,420,"Puzzle no. 1");
	setcolor(7);
	a[0]=140;
	b[0]=38;
	cx[0]=20;
	cx[1]=25;
	cx[2]=30;
	cx[3]=35;
	cx[4]=40;
	cx[5]=45;
	cx[6]=50;
	cx[7]=55;
	cx[8]=60;
	cy[0]=4;
	cy[1]=7;
	cy[2]=9;
	cy[3]=12;
	cy[4]=14;
	cy[5]=17;
	cy[6]=19;
	cy[7]=22;
	cy[8]=24;



	for(j=0;j<10;j++)
	{
		for(i=0;i<9;i++)
		{
			rectangle(a[0],b[0],a[0]+(i+1)*w,b[0]+w);
			rectangle(a[0],b[0]+w,a[0]+(i+1)*w,b[0]+j*w);
		}
	}
	for(i=0;i<3;i++)
	{
		rectangle(a[0]-i,b[0]-i,a[0]+9*w+i,b[0]+9*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+3*w+i,b[0]+3*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+6*w+i,b[0]+3*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+9*w+i,b[0]+3*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+6*w+i,b[0]+6*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+3*w+i,b[0]+6*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+9*w+i,b[0]+6*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+3*w+i,b[0]+9*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+6*w+i,b[0]+9*w+i);
	}



	p=startr[n];
	l=0;
	while(p!=NULL)
	{       m=0;

		t=startc[n];
		q=p->lnkr;

		while(q!=NULL)
		{
			gotoxy(cx[m],cy[l]);
			printf(" %d ",q->data);
			q=q->nxt;
			t=t->right;
			m++;
		}
		t=startc[n];
		p=p->dwn;
		l++;
	}
	getch();
	restorecrtmode();
	closegraph();

}
void main2()
{
	char e,no;
	int i,x1,y1,x2,y2,n,ox[9],oy[9],r=0;
	int x,y,d,kab;
	int gm,gd=DETECT;

	initgraph(&gd,&gm,"F:\\TC\\BGI");
	settextstyle(4,0,7);
	setcolor(1);
	setbkcolor(8);
	outtextxy(170,10,"Main-Menu");
	settextstyle(8,0,3);
	setfillstyle(1,7);
//bar(200,130,400,160);
	bar(200,160,400,280);
	setcolor(8);
	//rectangle(200,160,400,190);
	rectangle(200,190,400,220);
	rectangle(200,220,400,250);
	rectangle(200,250,400,280);
//rectangle(200,130,400,160);
		oy[0]=160;
		oy[1]=160;
	oy[2]=190;
	oy[3]=220;
	oy[4]=250;
	oy[5]=280;

	setcolor(15);
	//outtextxy(210,135,"Menu:-");
	gotoxy(28,9);
	outtextxy(210,160," Start Puzzle\n");
	gotoxy(28,12);
	outtextxy(210,190," Introduction\n");
	gotoxy(28,15);
	outtextxy(210,220," Controls\n");
	gotoxy(28,18);
	outtextxy(210,250," Exit");

	setcolor(4);
//rectangle(200,oy[0],400,oy[1]);

//printf("%d",e);
	setcolor(1);
	do
	{
		e=getch();
	       /*	{
			if(e==0)
			{
				e=getch();
			}
		}*/

		if(e==115)
		{
			if((r<4))
			{
				//printf("%d",r);
				setcolor(7);
				rectangle(200,oy[r],400,oy[r+1]);
				setcolor(1);
				rectangle(200,oy[r+1],400,oy[r+2]);
				r++;
			}
		}
		if(e==119)
		{
			 if(r>1)
			{
				//printf("%d",r);
				setcolor(7);
				rectangle(200,oy[r],400,oy[r+1]);
				setcolor(1);
				rectangle(200,oy[r-1],400,oy[r-2]);
				r--;
			}
		}
		if(e==122)
		{
		       //	printf("%d",r);
			// break;
			if(r==1)
			{
				main1();
			}
			else if(r==2)
			{
				intro();
			}
			else if(r==3)
			{
				option();
			}
			else
			{
				exit(0);
				break;
			}

		}
	}while(e!=120);
	getch();
	restorecrtmode();
	closegraph();
}
void main1()
{
	int x,y,d,n,i,j,r,a[9],b[9],g[9][9],w=40;
	int gm,gd=DETECT;
	char e,m;
	clrscr();
	initgraph(&gd,&gm,"F:\\TC\\BGI");

	settextstyle(5,0,4);
	setbkcolor(8);
	setcolor(15);
	settextstyle(4,0,4);
	outtextxy(250,420,"Puzzle no. 1");
	setcolor(7);
	a[0]=140;
	b[0]=38;

	for(j=0;j<10;j++)
	{
		for(i=0;i<9;i++)
		{
			rectangle(a[0],b[0],a[0]+(i+1)*w,b[0]+w);
			rectangle(a[0],b[0]+w,a[0]+(i+1)*w,b[0]+j*w);
		}
	}
	for(i=0;i<3;i++)
	{
		rectangle(a[0]-i,b[0]-i,a[0]+9*w+i,b[0]+9*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+3*w+i,b[0]+3*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+6*w+i,b[0]+3*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+9*w+i,b[0]+3*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+6*w+i,b[0]+6*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+3*w+i,b[0]+6*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+9*w+i,b[0]+6*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+3*w+i,b[0]+9*w+i);
		rectangle(a[0]-i,b[0]-i,a[0]+6*w+i,b[0]+9*w+i);
	}

	movement(140,38);
	getch();
	restorecrtmode();
	closegraph();

}

int chk(int a[9][9],int l,int m,int b)
{
	int f=0,t=0,s=0,i,j;
	if(l<3)
	{
		if(m<3)
		{
			for(i=0;i<3;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}

			}
			for(i=0;i<3;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}

			}
		}
		else if((m>=3)&&(m<6))
		{
			for(i=3;i<6;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}
			}
			for(i=0;i<3;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}
			}
		}
		else
		{
			for(i=6;i<9;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}
			}
			for(i=0;i<3;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}
			}
		}
	}
	else if((l>=3)&&(l<6))
	{
		if(m<3)
		{
			for(i=0;i<3;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}
			}
			for(i=3;i<6;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}
			}
		}
		else if((m>=3)&&(m<6))
		{
			for(i=3;i<6;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}
			}
			for(i=3;i<6;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}
			}
		}
		else
		{
			for(i=6;i<9;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}
			}
			for(i=3;i<6;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}
			}
		}
	}
	else
	{
		if(m<3)
		{
			for(i=0;i<3;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}
			}
			for(i=6;i<9;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}
			}
		}
		else if((m>=3)&&(m<6))
		{
			for(i=3;i<6;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}
			}
			for(i=6;i<9;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}
			}
		}
		else
		{
			for(i=6;i<9;i++)
			{
				if(a[l][i]==b)
				{
					t=t+1;
				}
			}
			for(i=6;i<9;i++)
			{
				if(a[i][m]==b)
				{
					s=s+1;
				}
			}
		}

	}
	if((t==0)&&(s==0))
	{
		f=0;
	}
	else
	{
		f=1;
	}
	return(f);

}

void movement(int x1,int y1)
{
	char e,no;
	int i,j,x2,y2,n,cx[9],cy[9],l=0,m=0,c,d,t,s;
	mn();
	x2=x1+40;
	y2=y1+40;
	cx[0]=20;
	cx[1]=25;
	cx[2]=30;
	cx[3]=35;
	cx[4]=40;
	cx[5]=45;
	cx[6]=50;
	cx[7]=55;
	cx[8]=60;
	cy[0]=4;
	cy[1]=7;
	cy[2]=9;
	cy[3]=12;
	cy[4]=14;
	cy[5]=17;
	cy[6]=19;
	cy[7]=22;
	cy[8]=24;

	setcolor(14);
	rectangle(x1,y1,x2,y2);
	do
	{
		e=getch();
		if(e>90)
		{
			if(e==100)
			{
				if(x1<460)
				{
					setcolor(7);
					rectangle(x1,y1,x2,y2);
					setcolor(14);
					rectangle(x1+40,y1,x2+40,y2);
					x1=x1+40;
					x2=x2+40;
					l++;
				}
			}
			if(e==121)
			{
				exit(0);
			}
			if(e==115)
			{
				if(y1<330)
				{
					setcolor(7);
					rectangle(x1,y1,x2,y2);
					setcolor(14);
					rectangle(x1,y1+40,x2,y2+40);
					y1=y1+40;
					y2=y2+40;
					m++;
				}
			}
			if(e==119)
			{
				if(y1>70)
				{
					setcolor(7);
					rectangle(x1,y1,x2,y2);
					setcolor(14);
					rectangle(x1,y1-40,x2,y2-40);
					y1=y1-40;
					y2=y2-40;
					m--;
				}
			}
			if(e==97)
			{
				if(x1>140)
				{
					setcolor(7);
					rectangle(x1,y1,x2,y2);
					setcolor(14);
					rectangle(x1-40,y1,x2-40,y2);
					x1=x1-40;
					x2=x2-40;
					l--;
				}
			}

		}

		if((e<=57) && (e>=49))
		{

			gotoxy(cx[l],cy[m]);
			no=e;

			if(e==49)
			{
				c=0,d=0,s=0,t=0;

				for(i=0;i<9;i++)
				{
					if(a[l][i]==1)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==1)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0)&&(s==0))
				{
					a[l][m]=1;
					//t=chk(a,l,m,1);
					if(t==0)
					{
						dt(l,m,1);
						printf("%c",no);
					}
				}
			}
			else if(e==50)
			{
				c=0,d=0;
				for(i=0;i<9;i++)
				{
					if(a[l][i]==2)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==2)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0))
				{
					a[l][m]=2;
					dt(l,m,2);
					printf("%c",no);
				}
			}
			else if(e==51)
			{
				c=0,d=0;
				for(i=0;i<9;i++)
				{
					if(a[l][i]==3)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==3)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0))
				{
					a[l][m]=3;
					dt(l,m,3);
					printf("%c",no);
				}
			}
			else if(e==52)
			{
				c=0,d=0;
				for(i=0;i<9;i++)
				{
					if(a[l][i]==4)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==4)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0))
				{
					a[l][m]=4;
					dt(l,m,4);
					printf("%c",no);
				}
			}
			else if(e==53)
			{
				c=0,d=0;
				for(i=0;i<9;i++)
				{
					if(a[l][i]==5)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==5)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0))
				{
					a[l][m]=5;
					dt(l,m,5);
					printf("%c",no);
				}
			}
			else if(e==54)
			{
				c=0,d=0;
				for(i=0;i<9;i++)
				{
					if(a[l][i]==6)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==6)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0))
				{
					a[l][m]=6;
					dt(l,m,6);
					printf("%c",no);
				}
			}
			else if(e==55)
			{
				c=0,d=0;
				for(i=0;i<9;i++)
				{
					if(a[l][i]==7)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==7)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0))
				{
					a[l][m]=7;
					dt(l,m,7);
					printf("%c",no);
				}
			}
			else if(e==56)
			{
				c=0,d=0;
				for(i=0;i<9;i++)
				{
					if(a[l][i]==8)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==8)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0))
				{
					a[l][m]=8;
					dt(l,m,8);
					printf("%c",no);
				}
			}
			else
			{
				c=0,d=0;
				for(i=0;i<9;i++)
				{
					if(a[l][i]==9)
					{
						c=c+1;
					}
				}
				for(i=0;i<9;i++)
				{
					if(a[i][m]==9)
					{
						d=d+1;
					}
				}

				if((c==0)&&(d==0))
				{
					a[l][m]=9;
					dt(l,m,9);
					printf("%c",no);
				}
			}

		}
		if(e==120)
		{
			break;
		}
	}while(e!=120);
	//traverse();
	solve(a);
	traverse();
}

void solve(int a[9][9])
{       int xy;
    int skcp[9][9][9];
    int cp = 0,vlp = 0, vts = 0,x = 0, y = 0,val;
    int i,jb,l,n,m,kc;

    //Set all values in 3-D matrice to be one.
    for (i = 0; i <9; i++)
    {
	for (jb = 0; jb <9; jb++)
	{
	    for ( kc = 0; kc <9; kc++)
	    {
		skcp[i][jb][kc] = 1;
	    }
	}
    }
	//Solving the puzzle
    while (1)
    {
	for ( i = 0; i <9; i++)
	{
	    for ( jb = 0; jb <9; jb++)
	    {
		//If number already exist move to  nxt
		if (a[i][jb] != 0)
		{
		    continue;
		}
		//Checking possible values
		for ( kc = 0; kc <9; kc++)
		{

		    if (skcp[i][jb][kc] == 0)
		    {
			continue;
		    }
		    //eliminate horizontal overlaps
		    for ( l = 0; l <9; l++)
		    {
			if ((a[i][l] == (kc + 1)) && (l != jb))
			{
			    skcp[i][jb][kc] = 0;
			}
		    }
		    //eliminate vertical overlaps
		    for ( l = 0; l <9; l++)
		    {
			if ((a[l][jb] == (kc + 1)) && (l != i))
			{
			    skcp[i][jb][kc] = 0;
			}
		    }

		    //overlapping in the 3x3 matrice replace it with 0.
		    x = 0;
		    y = 0;
		    for ( m = 0; m <= 6; m += 3)
		    {
			for ( n = 0; n <= 2; n++)
			{
			    if ((m + n) == i)
			    {
				x = m;
			    }
			}
		    }
		    for ( m = 0; m <= 6; m += 3)
		    {
			for ( n = 0; n <= 2; n++)
			{
			    if ((m + n) == jb)
			    {
				y = m;
			    }
			}
		    }
		    for ( m = 0; m <= 2; m++)
		    {
			    for ( n = 0; n <= 2; n++)
			    {
				if ((a[x+m][y+n] == (kc + 1)) && ((x+m) != i) && ((y+n) != jb))
				{
					skcp[i][jb][kc] = 0;
				}
			    }
		    }
		}
		//Counting of values for each 3x3

		vlp = 0;
		vts = 0;
		for ( l = 0; l <9; l++)
		{
		    if (skcp[i][jb][l] == 1)
		    {
			vlp++;
			vts = l + 1;
		    }
		}
		if (vlp == 1)
		{
		    a[i][jb] = vts;
		}
	    }
	}
	//Counting unsolved squares to get wether the sudoku is solved or not
	cp = 0;
	for (i= 0; i<9; i++)
	{
	    for ( jb = 0; jb < 9; jb++)
	    {
		if (a[i][jb] == 0)
		{
		    cp++;
		}
	    }
	}
	if (cp == 0)
	{
	    break;
	}
	else
	{
	    continue;
	}
    }

    for(i=0;i<9;i++)
    {
	for(jb=0;jb<9;jb++)
	{       //printf("%d \t",a[i][jb]);
		val=a[i][jb];
		dt(i,jb,val);
	}
       //	printf("/n");
    }
}

void ty()
{
	int x,y,d,n;
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"F:\\TC\\BGI");
	settextstyle(4,0,7);
	setcolor(1);
	setbkcolor(9);
	outtextxy(150,130,"Thank you !!");
	settextstyle(8,0,1);
	setcolor(6);
	outtextxy(400,330,"by:-");
	outtextxy(430,360,"Harsh Bhatia");
	outtextxy(430,390,"Tanmay Sinha");
	getch();
	restorecrtmode();
	closegraph();
}

void main()
{
	title();
	cleardevice();
	main2();
	cleardevice();
	ty();
}