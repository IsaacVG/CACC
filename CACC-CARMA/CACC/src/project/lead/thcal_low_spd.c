#define	S_FUNCTION_NAME		thcal	/*Ｓファンクション名の定義*/
#define	S_FUNCTION_LEVEL	2		/*ファンクションレベル??２*/


#include "simstruc.h"
#include "math.h"
//#include "size.h"

double	vt_in;
double	vt_buf;
double	vt_out;

double	vxg_in;
double sp_ini;


int first=0;
int counter=0;
double aux1 =0;
double aux2 =0;


static	void	mdlInitializeSizes( SimStruct *S )	/*サイズ?炎�化関?�*/
{
	long	board_base;								/*ボ?[ドアドレス用変?�*/

	ssSetNumSFcnParams( S, 0 );						/*パラ�??[タ引?狽ﾌ?ﾝ定	*/
	ssSetNumContStates( S, 0 );						/**/
	ssSetNumDiscStates( S, 0 );						/**/
	ssSetNumInputPorts( S, 1 );						/*入力?狽ﾌ?ﾝ定	*/
	ssSetInputPortWidth( S, 0,  2 );				//３つ目の引?狽ｪMatlabのMuxを通じて入力される変?�
													/*２番目の入力デ?[タの�?を３要素にの?ﾝ定*/
	ssSetInputPortDirectFeedThrough( S, 0, 1 );		/*ダイレクトフィ?[ルドスル?[の?ﾝ定*/
	ssSetNumOutputPorts( S, 1 );					/*?o力?狽ﾌ?ﾝ定*/
	ssSetOutputPortWidth( S, 0, 1  );				//３つ目の引?狽ｪMatlab?繧ﾅ?o力される変?狽ﾌ?�
													/*０番目の?o力デ?[タの�?の?ﾝ定*/
	ssSetNumSampleTimes( S, 1 );					/*サンプルタイム?狽ﾌ?ﾝ定*/
	ssSetNumRWork( S, 0 );				/**/
	ssSetNumIWork( S, 0 );				/**/
	ssSetNumPWork( S, 0 );				/**/
	ssSetNumModes( S, 0 );				/**/
	ssSetNumNonsampledZCs( S, 0 );		/**/
	ssSetOptions(S,	0);					/**/

}

static	void	mdlInitializeSampleTimes( SimStruct *S )/*サンプルタイム?炎�化関?�*/
{
	ssSetSampleTime( S, 0, INHERITED_SAMPLE_TIME );						/*サンプルタイムの?ﾝ定?i１００�?ｓ毎に実?sする?j*/
	ssSetOffsetTime( S, 0, 0.0 );						/*オフセットタイムの?ﾝ定*/
}






#define	MDL_INITIALIZE_CONDITIONS				/*定義?Fもし定義していなかったら?iundef?j下記を無効*/
#if	defined( MDL_INITIALIZE_CONDITIONS )		/*もしも?A定義してあったら有効にする*/
static	void	mdlInitializeConditions( SimStruct *S )	
{				/*?炎�?ﾝ定関?�?Fサンプリング周期が開始される前の?炎�?ﾝ定*/

}
#endif							/*もしも?A定義してあったら有効にする	*/

#define	MDL_START								/*定義?Fもし定義していなかったら?iundef?j下記を無効*/
#if	defined( MDL_START )						/*もしも?A定義してあったら有効にする*/
	static	void	mdlStart( SimStruct *S )	/*開始時関?�*/
	{											/*?炎�?ﾝ定関?�?Fサンプリング周期が開始される前の?炎�?ﾝ定*/

	}
#endif							/*もしも?A定義してあったら有効にする*/

