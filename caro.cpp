#include <iostream>
#include <windows.h>
#include <conio.h>
//x: Ngang; y:  doc
using namespace std;
char a[79][24], key;
short x,y,i,m,n,m1,n1, LuaChon; //m1,n1: phuc vu cho viec kiem tra Dieu Kien chien thang
void GanDL(){
    for (int i=1; i<=79; i++)
        for (int j=1; j<=24; j++)
            a[i][j]=' ';
}
void MoDau(short);
void Play();
void Exit();
void HuongDan(short);
void VeKhung(short);
void ChoiLai();

void Goto(int x, int y){
    COORD co = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , co);
}

void TextColor(int x)//Xac dinh mau cua chu
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , x);
}

short CHIALUOT(short i){// CHIA LUOT
    if (i%2==0) return 1;
    else return 0;
}

char OX(short i){
    if (CHIALUOT(i)==1) return 'O';
    else return 'X';
}

void VeOX(short x, short y){//Ve O, X theo luot
    if (a[x][y] != 'X' && a[x][y] != 'O'){
         if (CHIALUOT(i)==1) TextColor(11); else TextColor(12);
         a[x][y]=OX(i);
         cout<<a[x][y];
         i++;
    }
    else a[n][m];
    TextColor(7);
}

void SangTrai(){
    x-=1;
    if (x<13) x=13;
}

void SangPhai(){
    x+=1;
    if (x>=77) x=77;
}

void LenTren(){
    y-=1;
    if (y<3) y=3;
}

void XuongDuoi(){
    y+=1;
    if (y>=23) y=23;
}

void ConTro(short x, short y){  //Phuc vu cho di chuyen
    Goto(x,y);
    n=x;m=y;
}

void ThongTinTranDau(){
    TextColor(7);
    Goto(0,0); cout<<"Q : Thoat tran dau."<<endl<<"Luot thu: "<<i;
    cout<<"     M, E: choi.";
    TextColor(12); 
    Goto(0,4); TextColor(11);cout<<"Nguoi Choi 1"<<endl<<"A,D,W,S"<<endl<<endl;
               cout<<"Nguoi choi 2"<<endl<<"Phim di "<<endl<<"chuyen"<<endl<<endl;
    TextColor(14); cout<<"p/s:"<<endl<<"Chan dau,"<<endl<<"chan duoi "<<endl; TextColor(12); cout<<"khong";TextColor(14); cout<<" tinh"<<endl<<endl;
    TextColor(9); cout<<"B: Back"<<endl<<"R: Choi lai"<<endl;
    TextColor(10); cout<<endl<<"Luot: "<<OX(i);
    TextColor(7);
}

short DKOChienThang(){//Dieu kien de ben O chien thang
    //Theo hang ngang
    m1=m; n1=n;
    while (a[n1][m]=='O')
       n1++;
       n1--;
     
         if ((a[n1][m]=='O') && (a[n1+1][m]=='O') && (a[n1+2][m]=='O') && (a[n1+3][m]=='O') && (a[n1+4][m]=='O') && ((a[n1+5][m] != 'X') || (a[n1-1][m] != 'X')) ) return 1; 
	     else if ((a[n1][m]=='O') && (a[n1-1][m]=='O') && (a[n1-2][m]=='O') && (a[n1-3][m]=='O') && (a[n1-4][m]=='O') && ((a[n1-5][m] != 'X') || (a[n1+1][m] != 'X')) ) return 1;
    //Theo hang doc
    m1=m; n1=n;
    while (a[n][m1]=='O')
        m1++;
        m1--;
    if ((a[n][m1]=='O') && (a[n][m1+1]=='O') && (a[n][m1+2]=='O') && (a[n][m1+3]=='O') && (a[n][m1+4]=='O') && ((a[n][m1+5] != 'X') || (a[n][m1-1] != 'X')) ) return 1; 
	else if ((a[n][m1]=='O') && (a[n][m1-1]=='O') && (a[n][m1-2]=='O') && (a[n][m1-3]=='O') && (a[n][m1-4]=='O') && ((a[n][m1-5] != 'X') || (a[n][m1+1] != 'X')) ) return 1;
    
     //Theo duong cheo chinh
    m1=m; n1=n;
    while (a[n1][m1]=='O'){
        m1++; n1++;
    }
    m1--; n1--;
    if ((a[n1][m1]=='O') && (a[n1+1][m1+1]=='O') && (a[n1+2][m1+2]=='O') && (a[n1+3][m1+3]=='O') && (a[n1+4][m1+4]=='O') && ((a[n1+5][m1+5] != 'X') || (a[n1-1][m1-1] != 'X')) ) return 1; 
	else if ((a[n1][m1]=='O') && (a[n1-1][m1-1]=='O') && (a[n1-2][m1-2]=='O') && (a[n1-3][m1-3]=='O') && (a[n1-4][m1-4]=='O') && ((a[n1-5][m1-5] != 'X') || (a[n1+1][m1+1] != 'X')) ) return 1;
    //Theo duong cheo phu
	m1=m; n1=n;
    while (a[n1][m1]=='O'){
        n1++; m1--;
    }
    n1--; m1++;
    if ((a[n1][m1])=='O' && (a[n1+1][m1-1])=='O' && (a[n1+2][m1-2])=='O' && (a[n1+3][m1-3])=='O' && (a[n1+4][m1-4]=='O' ) && ((a[n1+5][m1-5] != 'X') || (a[n1-1][m1+1] != 'X')) ) return 1; 
	else if ((a[n1][m1])=='O' && (a[n1-1][m1+1])=='O' && (a[n1-2][m1+2])=='O' && (a[n1-3][m1+3])=='O' && (a[n1-4][m1+4]=='O' ) && ((a[n1-5][m1+5] != 'X') || (a[n1+1][m1-1] != 'X')) ) return 1;

    return 0;
}

