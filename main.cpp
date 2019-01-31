#include"Dxlib.h"
#include<math.h>
//軸
int px=50;
int py=200;
int ex=590;
int ey=200;
int f1=0;
int f2=0;
int a1=0;
int m1=0;
int m2=0;
int am1=0;
int as1=0;
int af=0;
int mz=0;
int lev=0;
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,LPSTR lpcmdLine, int nCmdshow)
{
	if( DxLib_Init() == -1 )return -1; // DXライブラリ初期化処理	
	SetGraphMode(640,360,16);; //全体画面の大きさ
	SetDrawScreen(DX_SCREEN_BACK);//裏画面に描画
	unsigned int Color ; //カウンターまたは画像カウンター表示(検証)
	int Color1 = GetColor( 255,0 ,0 ) ; //赤
	int Color2 = GetColor( 255 , 255 , 255 ) ;//白
	int Color3 = GetColor( 0 , 0 , 255 ) ;// 青
	int Color4 = GetColor(255,255,0); //黄色

	while(1){
		ClearDrawScreen(); //描画した画を消す
		//ex--;		
		//if(ex+20==0)ex=660;
		
		if(af==0&&CheckHitKey(KEY_INPUT_SPACE)==1){
			if(CheckHitKey(KEY_INPUT_F)==1){
				af=1;
				a1=1;
				f1=0;
			}else{
				a1=0;
				f1=1;
			}
		}else f1=0;

		if(mz==0&&CheckHitKey(KEY_INPUT_F)==1)a1=1;
		
		


		
		if(f1==1)px+=2;
		if(f2==1)px-=2;
		if(f1==1)m1++;
		if(f2==2)m2++;
		if(a1==1)am1++;	
		DrawBox(0,0,320,20,Color1,true);
		DrawBox(0,300,640,360,Color2,true);
		DrawBox(px-50,py,px+50,py+100,Color3,false);
		DrawBox(ex-20,ey,ex+20,ey+100,Color1,false);
		if(a1==1){
			DrawBox(px,py,px+50,py+100,Color1,true);			
		}
		ScreenFlip();
		if(ProcessMessage()<0)break;
		if(CheckHitKey(KEY_INPUT_ESCAPE))break;
	}

	DxLib_End();
	return 0;
}