static	void	mdlOutputs( SimStruct *S, int_T tid )	/*?o力関?�*/
{
	InputRealPtrsType	uPtrs =	ssGetInputPortRealSignalPtrs( S, 0 );
	real_T			*y = ssGetOutputPortRealSignal( S, 0 );	
	

	vt_in = *uPtrs[0];
	vxg_in = *uPtrs[1];
    
 if (vxg_in == 1)
 {   
    if (first == 0)
    {
        sp_ini = 4.0; // vt_in;   
        first = 1;
    }
    
    if (counter < 3001)
    {
        vt_out = sp_ini; 
        counter = counter + 1;
    }    
    if (counter > 3000 && counter < 3501)
    {
        vt_out = sp_ini-1*(aux1/500.0); 
        counter = counter + 1;
        aux1=aux1+1;
    }     
    
    if (counter > 3500 && counter < 4501)
    {
        vt_out = sp_ini-1; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 4500 && counter < 5001)
    {
        vt_out = sp_ini-1+3*(aux2/500.0); 
        counter = counter + 1;
        aux2=aux2+1;
    }   
    
    if (counter > 5000 && counter < 6001)
    {
        vt_out = sp_ini+2; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 6000 && counter < 6501)
    {
        vt_out = sp_ini+2-4*(aux1/500.0); 
        counter = counter + 1;
        aux1=aux1+1;
    }     
    
    if (counter > 6500 && counter < 8501)
    {
        vt_out = sp_ini-2; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 8500 && counter < 9001)
    {
        vt_out = sp_ini-2+2*(aux2/500.0); 
        counter = counter + 1;
        aux2=aux2+1;
    }   
    
    if (counter > 9000 && counter < 10001)
    {
        vt_out = sp_ini; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    } 
    
    if (counter > 10000 && counter < 10501)
    {
        vt_out = sp_ini+1*(aux1/500.0); 
        counter = counter + 1;
        aux1=aux1+1;
    }     
    
    if (counter > 10500 && counter < 11501)
    {
        vt_out = sp_ini+1; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 11500 && counter < 12001)
    {
        vt_out = sp_ini+1-2*(aux2/500.0); 
        counter = counter + 1;
        aux2=aux2+1;
    }   
       
    if (counter > 12000 && counter < 13001)
    {
        vt_out = sp_ini-1; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    } 
    
    if (counter > 13000 && counter < 13501)
    {
        vt_out = sp_ini-1-1.5*(aux1/500.0); 
        counter = counter + 1;
        aux1=aux1+1;
    }     
    
    
    if (counter > 13500 && counter < 14501)
    {
        vt_out = sp_ini-2.5; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 14500 && counter < 15001)
    {
        vt_out = sp_ini-2.5-1.5*(aux2/500.0); 
        counter = counter + 1;
        aux2=aux2+1;
    }   
    
    if (counter > 15000)
    {
        vt_out = sp_ini-4; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
 }
 if (vxg_in == 0)
 {   
     counter = 0;
     aux1 = 0;
     aux2 = 0;
 }
     
    
    

	y[0] = vt_out;
	


}

#undef	MDL_UPDATE						/*定義*/
#if	defined( MDL_UPDATE )					/*もしも?A定義してあったら有効にする*/
	static	void	mdlUpdate( SimStruct *S, int_T tid )	/*?X?V関?�*/
	{
	}
#endif								/*もしも?A定義してあったら有効にする*/



#undef	MDL_DERIVATIVES						/**/
#if	defined( MDL_DERIVATIVES )				/*もしも?A定義してあったら有効にする*/
	static	void	mdlDerivatives( SimStruct *S )		/*微分用関?�*/
	{
	}
#endif								/*もしも?A定義してあったら有効にする*/



static	void	mdlTerminate( SimStruct *S )			/*?I端関?�*/
{
}

#ifdef	MATLAB_MEX_FILE						/*ＳＩＭＵＬＩＮＫを使用する?�?�は?A	*/
	#include	"simulink.c"				/*インクル?[ドする			*/
#else								/*Ａｕｔ�?ｂ�?ｘを使用する?�?�は?A	*/
	#include	"cg_sfun.h"				/*インクル?[ドする			*/
#endif