short DKXChienThang(){ //Dieu kien de ben X chien thang
    //THeo hang ngang
    m1=m; n1=n;
    while (a[n1][m]=='X') {
        n1++;
    }
    n1--;
    if ((a[n1][m]=='X') && (a[n1+1][m]=='X') && (a[n1+2][m]=='X') && (a[n1+3][m]=='X') && (a[n1+4][m]=='X') && ((a[n1+5][m] != 'O') || (a[n1-1][m] != 'O')) ) return 1; else //Theo Hang ngang
    if ((a[n1][m]=='X') && (a[n1-1][m]=='X') && (a[n1-2][m]=='X') && (a[n1-3][m]=='X') && (a[n1-4][m]=='X') && ((a[n1-5][m] != 'O') || (a[n1+1][m] != 'O')) ) return 1;
    //Theo hang doc
    m1=m; n1=n;
    while (a[n][m1]=='X') {
        m1++;
    }
    m1--;
    if ((a[n][m1]=='X') && (a[n][m1+1]=='X') && (a[n][m1+2]=='X') && (a[n][m1+3]=='X') && (a[n][m1+4]=='X') && ((a[n][m1+5] != 'O') || (a[n][m1-1] != 'O')) ) return 1; else //Theo Hang doc
    if ((a[n][m1]=='X') && (a[n][m1-1]=='X') && (a[n][m1-2]=='X') && (a[n][m1-3]=='X') && (a[n][m1-4]=='X') && ((a[n][m1-5] != 'O') || (a[n][m1+1] != 'O')) ) return 1;
    //Theo duong cheo chinh
    m1=m; n1=n;
    while (a[n1][m1]=='X'){
        m1++; n1++;
    }
    m1--; n1--;
    if ((a[n1][m1]=='X') && (a[n1+1][m1+1]=='X') && (a[n1+2][m1+2]=='X') && (a[n1+3][m1+3]=='X') && (a[n1+4][m1+4]=='X') && ((a[n1+5][m1+5] != 'O') || (a[n1-1][m1-1] != 'O')) ) return 1; else //Theo Duong cheo chinh
    if ((a[n1][m1]=='X') && (a[n1-1][m1-1]=='X') && (a[n1-2][m1-2]=='X') && (a[n1-3][m1-3]=='X') && (a[n1-4][m1-4]=='X') && ((a[n1-5][m1-5] != 'O') || (a[n1+1][m1+1] != 'O')) ) return 1;
    //Theo duong cheo phu
    m1=m; n1=n;
    while (a[n1][m1]=='X'){
        n1++; m1--;
    }
    n1--; m1++;
    if ((a[n1][m1])=='X' && (a[n1+1][m1-1])=='X' && (a[n1+2][m1-2])=='X' && (a[n1+3][m1-3])=='X' && (a[n1+4][m1-4]=='X' ) && ((a[n1+5][m1-5] != 'O') || (a[n1+1][m1+1] != 'O')) ) return 1; else //Theo Duong cheo phu
    if ((a[n1][m1])=='X' && (a[n1-1][m1+1])=='X' && (a[n1-2][m1+2])=='X' && (a[n1-3][m1+3])=='X' && (a[n1-4][m1+4]=='X' ) && ((a[n1-5][m1+5] != 'O') || (a[n1-1][m1-1] != 'O')) ) return 1;
    //Khong chien thang
    return 0;
}
// Ai do chien thang
void ChienThang(){
    TextColor(12);
    if ((DKOChienThang()==1)){
        Goto(27,3); TextColor(11); cout<<"O chien thang. An R de choi lai. Q de thoat";
        key=getch();
        if (key=='r' || key=='R') ChoiLai();
        else if (key=='q' || key=='Q') Exit(); 
	
	else MoDau(50);
    }
    else
        if ((DKXChienThang()==1)){
            Goto(27,3);  TextColor(12); cout<<"X Chien Thang. An R de choi lai. Q de thoat";
            key=getch();
        if (key=='r' || key=='R') ChoiLai();
        else
            if (key=='q' || key=='Q') Exit(); else MoDau(50);
        }
    TextColor(7);
}

void ChoiLai(){ //Khoi phuc nguyen hien trang
    GanDL();
    i=0; x=13; y=3;
    system("cls");
    ThongTinTranDau();
    VeKhung(0);
}

void TuongTacPhim(){
    key=getch();
    if (key=='a' || key=='A' || int (key==75)) SangTrai(); else
    if (key=='d' || key=='D' || int (key==77)) SangPhai(); else
    if (key=='w' || key=='W' || int (key==72)) LenTren(); else
    if (key=='s' || key=='S' || int (key==80)) XuongDuoi(); else
    if (key=='e' || key=='E' || key=='m' || key=='M') VeOX(n,m); else
    if (key=='r' || key=='R') ChoiLai();
    if (key=='b' || key=='B') MoDau(50);
}

main(){
    GanDL();
    MoDau(100);
}

void MoDau(short n){
    system("cls");
    TextColor(12);
    
   Goto(31,6);cout<< "  ___     __    ____    _____ ";
   Goto(31,7);cout<< " / __)   /__\\  (  _ \\  (  _  )";
   Goto(31,8);cout<< "( (__   /(__)\\  )   /   )(_)( ";
   Goto(31,9);cout<< " \\___) (__)(__)(_)\\_)  (_____) " ;
   TextColor(14);
	Goto(31,12) ;  cout<<"1. Choi 2 nguoi voi nhau."<<endl;
   TextColor(11); 
	Sleep(n); Goto(31,13);cout<<"2. Huong Dan."<<endl;
    TextColor(10); 
	TextColor(13); 
	 Sleep(n); Goto(31,14);cout<<"3. Thoat"<<endl;
    TextColor(12);
	Sleep(n); Goto(31,15);cout<<"Menu: ";
    LuaChon=getch();
    cout<<char (LuaChon);
    Sleep(500);
    if (LuaChon== '1') Play(); else
    if (LuaChon== '2') HuongDan(1); else
    if (LuaChon== '3') Exit (); else MoDau(0);
    TextColor(7);

}

void VeKhung(short n){
    short i;
    TextColor(5);
    Goto(12,2);
    for (i=0; i<=66; i++){
        cout<<"@"; Sleep(n);
    }
    for (i=1; i<=22; i++) {
        Goto(12,i+2);
        Sleep(n);
        cout<<"@";
    }
    Goto(12,24);
    for (i=0; i<=65; i++) {
        cout<<"@"; Sleep(n);
    }

    for (i=1; i<=22; i++) {
        Goto(78,i+2);
        Sleep(n);
        cout<<"@";
    }
}

void BatDau(){
    system("cls");
    HuongDan(2);
    system("cls");
    VeKhung(5);
}

void Play(){
    BatDau();
    x=n=13; y=m=3;
    i=0;
    do{
        ThongTinTranDau();
        ConTro(x,y);
        ChienThang();
        TuongTacPhim();
    } while (key != 'q' && key != 'Q');
    Exit();
}





void HuongDan(short k){
    cout<<endl<<endl<<"                                         HUONG DAN"<<endl<<endl;
    cout<<"Dung";
    TextColor(12); cout<<" phim mui ten";
    TextColor(7);  cout<<" hoac";
    TextColor(12); cout<<" A,D,W,S";
    TextColor(7);  cout<<" de di chuyen. Dung phim";
    TextColor(12); cout<<" E";
    TextColor(7);  cout<<" va";
    TextColor(12); cout<<" M";
    TextColor(7);  cout<<" de choi."<<endl<<"Chuc vui!"<<endl;;
    system("pause");
    if (k==1) MoDau(0);
}



void Exit(){
    TextColor(10);
    system("cls");
    Goto(31,11); cout<<"Tam Biet! Hen Gap lai!";
    TextColor(7);
    getch();
    ExitProcess(0);
}

